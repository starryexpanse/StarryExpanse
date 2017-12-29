//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//
#include "RivenSavegameAware.h"

URivenSavegameAware::URivenSavegameAware(
    const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {}

void IRivenSavegameAware::SavegameUpdateNotify_Implementation() {}

void IRivenSavegameAware::SavegameInitialNotify_Implementation() {}