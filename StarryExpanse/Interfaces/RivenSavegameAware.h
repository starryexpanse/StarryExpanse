//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Object.h"
#include "SaveGame/RivenSaveGame.h"
#include "RivenSavegameAware.generated.h"

UINTERFACE()
class STARRYEXPANSE_API URivenSavegameAware : public UInterface {
  GENERATED_UINTERFACE_BODY()
};

class IRivenSavegameAware {
  GENERATED_IINTERFACE_BODY()

public:
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Savegame)
  void SavegameUpdateNotify(URivenSaveGame *OldSaveGame, URivenSaveGame *NewSaveGame);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Savegame)
  void SavegameInitialNotify(URivenSaveGame *CurrentSaveGame);
};