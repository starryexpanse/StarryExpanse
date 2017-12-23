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
  A_LoadGroups,
  A_LoadGroupsMarionettist,
  A_LoadGroupsMarionettistBooks,
  A_LoadGroupsMarionettistBooks,
  A_LoadGroupsMarionettistBooks,
  A_LoadGroupsMarionettistBooks,
  A_LoadGroupsMarionettistBooksRivenCharacter,
  B_Shore,
  B_ShoreBoilerExterior,
  B_ShoreBoilerExterior,
  B_ShoreBoilerExterior,
  B_ShoreBoilerExteriorBoilerInterior,
  B_ShoreBoilerExteriorBoilerInterior,
  J_Submarine,
  J_SubmarineTunnelBranch,
  J_SubmarineTunnelBranchIdolInterior,
  O_Stove,
  O_StoveCageButton,
  O_StoveCageButtonCageLever,
  S_Dome,
  S_Dome,
  S_Dome,
  S_Dome,
  S_Dome,
  T_FissurePlateau_CageLever,
  T_FissurePlateau_CageLever_Cho,
  T_FissurePlateau_CageLever_Cho_Telescope,
  T_FissurePlateau_CageLever_Cho_Telescope,
  T_FissurePlateau_CageLever_Cho_Telescope,
  T_FissurePlateau_CageLever_Cho_Telescope,
  T_FissurePlateau_CageLever_Cho_Telescope,
  T_NewTemple_DoorMain,
  T_NewTemple_DoorMain_DoorSide,
  P_Exterior_Lock,
  P_Exterior_Lock,
  P_Exterior_Lock,
  P_Exterior_Lock,
  P_Exterior_Lock,
  // [[[end]]]

};

FString GetSaveGameFieldAsString(ESaveGameField field);