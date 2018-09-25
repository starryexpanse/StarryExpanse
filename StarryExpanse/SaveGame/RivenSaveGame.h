//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#pragma once

#include "Enums/EMarionettist.h"
#include "Enums/ESubPosRot.h"
#include "GameFramework/SaveGame.h"
#include "UObjectGlobals.h"
#include "LoadGroups/ELoadGroups.h"
#include "SaveGame/ESaveGameField.h"
#include <string>
#include <tuple>
#include <vector>
#include "RivenSaveGame.generated.h"

class ARivenGameState;

/**
 *
 */
UCLASS()
class STARRYEXPANSE_API URivenSaveGame : public USaveGame {
  GENERATED_UCLASS_BODY()

private:
  bool IsFrozen = false;
  void Freeze();

public:
  UPROPERTY()
  ARivenGameState *Subscriber;

  UFUNCTION()
  void SetSubscriber(ARivenGameState *NextSubscriber);

  std::vector<std::tuple<std::string, std::string>> GetSavegameFields();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void RestoreNewGameDefaults();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  bool GetBooleanBySaveGameField(ESaveGameField fieldName);

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void SetBooleanBySaveGameField(ESaveGameField fieldName, bool newValue);

  /* The following section is generated with a code generator, Cog.
   * To re-generate code in this file, run recog.bat
   *
   * [[[cog
    import cog
    from rivensavegame_generator import vars, p

    p("private:")

    for var in vars:
        p("UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)")
        p("%s %s;" % (var[0], var[1]))
        p("")

    p("public:")

    for var in vars:

        # Setters
        p("UFUNCTION(BlueprintCallable, Category = SaveGame)")
        p("void Set_%s(%s NewVal);" % (var[1], var[0]))
        p("")

        # Getters
        p("UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)")
        p("%s Get_%s();" % (var[0], var[1]))
        p("")

  ]]] */
private:
  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  ELoadGroups A_LoadGroups_CurrentLoadGroup;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  EMarionettist A_Marionettist_CurrentMarionettist;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  FTransform A_RivenCharacter_Transform;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Books_CatherinesJournal_IsInPlayerPossession;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Books_CurrentZoomedLinkingBook_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Books_TrapBook_IsInPlayerPossession;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_Catherine_IsFreed;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_Cho_IsStillPassedOut;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_Gehn_IsTrappedInBook;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 A_Characters_Wahrk_TimesBeckoned;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_CatherinesFriend_HasMadeSecondAppearance;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_Scribe_HasBeenSeen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_JumpscareGirl_HasBeenSeen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_RecluseWoman_HasBeenSeen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_TowerGuard_HasBeenSeen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_FleeingParentAndChild_HaveBeenSeen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Characters_Sunners_HaveBeenShooed;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Basin_Balcony_AreDoorsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 B_Shore_Valve_Position;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerExterior_SelectorValve_IsTowardsPump;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerExterior_LevelSelector_IsUp;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerExterior_Heater_IsOn;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerInterior_Water_IsPresent;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerInterior_Platform_IsRaised;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_BookPress_IsToTheRight;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_NorthDoor_IsLocked;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_NorthDoor_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_SouthDoor_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_Furnace_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_Drawers_IsDrawer1Open;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_Drawers_IsDrawer2Open;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_Drawers_IsDrawer3Open;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_Drawers_IsDrawer4Open;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_Drawers_IsDrawer5Open;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_Lab_DuctGrate_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  ESubPosRot J_Basin_Submarine_PositionAndRotation;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Basin_Gallows_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Basin_Treehouse_IsLever1Up;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Basin_Treehouse_IsLever2Up;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Basin_Treehouse_IsLever3Up;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Basin_Treehouse_IsLever4Up;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Basin_Treehouse_IsLever5Up;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Forest_Gate1_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Forest_Gate2_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Forest_WharkIdol_IsMouthOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_Forest_WharkIdol_ElevatorPosition;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Forest_GehnsThrone_IsRaised;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Forest_Dome_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_Forest_Dome_SliderA;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_Forest_Dome_SliderB;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_Forest_Dome_SliderC;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_Forest_Dome_SliderD;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_Forest_Dome_SliderE;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_Forest_Ladder_IsLowered;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_SecretTunnel_Books_SelectedStoneA;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_SecretTunnel_Books_SelectedStoneB;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_SecretTunnel_Books_SelectedStoneC;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_SecretTunnel_Books_SelectedStoneD;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_SecretTunnel_Books_SelectedStoneE;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_SecretTunnel_Lights_IsLight1On;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_SecretTunnel_Lights_IsLight2On;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_SecretTunnel_Lights_IsLight3On;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_SecretTunnel_Lights_IsLight4On;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_SecretTunnel_Lights_IsLight5On;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool O_Upstairs_Stove_IsOn;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 O_Upstairs_CageButton_TimesPressed;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool O_Upstairs_CageLever_IsUnlocked;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool O_Upstairs_Cannen_IsPlaying;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool O_Bedroom_Drawer_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeA;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeB;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeC;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeD;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeE;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool S_Cart_IsAtJungle;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool S_MaglevTJ_IsSpinnerToRight;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool S_MaglevTJ_IsAtTemple;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool S_MaglevBG_IsSpinnerToRight;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool S_MaglevBG_IsAtSurvey;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool S_MaglevGJ_IsSpinnerToRight;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool S_MaglevGJ_IsAtJungle;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_FissurePlateau_CageLever_IsInClosedPosition;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Gateroom_Rotation;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Gateroom_SelectedBeetle;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_FissurePlateau_Telescope_IsBlocked;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_Level;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeA;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeB;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeC;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeD;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeE;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_Airlock_OutsideDoor_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_Airlock_InsideDoor_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_SteamCave_Door_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_SteamCave_Valve_IsPoweringTelescope;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_SpiderChairRoom_Microphone_IsOn;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_NewTemple_DoorMain_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_NewTemple_DoorSide_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_Backstage_Dome_IsOpen;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_Backstage_Dome_SliderA;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_Backstage_Dome_SliderB;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_Backstage_Dome_SliderC;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_Backstage_Dome_SliderD;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_Backstage_Dome_SliderE;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_Backstage_BridgeValve_IsWastingSteam;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_Backstage_BridgeLever_IsUp;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_Backstage_Elevator_IsUp;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_Backstage_SuperdomeWalkway_IsExtended;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_Backstage_WaffleIron_IsEngaged;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool P_Exterior_Elevator_IsInCaptiveMode;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeA;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeB;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeC;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeD;

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeE;

public:
  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_LoadGroups_CurrentLoadGroup(ELoadGroups NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  ELoadGroups Get_A_LoadGroups_CurrentLoadGroup();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Marionettist_CurrentMarionettist(EMarionettist NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  EMarionettist Get_A_Marionettist_CurrentMarionettist();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_RivenCharacter_Transform(FTransform NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  FTransform Get_A_RivenCharacter_Transform();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Books_CatherinesJournal_IsInPlayerPossession(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Books_CatherinesJournal_IsInPlayerPossession();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Books_CurrentZoomedLinkingBook_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Books_CurrentZoomedLinkingBook_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Books_TrapBook_IsInPlayerPossession(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Books_TrapBook_IsInPlayerPossession();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_Catherine_IsFreed(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_Catherine_IsFreed();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_Cho_IsStillPassedOut(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_Cho_IsStillPassedOut();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_Gehn_IsTrappedInBook(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_Gehn_IsTrappedInBook();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_Wahrk_TimesBeckoned(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_A_Characters_Wahrk_TimesBeckoned();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_CatherinesFriend_HasMadeSecondAppearance(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_CatherinesFriend_HasMadeSecondAppearance();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_Scribe_HasBeenSeen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_Scribe_HasBeenSeen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_JumpscareGirl_HasBeenSeen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_JumpscareGirl_HasBeenSeen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_RecluseWoman_HasBeenSeen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_RecluseWoman_HasBeenSeen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_TowerGuard_HasBeenSeen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_TowerGuard_HasBeenSeen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_FleeingParentAndChild_HaveBeenSeen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_FleeingParentAndChild_HaveBeenSeen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Characters_Sunners_HaveBeenShooed(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Characters_Sunners_HaveBeenShooed();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Basin_Balcony_AreDoorsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Basin_Balcony_AreDoorsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Shore_Valve_Position(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_B_Shore_Valve_Position();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerExterior_SelectorValve_IsTowardsPump(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerExterior_SelectorValve_IsTowardsPump();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerExterior_LevelSelector_IsUp(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerExterior_LevelSelector_IsUp();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerExterior_Heater_IsOn(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerExterior_Heater_IsOn();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerInterior_Water_IsPresent(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerInterior_Water_IsPresent();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerInterior_Platform_IsRaised(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerInterior_Platform_IsRaised();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_BookPress_IsToTheRight(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_BookPress_IsToTheRight();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_NorthDoor_IsLocked(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_NorthDoor_IsLocked();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_NorthDoor_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_NorthDoor_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_SouthDoor_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_SouthDoor_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_Furnace_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_Furnace_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_Drawers_IsDrawer1Open(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_Drawers_IsDrawer1Open();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_Drawers_IsDrawer2Open(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_Drawers_IsDrawer2Open();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_Drawers_IsDrawer3Open(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_Drawers_IsDrawer3Open();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_Drawers_IsDrawer4Open(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_Drawers_IsDrawer4Open();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_Drawers_IsDrawer5Open(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_Drawers_IsDrawer5Open();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Lab_DuctGrate_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_Lab_DuctGrate_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Basin_Submarine_PositionAndRotation(ESubPosRot NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  ESubPosRot Get_J_Basin_Submarine_PositionAndRotation();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Basin_Gallows_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Basin_Gallows_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Basin_Treehouse_IsLever1Up(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Basin_Treehouse_IsLever1Up();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Basin_Treehouse_IsLever2Up(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Basin_Treehouse_IsLever2Up();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Basin_Treehouse_IsLever3Up(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Basin_Treehouse_IsLever3Up();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Basin_Treehouse_IsLever4Up(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Basin_Treehouse_IsLever4Up();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Basin_Treehouse_IsLever5Up(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Basin_Treehouse_IsLever5Up();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_Gate1_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Forest_Gate1_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_Gate2_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Forest_Gate2_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_WharkIdol_IsMouthOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Forest_WharkIdol_IsMouthOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_WharkIdol_ElevatorPosition(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_Forest_WharkIdol_ElevatorPosition();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_GehnsThrone_IsRaised(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Forest_GehnsThrone_IsRaised();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_Dome_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Forest_Dome_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_Dome_SliderA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_Forest_Dome_SliderA();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_Dome_SliderB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_Forest_Dome_SliderB();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_Dome_SliderC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_Forest_Dome_SliderC();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_Dome_SliderD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_Forest_Dome_SliderD();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_Dome_SliderE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_Forest_Dome_SliderE();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Forest_Ladder_IsLowered(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_Forest_Ladder_IsLowered();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Books_SelectedStoneA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_SecretTunnel_Books_SelectedStoneA();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Books_SelectedStoneB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_SecretTunnel_Books_SelectedStoneB();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Books_SelectedStoneC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_SecretTunnel_Books_SelectedStoneC();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Books_SelectedStoneD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_SecretTunnel_Books_SelectedStoneD();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Books_SelectedStoneE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_SecretTunnel_Books_SelectedStoneE();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Lights_IsLight1On(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_SecretTunnel_Lights_IsLight1On();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Lights_IsLight2On(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_SecretTunnel_Lights_IsLight2On();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Lights_IsLight3On(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_SecretTunnel_Lights_IsLight3On();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Lights_IsLight4On(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_SecretTunnel_Lights_IsLight4On();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SecretTunnel_Lights_IsLight5On(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_SecretTunnel_Lights_IsLight5On();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_Upstairs_Stove_IsOn(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_O_Upstairs_Stove_IsOn();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_Upstairs_CageButton_TimesPressed(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_O_Upstairs_CageButton_TimesPressed();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_Upstairs_CageLever_IsUnlocked(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_O_Upstairs_CageLever_IsUnlocked();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_Upstairs_Cannen_IsPlaying(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_O_Upstairs_Cannen_IsPlaying();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_Bedroom_Drawer_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_O_Bedroom_Drawer_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeA();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeB();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeC();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeD();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeE();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Cart_IsAtJungle(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_S_Cart_IsAtJungle();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_MaglevTJ_IsSpinnerToRight(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_S_MaglevTJ_IsSpinnerToRight();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_MaglevTJ_IsAtTemple(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_S_MaglevTJ_IsAtTemple();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_MaglevBG_IsSpinnerToRight(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_S_MaglevBG_IsSpinnerToRight();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_MaglevBG_IsAtSurvey(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_S_MaglevBG_IsAtSurvey();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_MaglevGJ_IsSpinnerToRight(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_S_MaglevGJ_IsSpinnerToRight();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_MaglevGJ_IsAtJungle(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_S_MaglevGJ_IsAtJungle();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_CageLever_IsInClosedPosition(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_FissurePlateau_CageLever_IsInClosedPosition();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Gateroom_Rotation(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Gateroom_Rotation();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Gateroom_SelectedBeetle(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Gateroom_SelectedBeetle();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_IsBlocked(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_FissurePlateau_Telescope_IsBlocked();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_Level(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_Level();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeA();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeB();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeC();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeD();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeE();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Airlock_OutsideDoor_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_Airlock_OutsideDoor_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Airlock_InsideDoor_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_Airlock_InsideDoor_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_SteamCave_Door_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_SteamCave_Door_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_SteamCave_Valve_IsPoweringTelescope(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_SteamCave_Valve_IsPoweringTelescope();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_SpiderChairRoom_Microphone_IsOn(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_SpiderChairRoom_Microphone_IsOn();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_NewTemple_DoorMain_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_NewTemple_DoorMain_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_NewTemple_DoorSide_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_NewTemple_DoorSide_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_Dome_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_Backstage_Dome_IsOpen();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_Dome_SliderA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_Backstage_Dome_SliderA();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_Dome_SliderB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_Backstage_Dome_SliderB();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_Dome_SliderC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_Backstage_Dome_SliderC();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_Dome_SliderD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_Backstage_Dome_SliderD();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_Dome_SliderE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_Backstage_Dome_SliderE();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_BridgeValve_IsWastingSteam(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_Backstage_BridgeValve_IsWastingSteam();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_BridgeLever_IsUp(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_Backstage_BridgeLever_IsUp();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_Elevator_IsUp(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_Backstage_Elevator_IsUp();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_SuperdomeWalkway_IsExtended(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_Backstage_SuperdomeWalkway_IsExtended();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_Backstage_WaffleIron_IsEngaged(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_Backstage_WaffleIron_IsEngaged();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Elevator_IsInCaptiveMode(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_P_Exterior_Elevator_IsInCaptiveMode();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeA();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeB();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeC();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeD();

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeE();

  /* [[[end]]] */
};
