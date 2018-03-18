//
// Copyright, 59 Volt Entertainment, all rights reserved.
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
  A_RivenCharacter_Transform,
  A_Books_CatherinesJournal_IsInPlayerPossession,
  A_Books_CurrentZoomedLinkingBook_IsOpen,
  A_Books_TrapBook_IsInPlayerPossession,
  A_Characters_Catherine_IsFreed,
  A_Characters_Cho_IsStillPassedOut,
  A_Characters_Gehn_IsTrappedInBook,
  A_Characters_Wahrk_TimesBeckoned,
  A_Characters_CatherinesFriend_HasMadeSecondAppearance,
  A_Characters_Scribe_HasBeenSeen,
  A_Characters_JumpscareGirl_HasBeenSeen,
  A_Characters_RecluseWoman_HasBeenSeen,
  A_Characters_TowerGuard_HasBeenSeen,
  A_Characters_FleeingParentAndChild_HaveBeenSeen,
  A_Characters_Sunners_HaveBeenShooed,
  B_Shore_Valve_Position,
  B_BoilerExterior_SelectorValve_IsTowardsPump,
  B_BoilerExterior_LevelSelector_IsUp,
  B_BoilerExterior_Heater_IsOn,
  B_BoilerInterior_Water_IsPresent,
  B_BoilerInterior_Platform_IsRaised,
  J_Basin_Submarine_PositionAndRotation,
  J_Basin_Gallows_IsOpen,
  J_Basin_Treehouse_IsLever1Up,
  J_Basin_Treehouse_IsLever2Up,
  J_Basin_Treehouse_IsLever3Up,
  J_Basin_Treehouse_IsLever4Up,
  J_Basin_Treehouse_IsLever5Up,
  J_Forest_Gate1_IsOpen,
  J_Forest_Gate2_IsOpen,
  J_Forest_WharkIdol_IsMouthOpen,
  J_Forest_WharkIdol_ElevatorPosition,
  J_Forest_GehnsThrone_IsRaised,
  J_Forest_Dome_IsOpen,
  J_Forest_Dome_SliderA,
  J_Forest_Dome_SliderB,
  J_Forest_Dome_SliderC,
  J_Forest_Dome_SliderD,
  J_Forest_Dome_SliderE,
  J_Forest_Ladder_IsLowered,
  J_SecretTunnel_Books_SelectedStoneA,
  J_SecretTunnel_Books_SelectedStoneB,
  J_SecretTunnel_Books_SelectedStoneC,
  J_SecretTunnel_Books_SelectedStoneD,
  J_SecretTunnel_Books_SelectedStoneE,
  J_SecretTunnel_Lights_IsLight1On,
  J_SecretTunnel_Lights_IsLight2On,
  J_SecretTunnel_Lights_IsLight3On,
  J_SecretTunnel_Lights_IsLight4On,
  J_SecretTunnel_Lights_IsLight5On,
  O_Upstairs_Stove_IsOn,
  O_Upstairs_CageButton_TimesPressed,
  O_Upstairs_CageLever_IsUnlocked,
  O_Upstairs_Cannen_IsPlaying,
  O_Bedroom_Drawer_IsOpen,
  S_Dome_CodeA,
  S_Dome_CodeB,
  S_Dome_CodeC,
  S_Dome_CodeD,
  S_Dome_CodeE,
  S_Cart_IsAtJungle,
  S_MaglevTJ_IsSpinnerToRight,
  S_MaglevTJ_IsAtTemple,
  S_MaglevBG_IsSpinnerToRight,
  S_MaglevBG_IsAtSurvey,
  S_MaglevGJ_IsSpinnerToRight,
  S_MaglevGJ_IsAtJungle,
  T_FissurePlateau_CageLever_IsInClosedPosition,
  T_FissurePlateau_Gateroom_Rotation,
  T_FissurePlateau_Gateroom_SelectedBeetle,
  T_FissurePlateau_Telescope_IsBlocked,
  T_FissurePlateau_Telescope_Level,
  T_FissurePlateau_Telescope_CodeA,
  T_FissurePlateau_Telescope_CodeB,
  T_FissurePlateau_Telescope_CodeC,
  T_FissurePlateau_Telescope_CodeD,
  T_FissurePlateau_Telescope_CodeE,
  T_Airlock_OutsideDoor_IsOpen,
  T_Airlock_InsideDoor_IsOpen,
  T_SteamCave_Door_IsOpen,
  T_SteamCave_Valve_IsPoweringTelescope,
  T_SpiderChairRoom_Microphone_IsOn,
  T_NewTemple_DoorMain_IsOpen,
  T_NewTemple_DoorSide_IsOpen,
  T_Backstage_Dome_IsOpen,
  T_Backstage_Dome_SliderA,
  T_Backstage_Dome_SliderB,
  T_Backstage_Dome_SliderC,
  T_Backstage_Dome_SliderD,
  T_Backstage_Dome_SliderE,
  T_Backstage_BridgeValve_IsWastingSteam,
  T_Backstage_BridgeLever_IsUp,
  T_Backstage_Elevator_IsUp,
  T_Backstage_SuperdomeWalkway_IsExtended,
  T_Backstage_WaffleIron_IsEngaged,
  P_Exterior_Elevator_IsInCaptiveMode,
  P_Exterior_Lock_CodeA,
  P_Exterior_Lock_CodeB,
  P_Exterior_Lock_CodeC,
  P_Exterior_Lock_CodeD,
  P_Exterior_Lock_CodeE,
  // [[[end]]]

};

FString GetSaveGameFieldAsString(ESaveGameField field);