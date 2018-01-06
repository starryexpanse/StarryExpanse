//
// Copyright 2018 59 Volt Entertainment, all rights reserved.
//

#include "StrangerController.h"
#include "Actors/RivenInteractable.h"
#include "Camera/CameraActor.h"
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
  auto hitResult = this->CastInteractionRay(gotHit);

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

FHitResult AStrangerController::CastInteractionRay(bool &gotHit, float xFraction, float yFraction) {
    auto world = GetWorld();
    
    FVector ViewLocation;
    FRotator ViewRotation;
    
    this->GetPlayerViewPoint(
      ViewLocation,
      ViewRotation
    );

    ACameraActor* CurrentCameraActor = Cast<ACameraActor>(GetViewTarget());
    
    struct FHitResult HitResult;

    if (CurrentCameraActor != nullptr) {
      FCollisionQueryParams Params;
      FCollisionResponseParams ResponseParams;
      
      float range = 500;
      
      gotHit = world->LineTraceSingleByChannel(
          HitResult,
          ViewLocation,
          ViewLocation + this->GetActorForwardVector() * range,
          ECollisionChannel::ECC_Visibility,
          Params,
          ResponseParams
      );
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
