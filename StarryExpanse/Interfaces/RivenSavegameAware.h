//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Object.h"
#include "RivenSavegameAware.generated.h"

UINTERFACE()
class STARRYEXPANSE_API URivenSavegameAware : public UInterface {
  GENERATED_UINTERFACE_BODY()
};

class IRivenSavegameAware {
  GENERATED_IINTERFACE_BODY()

public:
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Savegame)
  void SavegameUpdateNotify();

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Savegame)
  void SavegameInitialNotify();
};