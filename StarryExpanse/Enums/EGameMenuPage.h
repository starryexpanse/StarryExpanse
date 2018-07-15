
//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

// Description: Which page the user is seeing right now (main menu, options, etc.)

#pragma once

#include "Engine/UserDefinedEnum.h"

UENUM(BlueprintType)
enum class EGameMenuPage : uint8 {
  NoPage UMETA(DisplayName = 'No menu page open'),
  MainMenu UMETA(DisplayName = 'Main Menu'),
  NewGame UMETA(DisplayName = 'New Game'),
  SaveGame UMETA(DisplayName = 'Save Game'),
  LoadGame UMETA(DisplayName = 'Load Game'),
  Options UMETA(DisplayName = 'Options')
};

