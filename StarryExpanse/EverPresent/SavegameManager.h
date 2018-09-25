// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoadGroups/ELoadGroups.h"
#include "SaveGame/RivenSaveGame.h"
#include "SavegameManager.generated.h"

// This object contends for LoadgroupQueen

UCLASS()
class STARRYEXPANSE_API ASavegameManager : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ASavegameManager();

  UFUNCTION(BlueprintCallable, Category = "Savegame Management")
  void StartNewGame();

  UFUNCTION(Category = "Savegame Management")
  void LoadGame(URivenSaveGame *nextSavegame);

  UFUNCTION(Category = "Savegame Management")
  void Cbk_ReadyForDispatchingLoadgroup();

  UFUNCTION(Category = "Savegame Management")
  void Cbk_OurLoadgroupLoaded();

  UFUNCTION(Category = "Savegame Management")
  bool CanLoadGameRightNow();

  DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameLoadedEvent);
  FGameLoadedEvent GameLoadedEvent;

private:
  bool IsLocked = false;

  void DestroyObject(UObject *Target);

  TScriptDelegate<FWeakObjectPtr> ReadyForDispatchingLoadgroup;
  TScriptDelegate<FWeakObjectPtr> OurLoadgroupLoaded;
};
