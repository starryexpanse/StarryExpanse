#include "RivenGameState.h"
#include "SaveGame/RivenSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"

ARivenGameState::ARivenGameState()
	: Super()
{
  auto world = this->GetWorld();
  if (!world) {
    return;
  }
  auto initialSavegame = NewObject<URivenSaveGame>();
  auto gs = static_cast<ARivenGameState*>(world->GetGameState());
  if (!gs) {
    return;
  }
  gs->Instantaneous_SaveGame = initialSavegame;
}

void ARivenGameState::HandleBeginPlay() {
  auto world = this->GetWorld();
  if (!world) {
    return;
  }
  auto initialSavegame = NewObject<URivenSaveGame>();
  auto gs = static_cast<ARivenGameState*>(world->GetGameState());
  if (!gs) {
    return;
  }
  gs->Instantaneous_SaveGame = initialSavegame;
}