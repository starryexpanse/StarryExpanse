//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Object.h"
#include "Structs/InteractabilityProbeResponse.h"
#include "RivenInteractable.generated.h"

// https://wiki.unrealengine.com/Blueprints,_Empower_Your_Entire_Team_With_BlueprintImplementableEvent
// https://wiki.unrealengine.com/Interfaces_in_C%2B%2B

UINTERFACE()
class STARRYEXPANSE_API URivenInteractable : public UInterface {
  GENERATED_UINTERFACE_BODY()
};

class IRivenInteractable {
  GENERATED_IINTERFACE_BODY()

public:
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  void LookingAt();

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  void Touched();

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
    FInteractabilityProbeResponse ProbeInteractability();
};