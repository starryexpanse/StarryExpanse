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
   UPROPERTY(BlueprintAssignable, Category = "LoadGroups")
      FLoadgroupLoadedEvent LoadgroupLoadedEvent;

   UFUNCTION(Category = "LoadGroups")
      void LevelLoaded();

   UFUNCTION(Category = "LoadGroups")
      void LevelUnloaded();

   UFUNCTION(Category = "LoadGroups", BlueprintCallable)
      void LoadLoadGroup(ELoadGroups groupToLoad);

   UFUNCTION(Category = "LoadGroups", BlueprintCallable)
      void LoadLevelsNow();

   UFUNCTION(Category = "LoadGroups", BlueprintCallable)
      bool IsLoading();

   UPROPERTY(BlueprintReadOnly, Category = "LoadGroups")
      int levelsWaitingOnUnload = 0;

   UPROPERTY(BlueprintReadOnly, Category = "LoadGroups")
      int levelsWaitingOnLoad = 0;
   
   UPROPERTY(BlueprintReadOnly, Category = "LoadGroups")
      int levelLatentActionInfoCounter = 0;
   
   UPROPERTY(BlueprintReadOnly, Category = "LoadGroups")
      bool isInitialLoad = false;

   UPROPERTY(BlueprintReadOnly, Category = "LoadGroups")
      ELoadGroups currentLoadGroup = ELoadGroups::AAbsoluteZero;

   UPROPERTY(BlueprintReadOnly, Category = "LoadGroups")
      ELoadGroups wantedLoadGroup = ELoadGroups::AAbsoluteZero;

   UPROPERTY(BlueprintReadOnly, Category = "LoadGroups")
      ELoadGroups previouslyLoadedLoadGroup = ELoadGroups::AAbsoluteZero;

   // Called every frame
   virtual void Tick(float DeltaTime) override;
};

