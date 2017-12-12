#include "RivenGameState.h"
#include "SaveGame/RivenSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "RivenGameInstance.h"
#include "StarryExpanse.h"

ARivenGameState::ARivenGameState()
	: Super()
{
}

void ARivenGameState::OnConstruction(const FTransform & Transform) {
  auto initialSavegame = NewObject<URivenSaveGame>();
  this->Instantaneous_SaveGame = initialSavegame;
  auto gameInstance = GetWorld()->GetGameInstance<URivenGameInstance>();
  gameInstance->Last_Savable_SaveGame = initialSavegame;
}

