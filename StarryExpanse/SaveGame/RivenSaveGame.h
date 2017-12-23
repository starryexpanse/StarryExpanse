//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//

#pragma once

#include "Enums/EMarionettist.h"
#include "Enums/ESubPosRot.h"
#include "GameFramework/SaveGame.h"
#include "LoadGroups/ELoadGroups.h"
#include "SaveGame/ESaveGameField.h"
#include <string>
#include <tuple>
#include <vector>
#include "RivenSaveGame.generated.h"

/**
 *
 */
UCLASS()
class STARRYEXPANSE_API URivenSaveGame : public USaveGame {
  GENERATED_UCLASS_BODY()

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

     for var in vars:
        p("UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)")
        p("%s %s;" % (var[0], var[1]))
        p("")

        # Setters
        p("UFUNCTION(BlueprintCallable, Category = SaveGame)")
        p("void Set_%s(%s NewVal);" % (var[1], var[0]))
        p("")

        # Getters
        p("UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)")
        p("%s Get_%s();" % (var[0], var[1]))
        p("")

  ]]] */
  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  ELoadGroups A_LoadGroups_CurrentLoadGroup;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_LoadGroups_CurrentLoadGroup(ELoadGroups NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  ELoadGroups Get_A_LoadGroups_CurrentLoadGroup();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  EMarionettist A_Marionettist_CurrentMarionettist;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Marionettist_CurrentMarionettist(EMarionettist NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  EMarionettist Get_A_Marionettist_CurrentMarionettist();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Books_CurrentZoomedLinkingBookIsOpen;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Books_CurrentZoomedLinkingBookIsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Books_CurrentZoomedLinkingBookIsOpen();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Books_IsGehnTrapped;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Books_IsGehnTrapped(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Books_IsGehnTrapped();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Books_HasTrapBook;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Books_HasTrapBook(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Books_HasTrapBook();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_Books_IsCatherineFreed;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_Books_IsCatherineFreed(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_Books_IsCatherineFreed();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  FTransform A_RivenCharacter_CharacterTransform;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_RivenCharacter_CharacterTransform(FTransform NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  FTransform Get_A_RivenCharacter_CharacterTransform();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 B_Shore_ValvePosition;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Shore_ValvePosition(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_B_Shore_ValvePosition();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerExterior_IsSelectorValveTowardsPump;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerExterior_IsSelectorValveTowardsPump(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerExterior_IsSelectorValveTowardsPump();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerExterior_IsLevelSelectorUp;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerExterior_IsLevelSelectorUp(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerExterior_IsLevelSelectorUp();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerExterior_IsHeaterOn;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerExterior_IsHeaterOn(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerExterior_IsHeaterOn();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerInterior_IsFullOfWater;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerInterior_IsFullOfWater(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerInterior_IsFullOfWater();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_BoilerInterior_PlatformRaised;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_BoilerInterior_PlatformRaised(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_BoilerInterior_PlatformRaised();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  ESubPosRot J_Submarine_PositionAndRotation;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Submarine_PositionAndRotation(ESubPosRot NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  ESubPosRot Get_J_Submarine_PositionAndRotation();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_TunnelBranch_HasSeenCreepyGirl;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_TunnelBranch_HasSeenCreepyGirl(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_TunnelBranch_HasSeenCreepyGirl();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_IdolInterior_ElevatorPosition;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_IdolInterior_ElevatorPosition(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_IdolInterior_ElevatorPosition();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool O_Stove_IsOn;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_Stove_IsOn(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_O_Stove_IsOn();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 O_CageButton_TimesPressed;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_CageButton_TimesPressed(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_O_CageButton_TimesPressed();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool O_CageLever_IsInUnlockedState;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_CageLever_IsInUnlockedState(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_O_CageLever_IsInUnlockedState();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeA;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeA();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeB;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeB();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeC;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeC();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeD;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeD();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome_CodeE;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome_CodeE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome_CodeE();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_FissurePlateau_CageLever_IsInClosedPosition;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_CageLever_IsInClosedPosition(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_FissurePlateau_CageLever_IsInClosedPosition();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_FissurePlateau_Cho_IsStillPassedOut;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Cho_IsStillPassedOut(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_FissurePlateau_Cho_IsStillPassedOut();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeA;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeA();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeB;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeB();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeC;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeC();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeD;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeD();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_Telescope_CodeE;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_Telescope_CodeE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_Telescope_CodeE();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_NewTemple_DoorMain_IsOpen;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_NewTemple_DoorMain_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_NewTemple_DoorMain_IsOpen();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_NewTemple_DoorSide_IsOpen;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_NewTemple_DoorSide_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_NewTemple_DoorSide_IsOpen();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeA;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeA();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeB;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeB();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeC;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeC();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeD;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeD();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock_CodeE;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock_CodeE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock_CodeE();

  /* [[[end]]] */
};
