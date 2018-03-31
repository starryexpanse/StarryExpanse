//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "CoreMinimal.h"
#include "SaveGame/ESaveGameField.h"
#include "Runtime/Engine/Classes/Animation/AnimSequence.h"
#include "InteractableSettingsSkeletal.generated.h"

USTRUCT(BlueprintType)
struct FInteractableSettingsSkeletal {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite)
  ESaveGameField SaveGameField;

  UPROPERTY(BlueprintReadWrite)
  UAnimSequence *ForwardsAnimation;

  UPROPERTY(BlueprintReadWrite)
  UAnimSequence *BackwardsAnimation;

  UPROPERTY(BlueprintReadWrite)
  USkeletalMeshComponent *MainSkeleton;

  UPROPERTY(BlueprintReadWrite)
  float AnimationDuration;

  UPROPERTY(BlueprintReadWrite)
  bool IsFalseAtEnd;
};