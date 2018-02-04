//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#include "RivenSavegameAware.h"
#include "SaveGame/RivenSaveGame.h"

URivenSavegameAware::URivenSavegameAware(
    const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {}

void IRivenSavegameAware::SavegameUpdateNotify_Implementation(
    URivenSaveGame *OldSaveGame, URivenSaveGame *NewSaveGame) {}

void IRivenSavegameAware::SavegameInitialNotify_Implementation(
    URivenSaveGame *CurrentSaveGame) {}