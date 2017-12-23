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
  A_LoadGroups_CurrentLoadGroup,
  A_Marionettist_CurrentMarionettist,
  A_Books_CurrentZoomedLinkingBookIsOpen,
  A_Books_IsGehnTrapped,
  A_Books_HasTrapBook,
  A_Books_IsCatherineFreed,
  A_RivenCharacter_CharacterTransform,
  B_Shore_ValvePosition,
  B_BoilerExterior_IsSelectorValveTowardsPump,
  B_BoilerExterior_IsLevelSelectorUp,
  B_BoilerExterior_IsHeaterOn,
  B_BoilerInterior_IsFullOfWater,
  B_BoilerInterior_PlatformRaised,
  J_Submarine_PositionAndRotation,
  J_TunnelBranch_HasSeenCreepyGirl,
  J_IdolInterior_ElevatorPosition,
  O_Stove_IsOn,
  O_CageButton_TimesPressed,
  O_CageLever_IsInUnlockedState,
  S_Dome_CodeA,
  S_Dome_CodeB,
  S_Dome_CodeC,
  S_Dome_CodeD,
  S_Dome_CodeE,
  T_FissurePlateau_CageLever_IsInClosedPosition,
  T_FissurePlateau_Cho_IsStillPassedOut,
  T_FissurePlateau_Telescope_CodeA,
  T_FissurePlateau_Telescope_CodeB,
  T_FissurePlateau_Telescope_CodeC,
  T_FissurePlateau_Telescope_CodeD,
  T_FissurePlateau_Telescope_CodeE,
  T_NewTemple_DoorMain_IsOpen,
  T_NewTemple_DoorSide_IsOpen,
  P_Exterior_Lock_CodeA,
  P_Exterior_Lock_CodeB,
  P_Exterior_Lock_CodeC,
  P_Exterior_Lock_CodeD,
  P_Exterior_Lock_CodeE,
  // [[[end]]]

};

FString GetSaveGameFieldAsString(ESaveGameField field);