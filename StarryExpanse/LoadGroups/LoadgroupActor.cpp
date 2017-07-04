// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadgroupActor.h"
#include <algorithm>
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
   this->levelsWaitingOn--;
   if (this->levelsWaitingOn == 0) {
      LoadgroupLoadedEvent.Broadcast();
   }
	UE_LOG(StarryDebug, Warning, TEXT("I loaded it! %d"), this->levelsWaitingOn);
}

void ALoadgroupActor::LoadLoadGroup(ELoadGroups groupToLoad) {
   auto levels = ULoadGroupInfo::GetLevelsInLoadGroup(groupToLoad);
   this->levelsWaitingOn = levels.size();

   for (const auto& levelName : levels) {
      this->levelLoadUuidCounter += 1;

      FLatentActionInfo LatentInfo;
      LatentInfo.UUID = this->levelLoadUuidCounter;
      LatentInfo.Linkage = 0;
      LatentInfo.CallbackTarget = this;
      LatentInfo.ExecutionFunction = FName("LevelLoaded");

      UGameplayStatics::LoadStreamLevel(this, FName(levelName), true, false, LatentInfo);
   }
}

// Called every frame
void ALoadgroupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

