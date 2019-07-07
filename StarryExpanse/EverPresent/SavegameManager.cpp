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
#include "StarryExpanseGameMode.h"
#include "RivenGameState.h"
#include "Runtime/Core/Public/Misc/ConfigCacheIni.h"
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
  params.SpawnCollisionHandlingOverride =
      ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

  auto gameMode = Cast<AStarryExpanseGameMode>(GetWorld()->GetAuthGameMode());
  check(gameMode);
  auto ginst = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
  check(ginst);
  auto pawnClass = ginst->bWasAppStartedInVRMode ? gameMode->VrPawnClass
                                                 : gameMode->DefaultPawnClass;

  auto transform = gs->Instantaneous_SaveGame->Get_A_RivenCharacter_Transform();

  auto pawn = this->GetWorld()->SpawnActor<APawn>(
      pawnClass, transform.GetLocation(), transform.Rotator(), params);

  auto controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
  controller->Possess(pawn);

  gs->SetMenuPage(EGameMenuPage::NoPage);
  this->GameLoadedEvent.Broadcast();
}

void ASavegameManager::StartNewGame() {
  auto blankSavegame = NewObject<URivenSaveGame>();
  blankSavegame->RestoreNewGameDefaults();

  FConfigFile config;
  FConfigCacheIni::LoadLocalIniFile(config, TEXT("StarryExpanse"), false,
                                    nullptr, true);

  auto initialSpawn = config.Find("InitialSpawn");

  float x = 0;
  float y = 0;
  float z = 0;

  if (initialSpawn) {
    auto xUnchecked = initialSpawn->Find("LocationX");
    auto yUnchecked = initialSpawn->Find("LocationY");
    auto zUnchecked = initialSpawn->Find("LocationZ");
    x = xUnchecked ? FCString::Atof(*xUnchecked->GetValue()) : 0;
    y = yUnchecked ? FCString::Atof(*yUnchecked->GetValue()) : 0;
    z = zUnchecked ? FCString::Atof(*zUnchecked->GetValue()) : 0;
  }

  // HACK: some overrides for easier debugging. Will be removed by release.
  // We have this because right now, Temple is not possible to walk through
  // due to incorrect scale.
  blankSavegame->Set_A_LoadGroups_CurrentLoadGroup(
      ELoadGroups::GUpsideInterior);
  blankSavegame->Set_A_RivenCharacter_Transform(FTransform(FVector(x, y, z)));

  // TODO: Generate telescope code & dome code here

  this->LoadGame(blankSavegame);
}
