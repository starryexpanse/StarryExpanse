// Fill out your copyright notice in the Description page of Project Settings.

#include "SavegameManager.h"
#include "Classes/Engine/World.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Engine/LatentActionManager.h"
#include "Engine/LevelStreaming.h"
#include "Kismet/GameplayStatics.h"
#include "LoadGroups/ELoadGroups.h"
#include "LoadGroups/LoadGroupInfo.h"
#include "SaveGame/RivenSaveGame.h"
#include "RivenGameInstance.h"
#include "RivenGameState.h"
#include "Runtime/Engine/Public/LevelUtils.h"
#include "StarryExpanse.h"
#include <algorithm>

// Sets default values
ASavegameManager::ASavegameManager() {
  ReadyForDispatchingLoadgroup.BindUFunction(
      this, "Cbk_ReadyForDispatchingLoadgroup");
  OurLoadgroupLoaded.BindUFunction(this, "Cbk_OurLoadgroupLoaded");
}

bool ASavegameManager::CanLoadGameRightNow() { return !IsLocked; }

void ASavegameManager::LoadGame(URivenSaveGame *nextSavegame) {
  if (IsLocked) {
    return;
  }

  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  if (!gs) {
    return;
  }

  auto lgQueen = gs->LoadgroupQueen;
  if (!lgQueen) {
    return;
  }

  // Committed, from this point on.

  auto pawn = UGameplayStatics::GetPlayerPawn(this, 0);
  if (pawn) {
    pawn->K2_DestroyActor();
    pawn = nullptr;
    GEngine->ForceGarbageCollection(true);
  }

  IsLocked = true;
  gs->SetNewCurrentSavegame(nextSavegame);

  if (lgQueen->IsLoading()) {
    lgQueen->LoadgroupLoadedEvent.Add(ReadyForDispatchingLoadgroup);
  } else {
    Cbk_ReadyForDispatchingLoadgroup();
  }
}

void ASavegameManager::Cbk_ReadyForDispatchingLoadgroup() {
  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  check(gs);

  auto lgQueen = gs->LoadgroupQueen;
  check(lgQueen);

  if (lgQueen->IsLoading()) {
    STARRY_CRITICAL(
        "We thought the Loadgroup queen would be ready by now, but she isn't!");
    return;
  }

  lgQueen->LoadgroupLoadedEvent.Remove(ReadyForDispatchingLoadgroup);
  lgQueen->LoadgroupLoadedEvent.Add(OurLoadgroupLoaded);

  auto loadgroupToLoad =
      gs->Instantaneous_SaveGame->Get_A_LoadGroups_CurrentLoadGroup();
  lgQueen->LoadLoadGroup(loadgroupToLoad);
}

void ASavegameManager::Cbk_OurLoadgroupLoaded() {
  IsLocked = false;

  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  check(gs);

  auto lgQueen = gs->LoadgroupQueen;
  check(lgQueen);

  lgQueen->LoadgroupLoadedEvent.Remove(OurLoadgroupLoaded);

  // Set up player

  FActorSpawnParameters params;
  params.Name = FName("Pawn");
  params.Owner = this;
  params.SpawnCollisionHandlingOverride =
      ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

  auto gameMode = GetWorld()->GetAuthGameMode();
  auto pawnClass = gameMode->DefaultPawnClass;

  auto transform = gs->Instantaneous_SaveGame->Get_A_RivenCharacter_Transform();

  auto pawn = this->GetWorld()->SpawnActor<APawn>(
      pawnClass, transform.GetLocation(), transform.Rotator(), params);

  auto controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
  controller->Possess(pawn);

  this->GameLoadedEvent.Broadcast();
}

void ASavegameManager::StartNewGame() {
  auto blankSavegame = NewObject<URivenSaveGame>();
  blankSavegame->RestoreNewGameDefaults();

  // HACK: some overrides for easier debugging. Will be removed by release.
  // We have this because right now, Temple is not possible to walk through
  // due to incorrect scale.
  blankSavegame->Set_A_LoadGroups_CurrentLoadGroup(ELoadGroups::BCentral);
  blankSavegame->Set_A_RivenCharacter_Transform(
      FTransform(FVector(-964.43, -2220, 886.8)));

  // TODO: Generate telescope code & dome code here

  this->LoadGame(blankSavegame);
}
