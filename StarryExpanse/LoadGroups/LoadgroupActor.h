// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <set>
#include "LoadGroups/ELoadGroups.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoadgroupActor.generated.h"

UCLASS()
class STARRYEXPANSE_API ALoadgroupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoadgroupActor();

   DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLoadgroupLoadedEvent);

   /*
   FLoadgroupLoadedEvent& OnLoadgroupLoaded() {
      return LoadgroupLoadedEvent;
   }

   */
   UPROPERTY(BlueprintAssignable)
      FLoadgroupLoadedEvent LoadgroupLoadedEvent;

   UFUNCTION(Category = "Callbacks")
      void LevelLoaded();

   UFUNCTION(Category = "Callbacks")
      void LevelUnloaded();

	UFUNCTION(Category = "LoadGroups", BlueprintCallable)
		void LoadLoadGroup(ELoadGroups groupToLoad);

   UFUNCTION(Category = "LoadGroups", BlueprintCallable)
      void LoadLevelsNow();

   int levelsWaitingOnUnload = 0;
	int levelsWaitingOnLoad = 0;
   int levelLatentActionInfoCounter = 0;
	bool isInitialLoad = false;
   ELoadGroups currentLoadGroup = ELoadGroups::AAbsoluteZero;
   ELoadGroups wantedLoadGroup = ELoadGroups::AAbsoluteZero;
   ELoadGroups previouslyLoadedLoadGroup = ELoadGroups::AAbsoluteZero;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

