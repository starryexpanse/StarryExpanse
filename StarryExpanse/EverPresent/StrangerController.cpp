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

void AStrangerController::SetupInputComponent() {
  Super::SetupInputComponent();

  this->InputComponent->BindAction(
    "Interact",
    EInputEvent::IE_Pressed,
    this,
    &AStrangerController::Interact
  );
}

void AStrangerController::BeginPlay() {
  auto gameInstance = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
  gameInstance->GameInstanceVarsChanged.AddDynamic(
      this,
      &AStrangerController::PossiblyFreezeOrUnfreeze
  );
}

void AStrangerController::Interact() {
  bool gotHit;
  bool hadError;
  auto hitResult = this->CastInteractionRay(gotHit, hadError, 0, 0);

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
  bool &hadError,
  float xCenterOffset, // range [-1, 1]
  float yCenterOffset // range [-1, 1]
) {
    hadError = true;
    gotHit = false;
    auto world = GetWorld();
    
    FVector ViewLocation;
    FRotator ViewRotation;
    
    this->GetPlayerViewPoint(
      ViewLocation,
      ViewRotation
    );

    auto viewTarget = this->GetViewTarget();
    
    struct FHitResult HitResult;

    if (viewTarget != nullptr) {
      auto Cameras = viewTarget->GetComponentsByTag(
        UCameraComponent::StaticClass(),
        FName("MainCamera")
      );
      if (Cameras.IsValidIndex(0)) {
        auto Camera = Cast<UCameraComponent>(Cameras[0]);
        if (Camera) {
          FCollisionQueryParams Params = FCollisionQueryParams::DefaultQueryParam;
          FCollisionResponseParams ResponseParams = FCollisionResponseParams::DefaultResponseParam;

          float range = 500;
          float halfHorizFov = FMath::DegreesToRadians(Camera->FieldOfView / 2.0);
          float halfVerticalFov = FMath::DegreesToRadians((Camera->FieldOfView / Camera->AspectRatio) / 2.0);

          float phi = FMath::Atan(xCenterOffset * FMath::Tan(halfHorizFov));
          float theta = FMath::Atan(yCenterOffset * FMath::Tan(halfVerticalFov));

          float sinphi = FMath::Sin(phi);
          float sintheta = FMath::Sin(theta);
          float cosphi = FMath::Cos(phi);
          float costheta = FMath::Cos(theta);

          float rightOffset = costheta * sinphi;
          float forwardOffset = costheta * cosphi;
          float upwardOffset = sintheta;

          FVector localOffset(
            forwardOffset,
            rightOffset,
            upwardOffset
          );

          auto transform = this->ActorToWorld();

          gotHit = world->LineTraceSingleByChannel(
            HitResult,
            ViewLocation,
            ViewLocation + transform.TransformVectorNoScale(localOffset) * range,
            ECollisionChannel::ECC_Visibility,
            Params,
            ResponseParams
          );
          hadError = false;
        }
      }
    }
    
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
