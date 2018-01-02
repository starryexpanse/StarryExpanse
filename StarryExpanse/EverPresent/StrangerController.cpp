//
// Copyright 2018 59 Volt Entertainment, all rights reserved.
//

#include "StrangerController.h"
#include "RivenGameInstance.h"

AStrangerController::AStrangerController() {}

void AStrangerController::BeginPlay() {
  auto gameInstance = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
  gameInstance->GameInstanceVarsChanged.AddDynamic(
      this, &AStrangerController::PossiblyFreezeOrUnfreeze);
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
