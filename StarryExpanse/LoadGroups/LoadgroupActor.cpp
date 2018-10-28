//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#include "LoadgroupActor.h"

#include "Classes/Engine/World.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Engine/LatentActionManager.h"
#include "Engine/LevelStreaming.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Public/LevelUtils.h"
#include "EngineUtils.h"

#include "LoadGroups/ELoadGroups.h"
#include "LoadGroups/LoadGroupInfo.h"
#include "Interfaces/RivenSavegameAware.h"
#include "RivenGameInstance.h"
#include "RivenGameState.h"
#include "StarryExpanse.h"

#include <algorithm>

// Sets default values
ALoadgroupActor::ALoadgroupActor() {
  LevelShownEvent.BindUFunction(this, "LevelShown");
}

void ALoadgroupActor::BeginPlay() {
  auto gameInstance = Cast<URivenGameInstance>(GetWorld()->GetGameInstance());
  gameInstance->RegisterLoadgroupQueen(this);
}

void ALoadgroupActor::LevelLoaded() {
  this->levelsWaitingOnLoad--;
  if (this->levelsWaitingOnLoad == 0) {
    this->currentLoadGroup = this->wantedLoadGroup;
    UE_LOG(StarryDebug, Display, TEXT("Finished loading LG."));

    auto levels = ULoadGroupInfo::GetLevelsInLoadGroup(this->wantedLoadGroup);
    for (const auto &levelName : levels) {
      auto level = UGameplayStatics::GetStreamingLevel(this, levelName);
      if (level == nullptr) {
        // level = level;
      }
      if (level != nullptr) {
        level->OnLevelShown.Add(LevelShownEvent);
        level->SetShouldBeVisible(true);
      }
    }
  }
}

void ALoadgroupActor::LevelShown() {
  this->levelsWaitingOnShow--;

  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  check(gs);

  auto saveGame = gs->Instantaneous_SaveGame;
  check(saveGame);

  if (this->levelsWaitingOnShow == 0) {

    auto levels = ULoadGroupInfo::GetLevelsInLoadGroup(this->wantedLoadGroup);
    for (const auto &levelName : levels) {
      auto level = UGameplayStatics::GetStreamingLevel(this, levelName);
      level->OnLevelShown.Remove(LevelShownEvent);
      auto loadedLevel = level->GetLoadedLevel();

      if (loadedLevel) {
        TArray<AActor *> actors = loadedLevel->Actors;

        for (auto actor : actors) {
          if (actor->GetClass()->ImplementsInterface(
                  URivenSavegameAware::StaticClass())) {
            IRivenSavegameAware::Execute_SavegameInitialNotify(actor, saveGame);
          }
        }
      } else {
        STARRY_CRITICAL(
            "Tried to get world for a newly loaded level but it was null.");
      }
    }
    LoadgroupLoadedEvent.Broadcast();
  }
}

void ALoadgroupActor::LevelUnloaded() {
  this->levelsWaitingOnUnload--;
  if (this->levelsWaitingOnUnload == 0) {
    this->LoadLevelsNow();
  }
}

void ALoadgroupActor::LoadLevelsNow() {
  auto levels = ULoadGroupInfo::GetLevelsToBeLoaded(
      this->previouslyLoadedLoadGroup, this->wantedLoadGroup);

  auto numLevelsToLoad = levels.size();
  this->levelsWaitingOnLoad = numLevelsToLoad;
  this->levelsWaitingOnShow = numLevelsToLoad;

  if (this->levelsWaitingOnLoad == 0) {
    this->currentLoadGroup = this->wantedLoadGroup;
    LoadgroupLoadedEvent.Broadcast();
  } else {
    for (const auto &levelName : levels) {
      this->levelLatentActionInfoCounter += 1;

      FLatentActionInfo LatentInfo;
      LatentInfo.UUID = this->levelLatentActionInfoCounter;
      LatentInfo.Linkage = 0;
      LatentInfo.CallbackTarget = this;
      LatentInfo.ExecutionFunction = FName("LevelLoaded");

      bool shouldShow = false;
      UGameplayStatics::LoadStreamLevel(this, FName(levelName), shouldShow,
                                        false, LatentInfo);
    }
  }
}

void ALoadgroupActor::LoadLoadGroup(ELoadGroups groupToLoad) {
  this->previouslyLoadedLoadGroup = this->currentLoadGroup;
  this->wantedLoadGroup = groupToLoad;

  // Determine levels to unload
  auto levelsToUnload = ULoadGroupInfo::GetLevelsToBeUnloaded(
      this->currentLoadGroup, this->wantedLoadGroup);

  if (levelsToUnload.size() == 0) {
    this->LoadLevelsNow();
  } else {
    this->levelsWaitingOnUnload = levelsToUnload.size();
    for (const auto &levelName : levelsToUnload) {
      levelLatentActionInfoCounter += 1;

      FLatentActionInfo LatentInfo;
      LatentInfo.UUID = this->levelLatentActionInfoCounter;
      LatentInfo.Linkage = 0;
      LatentInfo.CallbackTarget = this;
      LatentInfo.ExecutionFunction = FName("LevelUnloaded");

      UGameplayStatics::UnloadStreamLevel(this, FName(levelName), LatentInfo,
                                          false);
    }
  }
}

bool ALoadgroupActor::IsLoading() {
  return this->currentLoadGroup != this->wantedLoadGroup;
}
