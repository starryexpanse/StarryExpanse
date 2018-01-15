//
// Copyright 2018 59 Volt Entertainment, all rights reserved.
//

#include "StrangerController.h"
#include "Actors/RivenInteractable.h"
#include "Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "RivenGameInstance.h"

AStrangerController::AStrangerController() {}

void AStrangerController::PostInitializeComponents() {
  Super::PostInitializeComponents();

  InputMouseHorizScale = 1;
  InputMouseVertScale = 1;
}

void AStrangerController::SetupInputComponent() {
  Super::SetupInputComponent();

  InputComponent->BindAction(
    "Interact",
    EInputEvent::IE_Pressed,
    this,
    &AStrangerController::Interact
  );

  InputComponent->BindAction(
    "Toggle Cursor Mode",
    EInputEvent::IE_Pressed,
    this,
    &AStrangerController::RequestSwitchCursorMode
  );

  InputComponent->BindAxis(
    "Spectator_Turn",
    this,
    &AStrangerController::AddHorizontalMouse
  );

  InputComponent->BindAxis(
    "Spectator_LookUp",
    this,
    &AStrangerController::AddVerticalMouse
  );
}

void AStrangerController::AddHorizontalMouse(float amount) {
  HorizontalMousePosition = FMath::Clamp(HorizontalMousePosition + amount * InputMouseHorizScale, 0.0f, 1.0f);
}

void AStrangerController::AddVerticalMouse(float amount) {
  VerticalMousePosition = FMath::Clamp(VerticalMousePosition + amount * InputMouseVertScale, 0.0f, 1.0f);
}

void AStrangerController::BeginPlay() {
  auto gameInstance = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
  gameInstance->GameInstanceVarsChanged.AddDynamic(
      this,
      &AStrangerController::PossiblyFreezeOrUnfreeze
  );
}

void AStrangerController::RequestSwitchCursorMode() {
  if (this->IsCursorLockedToCenter) {
    this->IsCursorLockedToCenter = false;
    this->SetIgnoreLookInput(false);
  }
  else {
    this->IsCursorLockedToCenter = true;
    this->SetIgnoreLookInput(true);
  }
}

void AStrangerController::Interact() {
  bool gotHit;

  FVector ViewLocation;
  FRotator ViewRotation;

  this->GetPlayerViewPoint(
    ViewLocation,
    ViewRotation
  );
  auto viewTarget = this->GetViewTarget();
  if (!viewTarget)
    return;

  auto Cameras = viewTarget->GetComponentsByTag(
    UCameraComponent::StaticClass(),
    FName("MainCamera")
  );

  if (!Cameras.IsValidIndex(0))
    return;

  auto Camera = Cast<UCameraComponent>(Cameras[0]);
  if (!Camera)
    return;

  auto hitResult = this->CastInteractionRay(gotHit, ViewLocation, Camera->GetForwardVector());

  if (gotHit) {
    auto hitActor = hitResult.GetActor();
    if (
      hitActor != nullptr &&
      hitActor->GetClass()->ImplementsInterface(URivenInteractable::StaticClass())
    ) {
      IRivenInteractable::Execute_Touched(hitActor);
    }
  }
}

FHitResult AStrangerController::CastInteractionRay(
  bool &gotHit,
  FVector worldLocation,
  FVector worldDirection) {

  gotHit = false;
    
  struct FHitResult HitResult;
    
  auto viewTarget = this->GetViewTarget();
  if (!viewTarget)
    return HitResult;
    
  auto Cameras = viewTarget->GetComponentsByTag(
    UCameraComponent::StaticClass(),
    FName("MainCamera")
  );
  if (!Cameras.IsValidIndex(0))
    return HitResult;

  auto Camera = Cast<UCameraComponent>(Cameras[0]);
  if (!Camera)
    return HitResult;

  FCollisionQueryParams Params = FCollisionQueryParams::DefaultQueryParam;
  FCollisionResponseParams ResponseParams = FCollisionResponseParams::DefaultResponseParam;

  const float kRange = 500.0f;

  gotHit = GetWorld()->LineTraceSingleByChannel(
    HitResult,
    worldLocation,
    worldLocation + worldDirection * kRange,
    ECollisionChannel::ECC_Visibility,
    Params,
    ResponseParams
  );
  
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
}


/* 
  Overriding UE4 defaults. Long story short, their implementation does something we should
  do a little more explicitly, so resetting this to a very simple behavior and we can re-build
  what they do, later on.
*/

void AStrangerController::SetIgnoreLookInput(bool bNewLookInput) {
  this->IgnoreLookInput = (int)bNewLookInput;
}

void AStrangerController::SetIgnoreMoveInput(bool bNewMoveInput) {
  this->IgnoreMoveInput = (int)bNewMoveInput;
}