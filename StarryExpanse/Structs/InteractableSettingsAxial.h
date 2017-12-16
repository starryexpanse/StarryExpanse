//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Actors/EInteractable.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableSettingsAxial.generated.h"
#include "SaveGame/ESaveGameField.h"

USTRUCT(BlueprintType)
struct FInteractableSettingsAxial {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite)
  ESaveGameField SaveGameField;

  UPROPERTY(BlueprintReadWrite)
  UStaticMeshComponent *MoveablePart;

  UPROPERTY(BlueprintReadWrite)
  float AnimationDuration;

  UPROPERTY(BlueprintReadWrite)
  TEnumAsByte<EAxis::Type> Axis;

  UPROPERTY(BlueprintReadWrite)
  float AnimationStartValue;

  UPROPERTY(BlueprintReadWrite)
  float AnimationEndValue;
};