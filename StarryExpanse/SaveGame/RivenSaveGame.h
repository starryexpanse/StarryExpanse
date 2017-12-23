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
  ELoadGroups A_LoadGroups;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_LoadGroups(ELoadGroups NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  ELoadGroups Get_A_LoadGroups();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  EMarionettist A_LoadGroupsMarionettist;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_LoadGroupsMarionettist(EMarionettist NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  EMarionettist Get_A_LoadGroupsMarionettist();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_LoadGroupsMarionettistBooks;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_LoadGroupsMarionettistBooks(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_LoadGroupsMarionettistBooks();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_LoadGroupsMarionettistBooks;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_LoadGroupsMarionettistBooks(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_LoadGroupsMarionettistBooks();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_LoadGroupsMarionettistBooks;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_LoadGroupsMarionettistBooks(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_LoadGroupsMarionettistBooks();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool A_LoadGroupsMarionettistBooks;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_LoadGroupsMarionettistBooks(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_A_LoadGroupsMarionettistBooks();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  FTransform A_LoadGroupsMarionettistBooksRivenCharacter;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_A_LoadGroupsMarionettistBooksRivenCharacter(FTransform NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  FTransform Get_A_LoadGroupsMarionettistBooksRivenCharacter();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 B_Shore;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_Shore(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_B_Shore();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_ShoreBoilerExterior;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_ShoreBoilerExterior(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_ShoreBoilerExterior();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_ShoreBoilerExterior;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_ShoreBoilerExterior(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_ShoreBoilerExterior();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_ShoreBoilerExterior;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_ShoreBoilerExterior(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_ShoreBoilerExterior();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_ShoreBoilerExteriorBoilerInterior;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_ShoreBoilerExteriorBoilerInterior(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_ShoreBoilerExteriorBoilerInterior();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool B_ShoreBoilerExteriorBoilerInterior;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_B_ShoreBoilerExteriorBoilerInterior(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_B_ShoreBoilerExteriorBoilerInterior();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  ESubPosRot J_Submarine;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_Submarine(ESubPosRot NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  ESubPosRot Get_J_Submarine();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool J_SubmarineTunnelBranch;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SubmarineTunnelBranch(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_J_SubmarineTunnelBranch();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 J_SubmarineTunnelBranchIdolInterior;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_J_SubmarineTunnelBranchIdolInterior(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_J_SubmarineTunnelBranchIdolInterior();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool O_Stove;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_Stove(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_O_Stove();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 O_StoveCageButton;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_StoveCageButton(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_O_StoveCageButton();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool O_StoveCageButtonCageLever;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_O_StoveCageButtonCageLever(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_O_StoveCageButtonCageLever();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 S_Dome;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_S_Dome(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_S_Dome();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_FissurePlateau_CageLever;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_CageLever(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_FissurePlateau_CageLever();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_FissurePlateau_CageLever_Cho;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_CageLever_Cho(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_FissurePlateau_CageLever_Cho();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_CageLever_Cho_Telescope;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_CageLever_Cho_Telescope();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_CageLever_Cho_Telescope;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_CageLever_Cho_Telescope();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_CageLever_Cho_Telescope;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_CageLever_Cho_Telescope();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_CageLever_Cho_Telescope;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_CageLever_Cho_Telescope();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 T_FissurePlateau_CageLever_Cho_Telescope;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_T_FissurePlateau_CageLever_Cho_Telescope();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_NewTemple_DoorMain;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_NewTemple_DoorMain(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_NewTemple_DoorMain();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool T_NewTemple_DoorMain_DoorSide;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_T_NewTemple_DoorMain_DoorSide(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_T_NewTemple_DoorMain_DoorSide();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 P_Exterior_Lock;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_P_Exterior_Lock(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_P_Exterior_Lock();

  /* [[[end]]] */
};
