//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#include "SaveGame/RivenSaveGame.h"
#include "RivenGameState.h"
#include "SaveGame/ESaveGameField.h"
#include "StarryExpanse.h"

/* [[[cog
import cog
from rivensavegame_generator import vars as allvars, p

def vars(type):
  vars_of_type = [var for var in allvars if var[0] == type]
  return (vars_of_type, len(vars_of_type))

def wrap(ident):
  return "ESaveGameField::" + ident

def if_check(type):
  vars_of_type, n = vars(type)
  p('if (')
  for i, b in enumerate(vars_of_type):
    last = i == n - 1
    p('fieldName == %s%s' % (wrap(b[1]), ' ||' if not last else ''))
  p(') {')

]]] */
// [[[end]]]

URivenSaveGame::URivenSaveGame(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {
  this->RestoreNewGameDefaults();
}

void URivenSaveGame::Freeze() { this->IsFrozen = true; }

void URivenSaveGame::SetSubscriber(ARivenGameState *NextSubscriber) {
  this->Subscriber = NextSubscriber;
}

bool URivenSaveGame::GetBooleanBySaveGameField(ESaveGameField fieldName) {
  switch (fieldName) {
  /*
  [[[cog
      vars_of_type, n = vars('bool')
      for i, b in enumerate(vars_of_type):
        p('  case %s:' % wrap(b[1]))
        p('    return this->%s;' % (b[1],))
  ]]] */
  case ESaveGameField::A_Books_CatherinesJournal_IsInPlayerPossession:
    return this->A_Books_CatherinesJournal_IsInPlayerPossession;
  case ESaveGameField::A_Books_CurrentZoomedLinkingBook_IsOpen:
    return this->A_Books_CurrentZoomedLinkingBook_IsOpen;
  case ESaveGameField::A_Books_TrapBook_IsInPlayerPossession:
    return this->A_Books_TrapBook_IsInPlayerPossession;
  case ESaveGameField::A_Characters_Catherine_IsFreed:
    return this->A_Characters_Catherine_IsFreed;
  case ESaveGameField::A_Characters_Cho_IsStillPassedOut:
    return this->A_Characters_Cho_IsStillPassedOut;
  case ESaveGameField::A_Characters_Gehn_IsTrappedInBook:
    return this->A_Characters_Gehn_IsTrappedInBook;
  case ESaveGameField::A_Characters_CatherinesFriend_HasMadeSecondAppearance:
    return this->A_Characters_CatherinesFriend_HasMadeSecondAppearance;
  case ESaveGameField::A_Characters_Scribe_HasBeenSeen:
    return this->A_Characters_Scribe_HasBeenSeen;
  case ESaveGameField::A_Characters_JumpscareGirl_HasBeenSeen:
    return this->A_Characters_JumpscareGirl_HasBeenSeen;
  case ESaveGameField::A_Characters_RecluseWoman_HasBeenSeen:
    return this->A_Characters_RecluseWoman_HasBeenSeen;
  case ESaveGameField::A_Characters_TowerGuard_HasBeenSeen:
    return this->A_Characters_TowerGuard_HasBeenSeen;
  case ESaveGameField::A_Characters_FleeingParentAndChild_HaveBeenSeen:
    return this->A_Characters_FleeingParentAndChild_HaveBeenSeen;
  case ESaveGameField::A_Characters_Sunners_HaveBeenShooed:
    return this->A_Characters_Sunners_HaveBeenShooed;
  case ESaveGameField::B_BoilerExterior_SelectorValve_IsTowardsPump:
    return this->B_BoilerExterior_SelectorValve_IsTowardsPump;
  case ESaveGameField::B_BoilerExterior_LevelSelector_IsUp:
    return this->B_BoilerExterior_LevelSelector_IsUp;
  case ESaveGameField::B_BoilerExterior_Heater_IsOn:
    return this->B_BoilerExterior_Heater_IsOn;
  case ESaveGameField::B_BoilerInterior_Water_IsPresent:
    return this->B_BoilerInterior_Water_IsPresent;
  case ESaveGameField::B_BoilerInterior_Platform_IsRaised:
    return this->B_BoilerInterior_Platform_IsRaised;
  case ESaveGameField::J_Basin_Gallows_IsOpen:
    return this->J_Basin_Gallows_IsOpen;
  case ESaveGameField::J_Basin_Treehouse_IsLever1Up:
    return this->J_Basin_Treehouse_IsLever1Up;
  case ESaveGameField::J_Basin_Treehouse_IsLever2Up:
    return this->J_Basin_Treehouse_IsLever2Up;
  case ESaveGameField::J_Basin_Treehouse_IsLever3Up:
    return this->J_Basin_Treehouse_IsLever3Up;
  case ESaveGameField::J_Basin_Treehouse_IsLever4Up:
    return this->J_Basin_Treehouse_IsLever4Up;
  case ESaveGameField::J_Basin_Treehouse_IsLever5Up:
    return this->J_Basin_Treehouse_IsLever5Up;
  case ESaveGameField::J_Forest_Gate1_IsOpen:
    return this->J_Forest_Gate1_IsOpen;
  case ESaveGameField::J_Forest_Gate2_IsOpen:
    return this->J_Forest_Gate2_IsOpen;
  case ESaveGameField::J_Forest_WharkIdol_IsMouthOpen:
    return this->J_Forest_WharkIdol_IsMouthOpen;
  case ESaveGameField::J_Forest_GehnsThrone_IsRaised:
    return this->J_Forest_GehnsThrone_IsRaised;
  case ESaveGameField::J_Forest_Dome_IsOpen:
    return this->J_Forest_Dome_IsOpen;
  case ESaveGameField::J_Forest_Ladder_IsLowered:
    return this->J_Forest_Ladder_IsLowered;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight1On:
    return this->J_SecretTunnel_Lights_IsLight1On;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight2On:
    return this->J_SecretTunnel_Lights_IsLight2On;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight3On:
    return this->J_SecretTunnel_Lights_IsLight3On;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight4On:
    return this->J_SecretTunnel_Lights_IsLight4On;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight5On:
    return this->J_SecretTunnel_Lights_IsLight5On;
  case ESaveGameField::O_Upstairs_Stove_IsOn:
    return this->O_Upstairs_Stove_IsOn;
  case ESaveGameField::O_Upstairs_CageLever_IsUnlocked:
    return this->O_Upstairs_CageLever_IsUnlocked;
  case ESaveGameField::O_Upstairs_Cannen_IsPlaying:
    return this->O_Upstairs_Cannen_IsPlaying;
  case ESaveGameField::O_Bedroom_Drawer_IsOpen:
    return this->O_Bedroom_Drawer_IsOpen;
  case ESaveGameField::S_Cart_IsAtJungle:
    return this->S_Cart_IsAtJungle;
  case ESaveGameField::S_MaglevTJ_IsSpinnerToRight:
    return this->S_MaglevTJ_IsSpinnerToRight;
  case ESaveGameField::S_MaglevTJ_IsAtTemple:
    return this->S_MaglevTJ_IsAtTemple;
  case ESaveGameField::S_MaglevBG_IsSpinnerToRight:
    return this->S_MaglevBG_IsSpinnerToRight;
  case ESaveGameField::S_MaglevBG_IsAtSurvey:
    return this->S_MaglevBG_IsAtSurvey;
  case ESaveGameField::S_MaglevGJ_IsSpinnerToRight:
    return this->S_MaglevGJ_IsSpinnerToRight;
  case ESaveGameField::S_MaglevGJ_IsAtJungle:
    return this->S_MaglevGJ_IsAtJungle;
  case ESaveGameField::T_FissurePlateau_CageLever_IsInClosedPosition:
    return this->T_FissurePlateau_CageLever_IsInClosedPosition;
  case ESaveGameField::T_FissurePlateau_Telescope_IsBlocked:
    return this->T_FissurePlateau_Telescope_IsBlocked;
  case ESaveGameField::T_Airlock_OutsideDoor_IsOpen:
    return this->T_Airlock_OutsideDoor_IsOpen;
  case ESaveGameField::T_Airlock_InsideDoor_IsOpen:
    return this->T_Airlock_InsideDoor_IsOpen;
  case ESaveGameField::T_SteamCave_Door_IsOpen:
    return this->T_SteamCave_Door_IsOpen;
  case ESaveGameField::T_SteamCave_Valve_IsPoweringTelescope:
    return this->T_SteamCave_Valve_IsPoweringTelescope;
  case ESaveGameField::T_SpiderChairRoom_Microphone_IsOn:
    return this->T_SpiderChairRoom_Microphone_IsOn;
  case ESaveGameField::T_NewTemple_DoorMain_IsOpen:
    return this->T_NewTemple_DoorMain_IsOpen;
  case ESaveGameField::T_NewTemple_DoorSide_IsOpen:
    return this->T_NewTemple_DoorSide_IsOpen;
  case ESaveGameField::T_Backstage_Dome_IsOpen:
    return this->T_Backstage_Dome_IsOpen;
  case ESaveGameField::T_Backstage_BridgeValve_IsWastingSteam:
    return this->T_Backstage_BridgeValve_IsWastingSteam;
  case ESaveGameField::T_Backstage_BridgeLever_IsUp:
    return this->T_Backstage_BridgeLever_IsUp;
  case ESaveGameField::T_Backstage_Elevator_IsUp:
    return this->T_Backstage_Elevator_IsUp;
  case ESaveGameField::T_Backstage_SuperdomeWalkway_IsExtended:
    return this->T_Backstage_SuperdomeWalkway_IsExtended;
  case ESaveGameField::T_Backstage_WaffleIron_IsEngaged:
    return this->T_Backstage_WaffleIron_IsEngaged;
  case ESaveGameField::P_Exterior_Elevator_IsInCaptiveMode:
    return this->P_Exterior_Elevator_IsInCaptiveMode;
  // [[[end]]]
  default:
    UE_LOG(StarryDebug, Error, TEXT("%s is not a boolean."),
           *GetSaveGameFieldAsString(fieldName));
    return false;
  }
}

void URivenSaveGame::SetBooleanBySaveGameField(ESaveGameField fieldName,
                                               bool nextVal) {
  switch (fieldName) {
  /*
  [[[cog

  vars_of_type, n = vars('bool')
  for i, b in enumerate(vars_of_type):
    p('    case %s:' % wrap(b[1]))
    p('      this->Set_%s(nextVal);' % b[1])
    p('      break;')

  ]]] */
  case ESaveGameField::A_Books_CatherinesJournal_IsInPlayerPossession:
    this->Set_A_Books_CatherinesJournal_IsInPlayerPossession(nextVal);
    break;
  case ESaveGameField::A_Books_CurrentZoomedLinkingBook_IsOpen:
    this->Set_A_Books_CurrentZoomedLinkingBook_IsOpen(nextVal);
    break;
  case ESaveGameField::A_Books_TrapBook_IsInPlayerPossession:
    this->Set_A_Books_TrapBook_IsInPlayerPossession(nextVal);
    break;
  case ESaveGameField::A_Characters_Catherine_IsFreed:
    this->Set_A_Characters_Catherine_IsFreed(nextVal);
    break;
  case ESaveGameField::A_Characters_Cho_IsStillPassedOut:
    this->Set_A_Characters_Cho_IsStillPassedOut(nextVal);
    break;
  case ESaveGameField::A_Characters_Gehn_IsTrappedInBook:
    this->Set_A_Characters_Gehn_IsTrappedInBook(nextVal);
    break;
  case ESaveGameField::A_Characters_CatherinesFriend_HasMadeSecondAppearance:
    this->Set_A_Characters_CatherinesFriend_HasMadeSecondAppearance(nextVal);
    break;
  case ESaveGameField::A_Characters_Scribe_HasBeenSeen:
    this->Set_A_Characters_Scribe_HasBeenSeen(nextVal);
    break;
  case ESaveGameField::A_Characters_JumpscareGirl_HasBeenSeen:
    this->Set_A_Characters_JumpscareGirl_HasBeenSeen(nextVal);
    break;
  case ESaveGameField::A_Characters_RecluseWoman_HasBeenSeen:
    this->Set_A_Characters_RecluseWoman_HasBeenSeen(nextVal);
    break;
  case ESaveGameField::A_Characters_TowerGuard_HasBeenSeen:
    this->Set_A_Characters_TowerGuard_HasBeenSeen(nextVal);
    break;
  case ESaveGameField::A_Characters_FleeingParentAndChild_HaveBeenSeen:
    this->Set_A_Characters_FleeingParentAndChild_HaveBeenSeen(nextVal);
    break;
  case ESaveGameField::A_Characters_Sunners_HaveBeenShooed:
    this->Set_A_Characters_Sunners_HaveBeenShooed(nextVal);
    break;
  case ESaveGameField::B_BoilerExterior_SelectorValve_IsTowardsPump:
    this->Set_B_BoilerExterior_SelectorValve_IsTowardsPump(nextVal);
    break;
  case ESaveGameField::B_BoilerExterior_LevelSelector_IsUp:
    this->Set_B_BoilerExterior_LevelSelector_IsUp(nextVal);
    break;
  case ESaveGameField::B_BoilerExterior_Heater_IsOn:
    this->Set_B_BoilerExterior_Heater_IsOn(nextVal);
    break;
  case ESaveGameField::B_BoilerInterior_Water_IsPresent:
    this->Set_B_BoilerInterior_Water_IsPresent(nextVal);
    break;
  case ESaveGameField::B_BoilerInterior_Platform_IsRaised:
    this->Set_B_BoilerInterior_Platform_IsRaised(nextVal);
    break;
  case ESaveGameField::J_Basin_Gallows_IsOpen:
    this->Set_J_Basin_Gallows_IsOpen(nextVal);
    break;
  case ESaveGameField::J_Basin_Treehouse_IsLever1Up:
    this->Set_J_Basin_Treehouse_IsLever1Up(nextVal);
    break;
  case ESaveGameField::J_Basin_Treehouse_IsLever2Up:
    this->Set_J_Basin_Treehouse_IsLever2Up(nextVal);
    break;
  case ESaveGameField::J_Basin_Treehouse_IsLever3Up:
    this->Set_J_Basin_Treehouse_IsLever3Up(nextVal);
    break;
  case ESaveGameField::J_Basin_Treehouse_IsLever4Up:
    this->Set_J_Basin_Treehouse_IsLever4Up(nextVal);
    break;
  case ESaveGameField::J_Basin_Treehouse_IsLever5Up:
    this->Set_J_Basin_Treehouse_IsLever5Up(nextVal);
    break;
  case ESaveGameField::J_Forest_Gate1_IsOpen:
    this->Set_J_Forest_Gate1_IsOpen(nextVal);
    break;
  case ESaveGameField::J_Forest_Gate2_IsOpen:
    this->Set_J_Forest_Gate2_IsOpen(nextVal);
    break;
  case ESaveGameField::J_Forest_WharkIdol_IsMouthOpen:
    this->Set_J_Forest_WharkIdol_IsMouthOpen(nextVal);
    break;
  case ESaveGameField::J_Forest_GehnsThrone_IsRaised:
    this->Set_J_Forest_GehnsThrone_IsRaised(nextVal);
    break;
  case ESaveGameField::J_Forest_Dome_IsOpen:
    this->Set_J_Forest_Dome_IsOpen(nextVal);
    break;
  case ESaveGameField::J_Forest_Ladder_IsLowered:
    this->Set_J_Forest_Ladder_IsLowered(nextVal);
    break;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight1On:
    this->Set_J_SecretTunnel_Lights_IsLight1On(nextVal);
    break;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight2On:
    this->Set_J_SecretTunnel_Lights_IsLight2On(nextVal);
    break;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight3On:
    this->Set_J_SecretTunnel_Lights_IsLight3On(nextVal);
    break;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight4On:
    this->Set_J_SecretTunnel_Lights_IsLight4On(nextVal);
    break;
  case ESaveGameField::J_SecretTunnel_Lights_IsLight5On:
    this->Set_J_SecretTunnel_Lights_IsLight5On(nextVal);
    break;
  case ESaveGameField::O_Upstairs_Stove_IsOn:
    this->Set_O_Upstairs_Stove_IsOn(nextVal);
    break;
  case ESaveGameField::O_Upstairs_CageLever_IsUnlocked:
    this->Set_O_Upstairs_CageLever_IsUnlocked(nextVal);
    break;
  case ESaveGameField::O_Upstairs_Cannen_IsPlaying:
    this->Set_O_Upstairs_Cannen_IsPlaying(nextVal);
    break;
  case ESaveGameField::O_Bedroom_Drawer_IsOpen:
    this->Set_O_Bedroom_Drawer_IsOpen(nextVal);
    break;
  case ESaveGameField::S_Cart_IsAtJungle:
    this->Set_S_Cart_IsAtJungle(nextVal);
    break;
  case ESaveGameField::S_MaglevTJ_IsSpinnerToRight:
    this->Set_S_MaglevTJ_IsSpinnerToRight(nextVal);
    break;
  case ESaveGameField::S_MaglevTJ_IsAtTemple:
    this->Set_S_MaglevTJ_IsAtTemple(nextVal);
    break;
  case ESaveGameField::S_MaglevBG_IsSpinnerToRight:
    this->Set_S_MaglevBG_IsSpinnerToRight(nextVal);
    break;
  case ESaveGameField::S_MaglevBG_IsAtSurvey:
    this->Set_S_MaglevBG_IsAtSurvey(nextVal);
    break;
  case ESaveGameField::S_MaglevGJ_IsSpinnerToRight:
    this->Set_S_MaglevGJ_IsSpinnerToRight(nextVal);
    break;
  case ESaveGameField::S_MaglevGJ_IsAtJungle:
    this->Set_S_MaglevGJ_IsAtJungle(nextVal);
    break;
  case ESaveGameField::T_FissurePlateau_CageLever_IsInClosedPosition:
    this->Set_T_FissurePlateau_CageLever_IsInClosedPosition(nextVal);
    break;
  case ESaveGameField::T_FissurePlateau_Telescope_IsBlocked:
    this->Set_T_FissurePlateau_Telescope_IsBlocked(nextVal);
    break;
  case ESaveGameField::T_Airlock_OutsideDoor_IsOpen:
    this->Set_T_Airlock_OutsideDoor_IsOpen(nextVal);
    break;
  case ESaveGameField::T_Airlock_InsideDoor_IsOpen:
    this->Set_T_Airlock_InsideDoor_IsOpen(nextVal);
    break;
  case ESaveGameField::T_SteamCave_Door_IsOpen:
    this->Set_T_SteamCave_Door_IsOpen(nextVal);
    break;
  case ESaveGameField::T_SteamCave_Valve_IsPoweringTelescope:
    this->Set_T_SteamCave_Valve_IsPoweringTelescope(nextVal);
    break;
  case ESaveGameField::T_SpiderChairRoom_Microphone_IsOn:
    this->Set_T_SpiderChairRoom_Microphone_IsOn(nextVal);
    break;
  case ESaveGameField::T_NewTemple_DoorMain_IsOpen:
    this->Set_T_NewTemple_DoorMain_IsOpen(nextVal);
    break;
  case ESaveGameField::T_NewTemple_DoorSide_IsOpen:
    this->Set_T_NewTemple_DoorSide_IsOpen(nextVal);
    break;
  case ESaveGameField::T_Backstage_Dome_IsOpen:
    this->Set_T_Backstage_Dome_IsOpen(nextVal);
    break;
  case ESaveGameField::T_Backstage_BridgeValve_IsWastingSteam:
    this->Set_T_Backstage_BridgeValve_IsWastingSteam(nextVal);
    break;
  case ESaveGameField::T_Backstage_BridgeLever_IsUp:
    this->Set_T_Backstage_BridgeLever_IsUp(nextVal);
    break;
  case ESaveGameField::T_Backstage_Elevator_IsUp:
    this->Set_T_Backstage_Elevator_IsUp(nextVal);
    break;
  case ESaveGameField::T_Backstage_SuperdomeWalkway_IsExtended:
    this->Set_T_Backstage_SuperdomeWalkway_IsExtended(nextVal);
    break;
  case ESaveGameField::T_Backstage_WaffleIron_IsEngaged:
    this->Set_T_Backstage_WaffleIron_IsEngaged(nextVal);
    break;
  case ESaveGameField::P_Exterior_Elevator_IsInCaptiveMode:
    this->Set_P_Exterior_Elevator_IsInCaptiveMode(nextVal);
    break;
  // [[[end]]]
  default:
    UE_LOG(StarryDebug, Error, TEXT("%s is not a boolean."),
           *GetSaveGameFieldAsString(fieldName));
  }
}

void URivenSaveGame::RestoreNewGameDefaults() {
  /*
  [[[cog
     import cog
     from rivensavegame_generator import vars, p

     for var in vars:
        p('this->%s = %s;' % (var[1], var[2]))
  ]]] */
  this->A_LoadGroups_CurrentLoadGroup = ELoadGroups::TFissureDistrict;
  this->A_Marionettist_CurrentMarionettist = EMarionettist::NoMarionettist;
  this->A_RivenCharacter_Transform = FTransform::Identity;
  this->A_Books_CatherinesJournal_IsInPlayerPossession = false;
  this->A_Books_CurrentZoomedLinkingBook_IsOpen = false;
  this->A_Books_TrapBook_IsInPlayerPossession = true;
  this->A_Characters_Catherine_IsFreed = false;
  this->A_Characters_Cho_IsStillPassedOut = true;
  this->A_Characters_Gehn_IsTrappedInBook = false;
  this->A_Characters_Wahrk_TimesBeckoned = 0;
  this->A_Characters_CatherinesFriend_HasMadeSecondAppearance = false;
  this->A_Characters_Scribe_HasBeenSeen = false;
  this->A_Characters_JumpscareGirl_HasBeenSeen = false;
  this->A_Characters_RecluseWoman_HasBeenSeen = false;
  this->A_Characters_TowerGuard_HasBeenSeen = false;
  this->A_Characters_FleeingParentAndChild_HaveBeenSeen = false;
  this->A_Characters_Sunners_HaveBeenShooed = false;
  this->B_Shore_Valve_Position = 0;
  this->B_BoilerExterior_SelectorValve_IsTowardsPump = false;
  this->B_BoilerExterior_LevelSelector_IsUp = false;
  this->B_BoilerExterior_Heater_IsOn = false;
  this->B_BoilerInterior_Water_IsPresent = true;
  this->B_BoilerInterior_Platform_IsRaised = false;
  this->J_Basin_Submarine_PositionAndRotation = ESubPosRot::Plat_N;
  this->J_Basin_Gallows_IsOpen = false;
  this->J_Basin_Treehouse_IsLever1Up = false;
  this->J_Basin_Treehouse_IsLever2Up = false;
  this->J_Basin_Treehouse_IsLever3Up = false;
  this->J_Basin_Treehouse_IsLever4Up = false;
  this->J_Basin_Treehouse_IsLever5Up = false;
  this->J_Forest_Gate1_IsOpen = false;
  this->J_Forest_Gate2_IsOpen = false;
  this->J_Forest_WharkIdol_IsMouthOpen = false;
  this->J_Forest_WharkIdol_ElevatorPosition = 1;
  this->J_Forest_GehnsThrone_IsRaised = false;
  this->J_Forest_Dome_IsOpen = false;
  this->J_Forest_Dome_SliderA = 0;
  this->J_Forest_Dome_SliderB = 1;
  this->J_Forest_Dome_SliderC = 2;
  this->J_Forest_Dome_SliderD = 3;
  this->J_Forest_Dome_SliderE = 4;
  this->J_Forest_Ladder_IsLowered = false;
  this->J_SecretTunnel_Books_SelectedStoneA = -1;
  this->J_SecretTunnel_Books_SelectedStoneB = -1;
  this->J_SecretTunnel_Books_SelectedStoneC = -1;
  this->J_SecretTunnel_Books_SelectedStoneD = -1;
  this->J_SecretTunnel_Books_SelectedStoneE = -1;
  this->J_SecretTunnel_Lights_IsLight1On = false;
  this->J_SecretTunnel_Lights_IsLight2On = false;
  this->J_SecretTunnel_Lights_IsLight3On = false;
  this->J_SecretTunnel_Lights_IsLight4On = false;
  this->J_SecretTunnel_Lights_IsLight5On = false;
  this->O_Upstairs_Stove_IsOn = false;
  this->O_Upstairs_CageButton_TimesPressed = 0;
  this->O_Upstairs_CageLever_IsUnlocked = false;
  this->O_Upstairs_Cannen_IsPlaying = false;
  this->O_Bedroom_Drawer_IsOpen = false;
  this->S_Dome_CodeA = -1;
  this->S_Dome_CodeB = -1;
  this->S_Dome_CodeC = -1;
  this->S_Dome_CodeD = -1;
  this->S_Dome_CodeE = -1;
  this->S_Cart_IsAtJungle = true;
  this->S_MaglevTJ_IsSpinnerToRight = false;
  this->S_MaglevTJ_IsAtTemple = false;
  this->S_MaglevBG_IsSpinnerToRight = false;
  this->S_MaglevBG_IsAtSurvey = true;
  this->S_MaglevGJ_IsSpinnerToRight = false;
  this->S_MaglevGJ_IsAtJungle = false;
  this->T_FissurePlateau_CageLever_IsInClosedPosition = true;
  this->T_FissurePlateau_Gateroom_Rotation = 0;
  this->T_FissurePlateau_Gateroom_SelectedBeetle = -1;
  this->T_FissurePlateau_Telescope_IsBlocked = true;
  this->T_FissurePlateau_Telescope_Level = 4;
  this->T_FissurePlateau_Telescope_CodeA = -1;
  this->T_FissurePlateau_Telescope_CodeB = -1;
  this->T_FissurePlateau_Telescope_CodeC = -1;
  this->T_FissurePlateau_Telescope_CodeD = -1;
  this->T_FissurePlateau_Telescope_CodeE = -1;
  this->T_Airlock_OutsideDoor_IsOpen = false;
  this->T_Airlock_InsideDoor_IsOpen = false;
  this->T_SteamCave_Door_IsOpen = false;
  this->T_SteamCave_Valve_IsPoweringTelescope = false;
  this->T_SpiderChairRoom_Microphone_IsOn = false;
  this->T_NewTemple_DoorMain_IsOpen = false;
  this->T_NewTemple_DoorSide_IsOpen = false;
  this->T_Backstage_Dome_IsOpen = false;
  this->T_Backstage_Dome_SliderA = 0;
  this->T_Backstage_Dome_SliderB = 1;
  this->T_Backstage_Dome_SliderC = 2;
  this->T_Backstage_Dome_SliderD = 3;
  this->T_Backstage_Dome_SliderE = 4;
  this->T_Backstage_BridgeValve_IsWastingSteam = true;
  this->T_Backstage_BridgeLever_IsUp = true;
  this->T_Backstage_Elevator_IsUp = false;
  this->T_Backstage_SuperdomeWalkway_IsExtended = false;
  this->T_Backstage_WaffleIron_IsEngaged = false;
  this->P_Exterior_Elevator_IsInCaptiveMode = true;
  this->P_Exterior_Lock_CodeA = -1;
  this->P_Exterior_Lock_CodeB = -1;
  this->P_Exterior_Lock_CodeC = -1;
  this->P_Exterior_Lock_CodeD = -1;
  this->P_Exterior_Lock_CodeE = -1;
  /* [[[end]]]*/

  this->T_FissurePlateau_Telescope_CodeA = FMath::RandRange(0, 4);
  this->T_FissurePlateau_Telescope_CodeB = FMath::RandRange(0, 4);
  this->T_FissurePlateau_Telescope_CodeC = FMath::RandRange(0, 4);
  this->T_FissurePlateau_Telescope_CodeD = FMath::RandRange(0, 4);
  this->T_FissurePlateau_Telescope_CodeE = FMath::RandRange(0, 4);

  // Generate dome code. I tried a more constant-time way but it had pretty
  // uneven distributions. There's another way to accomplish the same task in
  // constant time, but this is simple.
  {
    TArray<int> DomeCode;

    bool slots[25];
    for (int i = 0; i < 25; i++) {
      slots[i] = 0;
    }

    int hits = 0;
    while (hits < 5) {
      int dartShot = FMath::RandRange(0, 25);
      if (!slots[dartShot]) {
        slots[dartShot] = true;
        DomeCode.Add(dartShot);
        hits++;
      }
    }

    DomeCode.Sort();

    this->S_Dome_CodeA = DomeCode[0];
    this->S_Dome_CodeB = DomeCode[1];
    this->S_Dome_CodeC = DomeCode[2];
    this->S_Dome_CodeD = DomeCode[3];
    this->S_Dome_CodeE = DomeCode[4];
  }
}

std::vector<std::tuple<std::string, std::string>>
URivenSaveGame::GetSavegameFields() {
  std::vector<std::tuple<std::string, std::string>> vars;

  /*[[[cog
    def wrap(text):
      return '"%s"' % text.replace("\"", "\\\"")

    for var in vars:
      p('vars.push_back(std::make_tuple(%s, %s));' % (
        wrap(var[0]),
        wrap(var[1])
      ))
  ]]] */
  vars.push_back(std::make_tuple("ELoadGroups", "A_LoadGroups_CurrentLoadGroup"));
  vars.push_back(std::make_tuple("EMarionettist", "A_Marionettist_CurrentMarionettist"));
  vars.push_back(std::make_tuple("FTransform", "A_RivenCharacter_Transform"));
  vars.push_back(std::make_tuple("bool", "A_Books_CatherinesJournal_IsInPlayerPossession"));
  vars.push_back(std::make_tuple("bool", "A_Books_CurrentZoomedLinkingBook_IsOpen"));
  vars.push_back(std::make_tuple("bool", "A_Books_TrapBook_IsInPlayerPossession"));
  vars.push_back(std::make_tuple("bool", "A_Characters_Catherine_IsFreed"));
  vars.push_back(std::make_tuple("bool", "A_Characters_Cho_IsStillPassedOut"));
  vars.push_back(std::make_tuple("bool", "A_Characters_Gehn_IsTrappedInBook"));
  vars.push_back(std::make_tuple("int32", "A_Characters_Wahrk_TimesBeckoned"));
  vars.push_back(std::make_tuple("bool", "A_Characters_CatherinesFriend_HasMadeSecondAppearance"));
  vars.push_back(std::make_tuple("bool", "A_Characters_Scribe_HasBeenSeen"));
  vars.push_back(std::make_tuple("bool", "A_Characters_JumpscareGirl_HasBeenSeen"));
  vars.push_back(std::make_tuple("bool", "A_Characters_RecluseWoman_HasBeenSeen"));
  vars.push_back(std::make_tuple("bool", "A_Characters_TowerGuard_HasBeenSeen"));
  vars.push_back(std::make_tuple("bool", "A_Characters_FleeingParentAndChild_HaveBeenSeen"));
  vars.push_back(std::make_tuple("bool", "A_Characters_Sunners_HaveBeenShooed"));
  vars.push_back(std::make_tuple("int32", "B_Shore_Valve_Position"));
  vars.push_back(std::make_tuple("bool", "B_BoilerExterior_SelectorValve_IsTowardsPump"));
  vars.push_back(std::make_tuple("bool", "B_BoilerExterior_LevelSelector_IsUp"));
  vars.push_back(std::make_tuple("bool", "B_BoilerExterior_Heater_IsOn"));
  vars.push_back(std::make_tuple("bool", "B_BoilerInterior_Water_IsPresent"));
  vars.push_back(std::make_tuple("bool", "B_BoilerInterior_Platform_IsRaised"));
  vars.push_back(std::make_tuple("ESubPosRot", "J_Basin_Submarine_PositionAndRotation"));
  vars.push_back(std::make_tuple("bool", "J_Basin_Gallows_IsOpen"));
  vars.push_back(std::make_tuple("bool", "J_Basin_Treehouse_IsLever1Up"));
  vars.push_back(std::make_tuple("bool", "J_Basin_Treehouse_IsLever2Up"));
  vars.push_back(std::make_tuple("bool", "J_Basin_Treehouse_IsLever3Up"));
  vars.push_back(std::make_tuple("bool", "J_Basin_Treehouse_IsLever4Up"));
  vars.push_back(std::make_tuple("bool", "J_Basin_Treehouse_IsLever5Up"));
  vars.push_back(std::make_tuple("bool", "J_Forest_Gate1_IsOpen"));
  vars.push_back(std::make_tuple("bool", "J_Forest_Gate2_IsOpen"));
  vars.push_back(std::make_tuple("bool", "J_Forest_WharkIdol_IsMouthOpen"));
  vars.push_back(std::make_tuple("int32", "J_Forest_WharkIdol_ElevatorPosition"));
  vars.push_back(std::make_tuple("bool", "J_Forest_GehnsThrone_IsRaised"));
  vars.push_back(std::make_tuple("bool", "J_Forest_Dome_IsOpen"));
  vars.push_back(std::make_tuple("int32", "J_Forest_Dome_SliderA"));
  vars.push_back(std::make_tuple("int32", "J_Forest_Dome_SliderB"));
  vars.push_back(std::make_tuple("int32", "J_Forest_Dome_SliderC"));
  vars.push_back(std::make_tuple("int32", "J_Forest_Dome_SliderD"));
  vars.push_back(std::make_tuple("int32", "J_Forest_Dome_SliderE"));
  vars.push_back(std::make_tuple("bool", "J_Forest_Ladder_IsLowered"));
  vars.push_back(std::make_tuple("int32", "J_SecretTunnel_Books_SelectedStoneA"));
  vars.push_back(std::make_tuple("int32", "J_SecretTunnel_Books_SelectedStoneB"));
  vars.push_back(std::make_tuple("int32", "J_SecretTunnel_Books_SelectedStoneC"));
  vars.push_back(std::make_tuple("int32", "J_SecretTunnel_Books_SelectedStoneD"));
  vars.push_back(std::make_tuple("int32", "J_SecretTunnel_Books_SelectedStoneE"));
  vars.push_back(std::make_tuple("bool", "J_SecretTunnel_Lights_IsLight1On"));
  vars.push_back(std::make_tuple("bool", "J_SecretTunnel_Lights_IsLight2On"));
  vars.push_back(std::make_tuple("bool", "J_SecretTunnel_Lights_IsLight3On"));
  vars.push_back(std::make_tuple("bool", "J_SecretTunnel_Lights_IsLight4On"));
  vars.push_back(std::make_tuple("bool", "J_SecretTunnel_Lights_IsLight5On"));
  vars.push_back(std::make_tuple("bool", "O_Upstairs_Stove_IsOn"));
  vars.push_back(std::make_tuple("int32", "O_Upstairs_CageButton_TimesPressed"));
  vars.push_back(std::make_tuple("bool", "O_Upstairs_CageLever_IsUnlocked"));
  vars.push_back(std::make_tuple("bool", "O_Upstairs_Cannen_IsPlaying"));
  vars.push_back(std::make_tuple("bool", "O_Bedroom_Drawer_IsOpen"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeA"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeB"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeC"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeD"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeE"));
  vars.push_back(std::make_tuple("bool", "S_Cart_IsAtJungle"));
  vars.push_back(std::make_tuple("bool", "S_MaglevTJ_IsSpinnerToRight"));
  vars.push_back(std::make_tuple("bool", "S_MaglevTJ_IsAtTemple"));
  vars.push_back(std::make_tuple("bool", "S_MaglevBG_IsSpinnerToRight"));
  vars.push_back(std::make_tuple("bool", "S_MaglevBG_IsAtSurvey"));
  vars.push_back(std::make_tuple("bool", "S_MaglevGJ_IsSpinnerToRight"));
  vars.push_back(std::make_tuple("bool", "S_MaglevGJ_IsAtJungle"));
  vars.push_back(std::make_tuple("bool", "T_FissurePlateau_CageLever_IsInClosedPosition"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Gateroom_Rotation"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Gateroom_SelectedBeetle"));
  vars.push_back(std::make_tuple("bool", "T_FissurePlateau_Telescope_IsBlocked"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_Level"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeA"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeB"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeC"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeD"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeE"));
  vars.push_back(std::make_tuple("bool", "T_Airlock_OutsideDoor_IsOpen"));
  vars.push_back(std::make_tuple("bool", "T_Airlock_InsideDoor_IsOpen"));
  vars.push_back(std::make_tuple("bool", "T_SteamCave_Door_IsOpen"));
  vars.push_back(std::make_tuple("bool", "T_SteamCave_Valve_IsPoweringTelescope"));
  vars.push_back(std::make_tuple("bool", "T_SpiderChairRoom_Microphone_IsOn"));
  vars.push_back(std::make_tuple("bool", "T_NewTemple_DoorMain_IsOpen"));
  vars.push_back(std::make_tuple("bool", "T_NewTemple_DoorSide_IsOpen"));
  vars.push_back(std::make_tuple("bool", "T_Backstage_Dome_IsOpen"));
  vars.push_back(std::make_tuple("int32", "T_Backstage_Dome_SliderA"));
  vars.push_back(std::make_tuple("int32", "T_Backstage_Dome_SliderB"));
  vars.push_back(std::make_tuple("int32", "T_Backstage_Dome_SliderC"));
  vars.push_back(std::make_tuple("int32", "T_Backstage_Dome_SliderD"));
  vars.push_back(std::make_tuple("int32", "T_Backstage_Dome_SliderE"));
  vars.push_back(std::make_tuple("bool", "T_Backstage_BridgeValve_IsWastingSteam"));
  vars.push_back(std::make_tuple("bool", "T_Backstage_BridgeLever_IsUp"));
  vars.push_back(std::make_tuple("bool", "T_Backstage_Elevator_IsUp"));
  vars.push_back(std::make_tuple("bool", "T_Backstage_SuperdomeWalkway_IsExtended"));
  vars.push_back(std::make_tuple("bool", "T_Backstage_WaffleIron_IsEngaged"));
  vars.push_back(std::make_tuple("bool", "P_Exterior_Elevator_IsInCaptiveMode"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeA"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeB"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeC"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeD"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeE"));
  /* [[[end]]]*/

  return vars;
}

/*
 * [[[cog
   import cog
   from rivensavegame_generator import vars, p

   too_expensive_for_comparison = ['FTransform']

   for var in vars:
      # Setters
      p("UFUNCTION(BlueprintCallable, Category = SaveGame)")
      p("void URivenSaveGame::Set_%s(%s NewVal) {" % (var[1], var[0]))
      p("   if (IsFrozen) return;")
      p("   %s OrigVal = this->%s;" % (var[0], var[1]))
      skip_comparison = var[0] in too_expensive_for_comparison
      p("   if (%s) {" % ('true' if skip_comparison else 'OrigVal != NewVal',))
      p("     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);")
      p("     OldSaveGame->Freeze();")
      p("     this->%s = NewVal;" % var[1])
      p("     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);")
      p("   }")
      p("}")
      p("")
      p("")

      # Getters
      p("UFUNCTION(BlueprintCallable, Category = SaveGame)")
      p("%s URivenSaveGame::Get_%s() {" % (var[0], var[1]))
      p("   return %s;" % var[1])
      p("}")
      p("")

]]] */
UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_LoadGroups_CurrentLoadGroup(ELoadGroups NewVal) {
   if (IsFrozen) return;
   ELoadGroups OrigVal = this->A_LoadGroups_CurrentLoadGroup;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_LoadGroups_CurrentLoadGroup = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
ELoadGroups URivenSaveGame::Get_A_LoadGroups_CurrentLoadGroup() {
   return A_LoadGroups_CurrentLoadGroup;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Marionettist_CurrentMarionettist(EMarionettist NewVal) {
   if (IsFrozen) return;
   EMarionettist OrigVal = this->A_Marionettist_CurrentMarionettist;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Marionettist_CurrentMarionettist = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
EMarionettist URivenSaveGame::Get_A_Marionettist_CurrentMarionettist() {
   return A_Marionettist_CurrentMarionettist;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_RivenCharacter_Transform(FTransform NewVal) {
   if (IsFrozen) return;
   FTransform OrigVal = this->A_RivenCharacter_Transform;
   if (true) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_RivenCharacter_Transform = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
FTransform URivenSaveGame::Get_A_RivenCharacter_Transform() {
   return A_RivenCharacter_Transform;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Books_CatherinesJournal_IsInPlayerPossession(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Books_CatherinesJournal_IsInPlayerPossession;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Books_CatherinesJournal_IsInPlayerPossession = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Books_CatherinesJournal_IsInPlayerPossession() {
   return A_Books_CatherinesJournal_IsInPlayerPossession;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Books_CurrentZoomedLinkingBook_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Books_CurrentZoomedLinkingBook_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Books_CurrentZoomedLinkingBook_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Books_CurrentZoomedLinkingBook_IsOpen() {
   return A_Books_CurrentZoomedLinkingBook_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Books_TrapBook_IsInPlayerPossession(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Books_TrapBook_IsInPlayerPossession;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Books_TrapBook_IsInPlayerPossession = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Books_TrapBook_IsInPlayerPossession() {
   return A_Books_TrapBook_IsInPlayerPossession;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_Catherine_IsFreed(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_Catherine_IsFreed;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_Catherine_IsFreed = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_Catherine_IsFreed() {
   return A_Characters_Catherine_IsFreed;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_Cho_IsStillPassedOut(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_Cho_IsStillPassedOut;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_Cho_IsStillPassedOut = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_Cho_IsStillPassedOut() {
   return A_Characters_Cho_IsStillPassedOut;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_Gehn_IsTrappedInBook(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_Gehn_IsTrappedInBook;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_Gehn_IsTrappedInBook = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_Gehn_IsTrappedInBook() {
   return A_Characters_Gehn_IsTrappedInBook;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_Wahrk_TimesBeckoned(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->A_Characters_Wahrk_TimesBeckoned;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_Wahrk_TimesBeckoned = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_A_Characters_Wahrk_TimesBeckoned() {
   return A_Characters_Wahrk_TimesBeckoned;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_CatherinesFriend_HasMadeSecondAppearance(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_CatherinesFriend_HasMadeSecondAppearance;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_CatherinesFriend_HasMadeSecondAppearance = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_CatherinesFriend_HasMadeSecondAppearance() {
   return A_Characters_CatherinesFriend_HasMadeSecondAppearance;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_Scribe_HasBeenSeen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_Scribe_HasBeenSeen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_Scribe_HasBeenSeen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_Scribe_HasBeenSeen() {
   return A_Characters_Scribe_HasBeenSeen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_JumpscareGirl_HasBeenSeen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_JumpscareGirl_HasBeenSeen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_JumpscareGirl_HasBeenSeen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_JumpscareGirl_HasBeenSeen() {
   return A_Characters_JumpscareGirl_HasBeenSeen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_RecluseWoman_HasBeenSeen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_RecluseWoman_HasBeenSeen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_RecluseWoman_HasBeenSeen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_RecluseWoman_HasBeenSeen() {
   return A_Characters_RecluseWoman_HasBeenSeen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_TowerGuard_HasBeenSeen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_TowerGuard_HasBeenSeen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_TowerGuard_HasBeenSeen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_TowerGuard_HasBeenSeen() {
   return A_Characters_TowerGuard_HasBeenSeen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_FleeingParentAndChild_HaveBeenSeen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_FleeingParentAndChild_HaveBeenSeen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_FleeingParentAndChild_HaveBeenSeen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_FleeingParentAndChild_HaveBeenSeen() {
   return A_Characters_FleeingParentAndChild_HaveBeenSeen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Characters_Sunners_HaveBeenShooed(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->A_Characters_Sunners_HaveBeenShooed;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->A_Characters_Sunners_HaveBeenShooed = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Characters_Sunners_HaveBeenShooed() {
   return A_Characters_Sunners_HaveBeenShooed;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_Shore_Valve_Position(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->B_Shore_Valve_Position;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->B_Shore_Valve_Position = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_B_Shore_Valve_Position() {
   return B_Shore_Valve_Position;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerExterior_SelectorValve_IsTowardsPump(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->B_BoilerExterior_SelectorValve_IsTowardsPump;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->B_BoilerExterior_SelectorValve_IsTowardsPump = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerExterior_SelectorValve_IsTowardsPump() {
   return B_BoilerExterior_SelectorValve_IsTowardsPump;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerExterior_LevelSelector_IsUp(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->B_BoilerExterior_LevelSelector_IsUp;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->B_BoilerExterior_LevelSelector_IsUp = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerExterior_LevelSelector_IsUp() {
   return B_BoilerExterior_LevelSelector_IsUp;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerExterior_Heater_IsOn(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->B_BoilerExterior_Heater_IsOn;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->B_BoilerExterior_Heater_IsOn = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerExterior_Heater_IsOn() {
   return B_BoilerExterior_Heater_IsOn;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerInterior_Water_IsPresent(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->B_BoilerInterior_Water_IsPresent;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->B_BoilerInterior_Water_IsPresent = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerInterior_Water_IsPresent() {
   return B_BoilerInterior_Water_IsPresent;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerInterior_Platform_IsRaised(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->B_BoilerInterior_Platform_IsRaised;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->B_BoilerInterior_Platform_IsRaised = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerInterior_Platform_IsRaised() {
   return B_BoilerInterior_Platform_IsRaised;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Basin_Submarine_PositionAndRotation(ESubPosRot NewVal) {
   if (IsFrozen) return;
   ESubPosRot OrigVal = this->J_Basin_Submarine_PositionAndRotation;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Basin_Submarine_PositionAndRotation = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
ESubPosRot URivenSaveGame::Get_J_Basin_Submarine_PositionAndRotation() {
   return J_Basin_Submarine_PositionAndRotation;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Basin_Gallows_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Basin_Gallows_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Basin_Gallows_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Basin_Gallows_IsOpen() {
   return J_Basin_Gallows_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Basin_Treehouse_IsLever1Up(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Basin_Treehouse_IsLever1Up;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Basin_Treehouse_IsLever1Up = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Basin_Treehouse_IsLever1Up() {
   return J_Basin_Treehouse_IsLever1Up;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Basin_Treehouse_IsLever2Up(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Basin_Treehouse_IsLever2Up;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Basin_Treehouse_IsLever2Up = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Basin_Treehouse_IsLever2Up() {
   return J_Basin_Treehouse_IsLever2Up;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Basin_Treehouse_IsLever3Up(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Basin_Treehouse_IsLever3Up;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Basin_Treehouse_IsLever3Up = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Basin_Treehouse_IsLever3Up() {
   return J_Basin_Treehouse_IsLever3Up;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Basin_Treehouse_IsLever4Up(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Basin_Treehouse_IsLever4Up;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Basin_Treehouse_IsLever4Up = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Basin_Treehouse_IsLever4Up() {
   return J_Basin_Treehouse_IsLever4Up;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Basin_Treehouse_IsLever5Up(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Basin_Treehouse_IsLever5Up;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Basin_Treehouse_IsLever5Up = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Basin_Treehouse_IsLever5Up() {
   return J_Basin_Treehouse_IsLever5Up;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_Gate1_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Forest_Gate1_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_Gate1_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Forest_Gate1_IsOpen() {
   return J_Forest_Gate1_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_Gate2_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Forest_Gate2_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_Gate2_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Forest_Gate2_IsOpen() {
   return J_Forest_Gate2_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_WharkIdol_IsMouthOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Forest_WharkIdol_IsMouthOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_WharkIdol_IsMouthOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Forest_WharkIdol_IsMouthOpen() {
   return J_Forest_WharkIdol_IsMouthOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_WharkIdol_ElevatorPosition(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_Forest_WharkIdol_ElevatorPosition;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_WharkIdol_ElevatorPosition = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_Forest_WharkIdol_ElevatorPosition() {
   return J_Forest_WharkIdol_ElevatorPosition;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_GehnsThrone_IsRaised(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Forest_GehnsThrone_IsRaised;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_GehnsThrone_IsRaised = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Forest_GehnsThrone_IsRaised() {
   return J_Forest_GehnsThrone_IsRaised;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_Dome_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Forest_Dome_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_Dome_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Forest_Dome_IsOpen() {
   return J_Forest_Dome_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_Dome_SliderA(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_Forest_Dome_SliderA;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_Dome_SliderA = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_Forest_Dome_SliderA() {
   return J_Forest_Dome_SliderA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_Dome_SliderB(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_Forest_Dome_SliderB;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_Dome_SliderB = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_Forest_Dome_SliderB() {
   return J_Forest_Dome_SliderB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_Dome_SliderC(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_Forest_Dome_SliderC;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_Dome_SliderC = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_Forest_Dome_SliderC() {
   return J_Forest_Dome_SliderC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_Dome_SliderD(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_Forest_Dome_SliderD;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_Dome_SliderD = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_Forest_Dome_SliderD() {
   return J_Forest_Dome_SliderD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_Dome_SliderE(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_Forest_Dome_SliderE;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_Dome_SliderE = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_Forest_Dome_SliderE() {
   return J_Forest_Dome_SliderE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Forest_Ladder_IsLowered(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_Forest_Ladder_IsLowered;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_Forest_Ladder_IsLowered = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_Forest_Ladder_IsLowered() {
   return J_Forest_Ladder_IsLowered;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Books_SelectedStoneA(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_SecretTunnel_Books_SelectedStoneA;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Books_SelectedStoneA = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_SecretTunnel_Books_SelectedStoneA() {
   return J_SecretTunnel_Books_SelectedStoneA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Books_SelectedStoneB(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_SecretTunnel_Books_SelectedStoneB;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Books_SelectedStoneB = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_SecretTunnel_Books_SelectedStoneB() {
   return J_SecretTunnel_Books_SelectedStoneB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Books_SelectedStoneC(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_SecretTunnel_Books_SelectedStoneC;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Books_SelectedStoneC = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_SecretTunnel_Books_SelectedStoneC() {
   return J_SecretTunnel_Books_SelectedStoneC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Books_SelectedStoneD(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_SecretTunnel_Books_SelectedStoneD;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Books_SelectedStoneD = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_SecretTunnel_Books_SelectedStoneD() {
   return J_SecretTunnel_Books_SelectedStoneD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Books_SelectedStoneE(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->J_SecretTunnel_Books_SelectedStoneE;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Books_SelectedStoneE = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_SecretTunnel_Books_SelectedStoneE() {
   return J_SecretTunnel_Books_SelectedStoneE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Lights_IsLight1On(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_SecretTunnel_Lights_IsLight1On;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Lights_IsLight1On = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_SecretTunnel_Lights_IsLight1On() {
   return J_SecretTunnel_Lights_IsLight1On;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Lights_IsLight2On(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_SecretTunnel_Lights_IsLight2On;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Lights_IsLight2On = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_SecretTunnel_Lights_IsLight2On() {
   return J_SecretTunnel_Lights_IsLight2On;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Lights_IsLight3On(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_SecretTunnel_Lights_IsLight3On;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Lights_IsLight3On = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_SecretTunnel_Lights_IsLight3On() {
   return J_SecretTunnel_Lights_IsLight3On;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Lights_IsLight4On(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_SecretTunnel_Lights_IsLight4On;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Lights_IsLight4On = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_SecretTunnel_Lights_IsLight4On() {
   return J_SecretTunnel_Lights_IsLight4On;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SecretTunnel_Lights_IsLight5On(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->J_SecretTunnel_Lights_IsLight5On;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->J_SecretTunnel_Lights_IsLight5On = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_SecretTunnel_Lights_IsLight5On() {
   return J_SecretTunnel_Lights_IsLight5On;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_Upstairs_Stove_IsOn(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->O_Upstairs_Stove_IsOn;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->O_Upstairs_Stove_IsOn = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_Upstairs_Stove_IsOn() {
   return O_Upstairs_Stove_IsOn;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_Upstairs_CageButton_TimesPressed(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->O_Upstairs_CageButton_TimesPressed;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->O_Upstairs_CageButton_TimesPressed = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_O_Upstairs_CageButton_TimesPressed() {
   return O_Upstairs_CageButton_TimesPressed;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_Upstairs_CageLever_IsUnlocked(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->O_Upstairs_CageLever_IsUnlocked;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->O_Upstairs_CageLever_IsUnlocked = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_Upstairs_CageLever_IsUnlocked() {
   return O_Upstairs_CageLever_IsUnlocked;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_Upstairs_Cannen_IsPlaying(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->O_Upstairs_Cannen_IsPlaying;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->O_Upstairs_Cannen_IsPlaying = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_Upstairs_Cannen_IsPlaying() {
   return O_Upstairs_Cannen_IsPlaying;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_Bedroom_Drawer_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->O_Bedroom_Drawer_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->O_Bedroom_Drawer_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_Bedroom_Drawer_IsOpen() {
   return O_Bedroom_Drawer_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeA(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->S_Dome_CodeA;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_Dome_CodeA = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeA() {
   return S_Dome_CodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeB(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->S_Dome_CodeB;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_Dome_CodeB = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeB() {
   return S_Dome_CodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeC(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->S_Dome_CodeC;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_Dome_CodeC = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeC() {
   return S_Dome_CodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeD(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->S_Dome_CodeD;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_Dome_CodeD = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeD() {
   return S_Dome_CodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeE(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->S_Dome_CodeE;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_Dome_CodeE = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeE() {
   return S_Dome_CodeE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Cart_IsAtJungle(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->S_Cart_IsAtJungle;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_Cart_IsAtJungle = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_S_Cart_IsAtJungle() {
   return S_Cart_IsAtJungle;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_MaglevTJ_IsSpinnerToRight(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->S_MaglevTJ_IsSpinnerToRight;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_MaglevTJ_IsSpinnerToRight = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_S_MaglevTJ_IsSpinnerToRight() {
   return S_MaglevTJ_IsSpinnerToRight;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_MaglevTJ_IsAtTemple(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->S_MaglevTJ_IsAtTemple;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_MaglevTJ_IsAtTemple = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_S_MaglevTJ_IsAtTemple() {
   return S_MaglevTJ_IsAtTemple;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_MaglevBG_IsSpinnerToRight(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->S_MaglevBG_IsSpinnerToRight;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_MaglevBG_IsSpinnerToRight = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_S_MaglevBG_IsSpinnerToRight() {
   return S_MaglevBG_IsSpinnerToRight;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_MaglevBG_IsAtSurvey(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->S_MaglevBG_IsAtSurvey;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_MaglevBG_IsAtSurvey = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_S_MaglevBG_IsAtSurvey() {
   return S_MaglevBG_IsAtSurvey;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_MaglevGJ_IsSpinnerToRight(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->S_MaglevGJ_IsSpinnerToRight;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_MaglevGJ_IsSpinnerToRight = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_S_MaglevGJ_IsSpinnerToRight() {
   return S_MaglevGJ_IsSpinnerToRight;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_MaglevGJ_IsAtJungle(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->S_MaglevGJ_IsAtJungle;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->S_MaglevGJ_IsAtJungle = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_S_MaglevGJ_IsAtJungle() {
   return S_MaglevGJ_IsAtJungle;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever_IsInClosedPosition(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_FissurePlateau_CageLever_IsInClosedPosition;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_CageLever_IsInClosedPosition = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_FissurePlateau_CageLever_IsInClosedPosition() {
   return T_FissurePlateau_CageLever_IsInClosedPosition;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Gateroom_Rotation(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_FissurePlateau_Gateroom_Rotation;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_Gateroom_Rotation = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Gateroom_Rotation() {
   return T_FissurePlateau_Gateroom_Rotation;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Gateroom_SelectedBeetle(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_FissurePlateau_Gateroom_SelectedBeetle;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_Gateroom_SelectedBeetle = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Gateroom_SelectedBeetle() {
   return T_FissurePlateau_Gateroom_SelectedBeetle;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_IsBlocked(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_FissurePlateau_Telescope_IsBlocked;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_Telescope_IsBlocked = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_FissurePlateau_Telescope_IsBlocked() {
   return T_FissurePlateau_Telescope_IsBlocked;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_Level(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_FissurePlateau_Telescope_Level;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_Telescope_Level = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_Level() {
   return T_FissurePlateau_Telescope_Level;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeA(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_FissurePlateau_Telescope_CodeA;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_Telescope_CodeA = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeA() {
   return T_FissurePlateau_Telescope_CodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeB(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_FissurePlateau_Telescope_CodeB;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_Telescope_CodeB = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeB() {
   return T_FissurePlateau_Telescope_CodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeC(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_FissurePlateau_Telescope_CodeC;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_Telescope_CodeC = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeC() {
   return T_FissurePlateau_Telescope_CodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeD(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_FissurePlateau_Telescope_CodeD;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_Telescope_CodeD = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeD() {
   return T_FissurePlateau_Telescope_CodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeE(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_FissurePlateau_Telescope_CodeE;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_FissurePlateau_Telescope_CodeE = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeE() {
   return T_FissurePlateau_Telescope_CodeE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Airlock_OutsideDoor_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_Airlock_OutsideDoor_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Airlock_OutsideDoor_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_Airlock_OutsideDoor_IsOpen() {
   return T_Airlock_OutsideDoor_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Airlock_InsideDoor_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_Airlock_InsideDoor_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Airlock_InsideDoor_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_Airlock_InsideDoor_IsOpen() {
   return T_Airlock_InsideDoor_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_SteamCave_Door_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_SteamCave_Door_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_SteamCave_Door_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_SteamCave_Door_IsOpen() {
   return T_SteamCave_Door_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_SteamCave_Valve_IsPoweringTelescope(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_SteamCave_Valve_IsPoweringTelescope;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_SteamCave_Valve_IsPoweringTelescope = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_SteamCave_Valve_IsPoweringTelescope() {
   return T_SteamCave_Valve_IsPoweringTelescope;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_SpiderChairRoom_Microphone_IsOn(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_SpiderChairRoom_Microphone_IsOn;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_SpiderChairRoom_Microphone_IsOn = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_SpiderChairRoom_Microphone_IsOn() {
   return T_SpiderChairRoom_Microphone_IsOn;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_NewTemple_DoorMain_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_NewTemple_DoorMain_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_NewTemple_DoorMain_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_NewTemple_DoorMain_IsOpen() {
   return T_NewTemple_DoorMain_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_NewTemple_DoorSide_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_NewTemple_DoorSide_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_NewTemple_DoorSide_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_NewTemple_DoorSide_IsOpen() {
   return T_NewTemple_DoorSide_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_Dome_IsOpen(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_Backstage_Dome_IsOpen;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_Dome_IsOpen = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_Backstage_Dome_IsOpen() {
   return T_Backstage_Dome_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_Dome_SliderA(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_Backstage_Dome_SliderA;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_Dome_SliderA = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_Backstage_Dome_SliderA() {
   return T_Backstage_Dome_SliderA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_Dome_SliderB(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_Backstage_Dome_SliderB;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_Dome_SliderB = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_Backstage_Dome_SliderB() {
   return T_Backstage_Dome_SliderB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_Dome_SliderC(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_Backstage_Dome_SliderC;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_Dome_SliderC = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_Backstage_Dome_SliderC() {
   return T_Backstage_Dome_SliderC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_Dome_SliderD(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_Backstage_Dome_SliderD;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_Dome_SliderD = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_Backstage_Dome_SliderD() {
   return T_Backstage_Dome_SliderD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_Dome_SliderE(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->T_Backstage_Dome_SliderE;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_Dome_SliderE = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_Backstage_Dome_SliderE() {
   return T_Backstage_Dome_SliderE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_BridgeValve_IsWastingSteam(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_Backstage_BridgeValve_IsWastingSteam;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_BridgeValve_IsWastingSteam = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_Backstage_BridgeValve_IsWastingSteam() {
   return T_Backstage_BridgeValve_IsWastingSteam;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_BridgeLever_IsUp(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_Backstage_BridgeLever_IsUp;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_BridgeLever_IsUp = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_Backstage_BridgeLever_IsUp() {
   return T_Backstage_BridgeLever_IsUp;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_Elevator_IsUp(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_Backstage_Elevator_IsUp;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_Elevator_IsUp = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_Backstage_Elevator_IsUp() {
   return T_Backstage_Elevator_IsUp;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_SuperdomeWalkway_IsExtended(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_Backstage_SuperdomeWalkway_IsExtended;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_SuperdomeWalkway_IsExtended = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_Backstage_SuperdomeWalkway_IsExtended() {
   return T_Backstage_SuperdomeWalkway_IsExtended;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_Backstage_WaffleIron_IsEngaged(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->T_Backstage_WaffleIron_IsEngaged;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->T_Backstage_WaffleIron_IsEngaged = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_Backstage_WaffleIron_IsEngaged() {
   return T_Backstage_WaffleIron_IsEngaged;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Elevator_IsInCaptiveMode(bool NewVal) {
   if (IsFrozen) return;
   bool OrigVal = this->P_Exterior_Elevator_IsInCaptiveMode;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->P_Exterior_Elevator_IsInCaptiveMode = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_P_Exterior_Elevator_IsInCaptiveMode() {
   return P_Exterior_Elevator_IsInCaptiveMode;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeA(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->P_Exterior_Lock_CodeA;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->P_Exterior_Lock_CodeA = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeA() {
   return P_Exterior_Lock_CodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeB(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->P_Exterior_Lock_CodeB;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->P_Exterior_Lock_CodeB = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeB() {
   return P_Exterior_Lock_CodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeC(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->P_Exterior_Lock_CodeC;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->P_Exterior_Lock_CodeC = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeC() {
   return P_Exterior_Lock_CodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeD(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->P_Exterior_Lock_CodeD;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->P_Exterior_Lock_CodeD = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeD() {
   return P_Exterior_Lock_CodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeE(int32 NewVal) {
   if (IsFrozen) return;
   int32 OrigVal = this->P_Exterior_Lock_CodeE;
   if (OrigVal != NewVal) {
     URivenSaveGame* OldSaveGame = DuplicateObject(this, NULL);
     OldSaveGame->Freeze();
     this->P_Exterior_Lock_CodeE = NewVal;
     this->Subscriber->NotifySubscribersOfChange(OldSaveGame);
   }
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeE() {
   return P_Exterior_Lock_CodeE;
}

/* [[[end]]] */
