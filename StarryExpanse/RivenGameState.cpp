#include "RivenGameState.h"
#include "SaveGame/RivenSaveGame.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "RivenGameInstance.h"
#include "StarryExpanse.h"
#include "UObject/ConstructorHelpers.h"

ARivenGameState::ARivenGameState() : Super() {}

void ARivenGameState::OnConstruction(const FTransform &Transform) {
  auto initialSavegame = NewObject<URivenSaveGame>();
  this->Instantaneous_SaveGame = initialSavegame;
  auto gameInstance = GetWorld()->GetGameInstance<URivenGameInstance>();
  gameInstance->Last_Savable_SaveGame = initialSavegame;
}

/*
void ARivenGameState::SubscribeActorToSavegame(AActor* Actor) {
  SubscribedToSavegame.Add(Actor);
}

void ARivenGameState::UnsubscribeActorFromSavegame(AActor* Actor) {
  SubscribedToSavegame.Remove(Actor);
}
*/

void ARivenGameState::NotifySubscribersOfChange(URivenSaveGame *OldSaveGame) {
  //URivenSaveGame NewSaveGame = *Instantaneous_SaveGame;
}
