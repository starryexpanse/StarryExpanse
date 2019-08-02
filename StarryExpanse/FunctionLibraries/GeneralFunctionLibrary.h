// Copyright, 59 Volt Entertainment, all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GeneralFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class STARRYEXPANSE_API UGeneralFunctionLibrary
    : public UBlueprintFunctionLibrary {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "General Function Library")
  static FVector GetInitialSpawnPosition();

  UFUNCTION(BlueprintCallable, Category = "General Function Library")
  static bool GetShouldPlayMusic();

  UFUNCTION(BlueprintCallable, Category = "General Function Library")
  static bool GetIsVrGame();

  UFUNCTION(BlueprintCallable, Category = "General Function Library")
  static bool GetIsVrTeleportGame();
};
