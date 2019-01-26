#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Logging.generated.h"

UCLASS()
class STARRYEXPANSE_API ULogging : public UBlueprintFunctionLibrary {
  GENERATED_UCLASS_BODY()

  UFUNCTION(BlueprintCallable, Category = "Logging")
  static void LogWarning(FString text);

  UFUNCTION(BlueprintCallable, Category = "Logging")
  static void LogCritical(FString text);
};