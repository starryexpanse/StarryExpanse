//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#include "StrangerController.h"
#include "Interfaces/RivenInteractable.h"
#include "Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RivenGameState.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Engine/Engine.h"
#include "RivenGameInstance.h"
#include "StarryExpanse.h"

AStrangerController::AStrangerController() {
  MenuStateChanged.BindUFunction(this, "Cbk_MenuStateChanged");
}

void AStrangerController::BeginPlay() {
  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  this->ReactToMenuState(gs->CurrentMenuPage, gs->MenuWidget);
  gs->MenuStateChangedEvent.Add(MenuStateChanged);

  auto gameInstance = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
  gameInstance->GameInstanceVarsChanged.AddDynamic(
    this, &AStrangerController::PossiblyFreezeOrUnfreeze);
  this->EnterCursorMode(true);
}

void AStrangerController::Cbk_MenuStateChanged() {
  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  this->ReactToMenuState(gs->CurrentMenuPage, gs->MenuWidget);
}

void AStrangerController::ReactToMenuState(EGameMenuPage menuPage, UUserWidget* widgetNonShared) {
  if (menuPage != EGameMenuPage::NoPage) {
    FInputModeUIOnly mode;

    auto widget = widgetNonShared->TakeWidget();

    mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    mode.SetWidgetToFocus(widget);
    this->SetInputMode(mode);
  }
}

void AStrangerController::PostInitializeComponents() {
  Super::PostInitializeComponents();
}

void AStrangerController::SetupInputComponent() {
  Super::SetupInputComponent();

  InputComponent->BindAction("Interact", EInputEvent::IE_Pressed, this,
                             &AStrangerController::Interact);

  InputComponent->BindAction("Toggle Cursor Mode", EInputEvent::IE_Pressed,
                             this,
                             &AStrangerController::RequestSwitchCursorMode);

  InputComponent->BindAxis("CursorMoveX", this,
                           &AStrangerController::AddHorizontalMouseScan);

  InputComponent->BindAxis("CursorMoveY", this,
                           &AStrangerController::AddVerticalMouseScan);

  InputComponent->BindAxis("Turn", this,
                           &AStrangerController::AddHorizontalMousePan);

  InputComponent->BindAxis("LookUp", this,
                           &AStrangerController::AddVerticalMousePan);
}

void AStrangerController::AddHorizontalMousePan(float amount) {
  if (IsCursorLockedToCenter) {
    this->AddYawInput(amount);
  }
}

void AStrangerController::AddVerticalMousePan(float amount) {
  if (IsCursorLockedToCenter) {
    this->AddPitchInput(amount);
  }
}

void AStrangerController::AddHorizontalMouseScan(float amount) {
  if (!IsCursorLockedToCenter) {
    HorizontalMousePosition = FMath::Clamp(
      HorizontalMousePosition + amount, 0.0f, 1.0f);
  }
}

void AStrangerController::AddVerticalMouseScan(float amount) {
  if (!IsCursorLockedToCenter) {
    VerticalMousePosition = FMath::Clamp(
      VerticalMousePosition + amount, 0.0f, 1.0f);
  }
}

void AStrangerController::EnterCursorMode(bool fixed) {
  if (fixed) {
    this->IsCursorLockedToCenter = true;
    this->IgnoreLookInput = 0;
    HorizontalMousePosition = 0.5;
    VerticalMousePosition = 0.5;
  } else {
    this->IsCursorLockedToCenter = false;
    this->IgnoreLookInput = 1;
  }
}

void AStrangerController::RequestSwitchCursorMode() {
  this->EnterCursorMode(!this->IsCursorLockedToCenter);
}

void AStrangerController::Interact() {
  bool gotHit;

  FVector ViewLocation;
  FRotator ViewRotation;

  this->GetPlayerViewPoint(ViewLocation, ViewRotation);
  auto viewTarget = this->GetViewTarget();
  if (!viewTarget)
    return;

  auto Cameras = viewTarget->GetComponentsByTag(UCameraComponent::StaticClass(),
                                                FName("MainCamera"));

  if (!Cameras.IsValidIndex(0))
    return;

  auto Camera = Cast<UCameraComponent>(Cameras[0]);
  if (!Camera)
    return;

  auto hitResult = this->CastInteractionRay(gotHit, ViewLocation,
                                            Camera->GetForwardVector());

  if (gotHit) {
    auto hitActor = hitResult.GetActor();
    if (hitActor != nullptr &&
        hitActor->GetClass()->ImplementsInterface(
            URivenInteractable::StaticClass())) {
      IRivenInteractable::Execute_Touched(hitActor);
    }
  }
}

FHitResult AStrangerController::CastInteractionRay(bool &gotHit,
                                                   FVector worldLocation,
                                                   FVector worldDirection) {

  gotHit = false;

  struct FHitResult HitResult;

  auto viewTarget = this->GetViewTarget();
  if (!viewTarget)
    return HitResult;

  auto Cameras = viewTarget->GetComponentsByTag(UCameraComponent::StaticClass(),
                                                FName("MainCamera"));
  if (!Cameras.IsValidIndex(0))
    return HitResult;

  auto Camera = Cast<UCameraComponent>(Cameras[0]);
  if (!Camera)
    return HitResult;

  FCollisionQueryParams Params = FCollisionQueryParams::DefaultQueryParam;
  FCollisionResponseParams ResponseParams =
      FCollisionResponseParams::DefaultResponseParam;

  const float kRange = 500.0f;

  gotHit = GetWorld()->LineTraceSingleByChannel(
      HitResult, worldLocation, worldLocation + worldDirection * kRange,
      ECollisionChannel::ECC_Visibility, Params, ResponseParams);

  return HitResult;
}

void AStrangerController::PossiblyFreezeOrUnfreeze() {
  auto gameInstance = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
  this->SetIgnoreLookInput(gameInstance->bIsFrozenForLoading);
  this->SetIgnoreMoveInput(gameInstance->bIsFrozenForLoading);
}

void AStrangerController::Destroyed() {
  auto gameInstance = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
  gameInstance->GameInstanceVarsChanged.RemoveDynamic(
      this, &AStrangerController::PossiblyFreezeOrUnfreeze);

  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  gs->MenuStateChangedEvent.Remove(MenuStateChanged);
}

/*
  Overriding UE4 defaults.
*/

void AStrangerController::SetIgnoreLookInput(bool bNewLookInput) {
  this->IgnoreLookInput = (int)bNewLookInput;
}

void AStrangerController::SetIgnoreMoveInput(bool bNewMoveInput) {
  this->IgnoreMoveInput = (int)bNewMoveInput;
}

/*
  Above two:
  Long story short, their implementation does something we should
  do a little more explicitly, so resetting this to a very simple behavior and
  we can re-build
  what they do, later on.
*/