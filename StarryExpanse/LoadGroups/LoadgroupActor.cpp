// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadgroupActor.h"
#include <algorithm>
#include "Engine/LevelStreaming.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Public/LevelUtils.h"
#include "LoadGroups/ELoadGroups.h"
#include "LoadGroups/LoadGroupInfo.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LatentActionManager.h"
#include "StarryExpanse.h"

// Sets default values
ALoadgroupActor::ALoadgroupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ALoadgroupActor::LevelLoaded() {
   this->levelsWaitingOnLoad--;
   if (this->levelsWaitingOnLoad == 0) {
      this->currentLoadGroup = this->wantedLoadGroup;
      LoadgroupLoadedEvent.Broadcast();
   }

   auto wningWorld = this->GetWorld();
   auto journals = UGameplayStatics::GetStreamingLevel(this, TEXT("A_Journals"));
   if (journals) {
      auto x = journals->GetName();
      UE_LOG(StarryDebug, Warning, TEXT("I loaded it!"));
   }
   // FLevelUtils::MarkLevelForUnloading();
	UE_LOG(StarryDebug, Warning, TEXT("I loaded it! %d"), this->levelsWaitingOnLoad);
}

void ALoadgroupActor::LevelUnloaded() {
   this->levelsWaitingOnUnload--;
   if (this->levelsWaitingOnUnload == 0) {
      this->LoadLevelsNow();
   }
}

void ALoadgroupActor::LoadLevelsNow() {
   auto levels = ULoadGroupInfo::GetLevelsToBeLoaded(this->previouslyLoadedLoadGroup, this->wantedLoadGroup);

   // TODO don't re-load already-loaded levels
   this->levelsWaitingOnLoad = levels.size();
   for (const auto& levelName : levels) {
      this->levelLatentActionInfoCounter += 1;

      FLatentActionInfo LatentInfo;
      LatentInfo.UUID = this->levelLatentActionInfoCounter;
      LatentInfo.Linkage = 0;
      LatentInfo.CallbackTarget = this;
      LatentInfo.ExecutionFunction = FName("LevelLoaded");

      UGameplayStatics::LoadStreamLevel(this, FName(levelName), true, false, LatentInfo);
   }
}

void ALoadgroupActor::LoadLoadGroup(ELoadGroups groupToLoad) {
   this->previouslyLoadedLoadGroup = this->currentLoadGroup;
   this->wantedLoadGroup = groupToLoad;

   // Determine levels to unload
   auto levelsToUnload = ULoadGroupInfo::GetLevelsToBeUnloaded(this->currentLoadGroup, this->wantedLoadGroup);

   if (levelsToUnload.size() == 0) {
      this->LoadLevelsNow();
   } else {
      this->levelsWaitingOnUnload = levelsToUnload.size();
      for (const auto& levelName : levelsToUnload) {
         levelLatentActionInfoCounter += 1;

         FLatentActionInfo LatentInfo;
         LatentInfo.UUID = this->levelLatentActionInfoCounter;
         LatentInfo.Linkage = 0;
         LatentInfo.CallbackTarget = this;
         LatentInfo.ExecutionFunction = FName("LevelUnloaded");

         UGameplayStatics::UnloadStreamLevel(this, FName(levelName), LatentInfo);
      }
   }
   // auto level = FindStreamingLevel(UWorld* InWorld, const TCHAR* PackageName);
   
}

bool ALoadgroupActor::IsLoading() {
   return this->currentLoadGroup != this->wantedLoadGroup;
}

// Called every frame
void ALoadgroupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

