//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actors/EInteractable.h"
#include "SaveGame/ESaveGameField.h"
#include "RivenGameInstanceVars.generated.h"

USTRUCT(BlueprintType)
struct FRivenGameInstanceVars
{
  GENERATED_BODY()

    void Reset() {
      CursorMode = 0;
      InventoryBookOpen = 0;
      InventoryBookPage = 0;
      InventoryBookPageTurnAmount = 0;
      IsFrozenForLoading = false;
      IsFrozenForLoadingFirstTime = false;
    };

  UPROPERTY(BlueprintReadOnly)
    int32 CursorMode; // 0 = fixed to center, 1 = unlocked

  UPROPERTY(BlueprintReadOnly)
    int32 InventoryBookOpen; // 0 = none, 1 = atrus's journal, 2 = catherine's journal, 3 = trap book

  UPROPERTY(BlueprintReadOnly)
    int32 InventoryBookPage; // 0 = front cover, 1...N = different pages

  UPROPERTY(BlueprintReadOnly)
    float InventoryBookPageTurnAmount; // 0 = front cover, 1...N = different pages

  UPROPERTY(BlueprintReadOnly)
	  bool IsFrozenForLoading;

  UPROPERTY(BlueprintReadOnly)
    bool IsFrozenForLoadingFirstTime;
};
