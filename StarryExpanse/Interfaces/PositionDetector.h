//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Runtime/CoreUObject/Public/UObject/Interface.h"
#include "PositionDetector.generated.h"

UINTERFACE()
class STARRYEXPANSE_API UPositionDetector : public UInterface {
  GENERATED_BODY()
};

class IPositionDetector {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Framework)
  int32 GetRegionNumberFromPosition(FVector position);

};
