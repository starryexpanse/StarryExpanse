//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//

#pragma once

#include "Engine/UserDefinedEnum.h"

UENUM(BlueprintType)
enum class ESaveGameField : uint8 {
  /*
  [[[cog
          import cog
          from rivensavegame_generator import vars, p

          for var in vars:
                  p('%s,' % (var[1],))
  ]]] */
  CurrentLoadGroup,
  CurrentMarionettist,
  CurrentZoomedLinkingBookIsOpen,
  IsGehnTrapped,
  HasTrapBook,
  IsCatherineFreed,
  CharacterTransform,
  ValvePosition,
  IsSelectorValveTowardsPump,
  IsLevelSelectorUp,
  IsHeaterOn,
  IsFullOfWater,
  PlatformRaised,
  PositionAndRotation,
  HasSeenCreepyGirl,
  ElevatorPosition,
  IsOn,
  TimesPressed,
  IsInUnlockedState,
  CodeA,
  CodeB,
  CodeC,
  CodeD,
  CodeE,
  IsInClosedPosition,
  IsStillPassedOut,
  CodeA,
  CodeB,
  CodeC,
  CodeD,
  CodeE,
  IsOpen,
  IsOpen,
  CodeA,
  CodeB,
  CodeC,
  CodeD,
  CodeE,
  // [[[end]]]

};

FString GetSaveGameFieldAsString(ESaveGameField field);