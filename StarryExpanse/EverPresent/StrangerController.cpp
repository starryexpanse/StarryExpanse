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
#include "Actors/Player/VRCharacter.h"
#include "StarryExpanse.h"

AStrangerController::AStrangerController() {
  MenuStateChanged.BindUFunction(this, "Cbk_MenuStateChanged");

  auto world = GetWorld();
  if (world) {
    auto gameMode = Cast<AStarryExpanseGameMode>(world->GetAuthGameMode());
    auto ginst = Cast<URivenGameInstance>(world->GetGameInstance());

    if (gameMode && ginst && ginst->bWasAppStartedInVRMode) {
      PrimaryActorTick.bCanEverTick = true;
    }
  }
}

void AStrangerController::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

  auto Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
  auto VrCharacter = Cast<AVRCharacter>(Character);
  if (VrCharacter) {
    auto handTransform = VrCharacter->GetPointerHandTransform();

    bool gotHit;
    auto handForward = handTransform.TransformVector(FVector::ForwardVector);
    handForward.Normalize();

    auto params = FCollisionQueryParams::DefaultQueryParam;
    params.AddIgnoredActor(VrCharacter);

    auto hitResult = this->CastInteractionRay(
        gotHit, handTransform.TransformPosition(FVector::ZeroVector),
        handForward, params);

    AActor *hitActor = nullptr;

    if (gotHit) {
      hitActor = hitResult.GetActor();
    }

    if (hitActor && hitActor->GetClass()->ImplementsInterface(
                        URivenInteractable::StaticClass())) {
      if (PreviouslyLookingAtInteractable &&
          PreviouslyLookingAtInteractable != hitActor) {
        IRivenInteractable::Execute_LookingAt_End(
            PreviouslyLookingAtInteractable);
      }
      if (PreviouslyLookingAtInteractable != hitActor) {
        PreviouslyLookingAtInteractable = hitActor;
        IRivenInteractable::Execute_LookingAt_Begin(hitActor, hitResult);
      }
    } else {
      if (PreviouslyLookingAtInteractable) {
        IRivenInteractable::Execute_LookingAt_End(
            PreviouslyLookingAtInteractable);
        PreviouslyLookingAtInteractable = nullptr;
      }
    }
  }
}

void AStrangerController::BeginPlay() {
  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  check(gs);

  this->ReactToMenuState(gs->CurrentMenuPage);
  gs->MenuStateChangedEvent.Add(MenuStateChanged);

  auto gameInstance = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
  gameInstance->GameInstanceVarsChanged.AddDynamic(
      this, &AStrangerController::PossiblyFreezeOrUnfreeze);
  this->EnterCursorMode(true);
}

void AStrangerController::Cbk_MenuStateChanged() {
  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  this->ReactToMenuState(gs->CurrentMenuPage);
}

void AStrangerController::ReactToMenuState(EGameMenuPage menuPage) {
  auto hud = Cast<AStarryExpanseHUD>(this->GetHUD());
  check(hud);

  if (menuPage != EGameMenuPage::NoPage) {
    FInputModeUIOnly mode;

    auto widget = hud->GetLoadingGuiWidget()->TakeWidget();

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
  auto gameMode = Cast<AStarryExpanseGameMode>(GetWorld()->GetAuthGameMode());
  auto ginst = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());

  if (gameMode && ginst) {
    if (!ginst->bWasAppStartedInVRMode) {
      if (IsCursorLockedToCenter) {
        this->AddYawInput(amount);
      }
    } else {
      auto Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
      auto VrCharacter = Cast<AVRCharacter>(Character);
      if (VrCharacter) {
        VrCharacter->OnTurn(amount);
      }
    }
  }
}

void AStrangerController::AddVerticalMousePan(float amount) {
  if (IsCursorLockedToCenter) {
    this->AddPitchInput(amount);
  }
}

void AStrangerController::AddHorizontalMouseScan(float amount) {
  if (!IsCursorLockedToCenter) {
    HorizontalMousePosition =
        FMath::Clamp(HorizontalMousePosition + amount, 0.0f, 1.0f);

    // check to see if we're within +tolerance for screen border
    if (1 - HorizontalMousePosition < HorizontalMouseNudgeThreshold) {
      // rotate the camera in accordance with how close the cursor is to the
      // edge of the screen
      this->AddYawInput(
          (HorizontalMouseNudgeThreshold - (1 - HorizontalMousePosition)) *
          HorizontalMouseNudgeMultiplier);
    }

    // check to see if we're within -tolerance for screen border
    if (HorizontalMousePosition < HorizontalMouseNudgeThreshold) {
      // rotate the camera in accordance with how close the cursor is to the
      // edge of the screen
      this->AddYawInput(
          (-(HorizontalMouseNudgeThreshold - HorizontalMousePosition)) *
          HorizontalMouseNudgeMultiplier);
    }
  }
}

void AStrangerController::AddVerticalMouseScan(float amount) {
  if (!IsCursorLockedToCenter) {
    VerticalMousePosition =
        FMath::Clamp(VerticalMousePosition + amount, 0.0f, 1.0f);

    // check to see if we're within +tolerance for screen border
    if (1 - VerticalMousePosition < VerticalMouseNudgeThreshold) {
      // rotate the camera in accordance with how close the cursor is to the
      // edge of the screen
      this->AddPitchInput(
          (VerticalMouseNudgeThreshold - (1 - VerticalMousePosition)) *
          VerticalMouseNudgeMultiplier);
    }

    // check to see if we're within -tolerance for screen border
    if (VerticalMousePosition < VerticalMouseNudgeThreshold) {
      // rotate the camera in accordance with how close the cursor is to the
      // edge of the screen
      this->AddPitchInput(
          (-(VerticalMouseNudgeThreshold - VerticalMousePosition)) *
          VerticalMouseNudgeMultiplier);
    }
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

  auto hitResult =
      this->CastInteractionRay(gotHit, ViewLocation, Camera->GetForwardVector(),
                               FCollisionQueryParams::DefaultQueryParam);

  if (gotHit) {
    auto hitActor = hitResult.GetActor();
    if (hitActor != nullptr && hitActor->GetClass()->ImplementsInterface(
                                   URivenInteractable::StaticClass())) {
      IRivenInteractable::Execute_Touched(hitActor);
    }
  }
}

void AStrangerController::InteractVR() {
  auto Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
  auto VrCharacter = Cast<AVRCharacter>(Character);
  if (VrCharacter) {
    auto handTransform = VrCharacter->GetPointerHandTransform();

    bool gotHit;
    auto handForward = handTransform.TransformVector(FVector::ForwardVector);
    handForward.Normalize();

    auto params = FCollisionQueryParams::DefaultQueryParam;
    params.AddIgnoredActor(VrCharacter);

    auto hitResult = this->CastInteractionRay(
        gotHit, handTransform.TransformPosition(FVector::ZeroVector),
        handForward, params);

    AActor *hitActor = nullptr;

    if (gotHit) {
      hitActor = hitResult.GetActor();
    }

    if (hitActor && hitActor->GetClass()->ImplementsInterface(
                        URivenInteractable::StaticClass())) {
      IRivenInteractable::Execute_Touched(hitActor);
    }
  }
}

FHitResult
AStrangerController::CastInteractionRay(bool &gotHit, FVector worldLocation,
                                        FVector worldDirection,
                                        FCollisionQueryParams Params) {

  gotHit = false;

  struct FHitResult HitResult;

  /*auto viewTarget = this->GetViewTarget();
  if (!viewTarget)
    return HitResult;

  auto Cameras = viewTarget->GetComponentsByTag(UCameraComponent::StaticClass(),
                                                FName("MainCamera"));
  if (!Cameras.IsValidIndex(0))
    return HitResult;

  auto Camera = Cast<UCameraComponent>(Cameras[0]);
  if (!Camera)
    return HitResult;*/
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
  auto world = GetWorld();

  if (world) {
    auto gameInstance = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
    auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());

    if (gameInstance && gs) {
      gameInstance->GameInstanceVarsChanged.RemoveDynamic(
          this, &AStrangerController::PossiblyFreezeOrUnfreeze);

      gs->MenuStateChangedEvent.Remove(MenuStateChanged);

      STARRY_CRITICAL("Controller destroyed");
    }
  }
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
