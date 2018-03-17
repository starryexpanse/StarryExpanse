//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Enums/EInteractable.h"
#include "CoreMinimal.h"
#include "DragCallbackPreferences.generated.h"

USTRUCT(BlueprintType)
struct FDragCallbackPreferences {
  GENERATED_BODY()

  static FDragCallbackPreferences NoUpdates();
  static FDragCallbackPreferences ModerateDelay_Simple();

  UPROPERTY(BlueprintReadOnly)
  float MinimumStrobeDelay;

  UPROPERTY(BlueprintReadOnly)
  bool ReceiveHitInfoBeforeEveryUpdate;
};