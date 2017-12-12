//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//

#pragma once

#include "GameFramework/SaveGame.h"
#include "SaveGame/ESaveGameField.h"
#include "LoadGroups/ELoadGroups.h"
#include "Enums/EMarionettist.h"
#include "Enums/ESubPosRot.h"
#include <vector>
#include <tuple>
#include <string>
#include "RivenSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class STARRYEXPANSE_API URivenSaveGame : public USaveGame
{
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
   ELoadGroups CurrentLoadGroup;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_CurrentLoadGroup(ELoadGroups NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   ELoadGroups Get_CurrentLoadGroup();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   EMarionettist CurrentMarionettist;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_CurrentMarionettist(EMarionettist NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   EMarionettist Get_CurrentMarionettist();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool CurrentZoomedLinkingBookIsOpen;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_CurrentZoomedLinkingBookIsOpen(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_CurrentZoomedLinkingBookIsOpen();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool GehnIsTrapped;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_GehnIsTrapped(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_GehnIsTrapped();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool HaveTrapBook;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_HaveTrapBook(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_HaveTrapBook();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool CatherineIsFree;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_CatherineIsFree(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_CatherineIsFree();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   FTransform CharacterTransform;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_CharacterTransform(FTransform NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   FTransform Get_CharacterTransform();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 TelescopeCodeA;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_TelescopeCodeA(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_TelescopeCodeA();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 TelescopeCodeB;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_TelescopeCodeB(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_TelescopeCodeB();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 TelescopeCodeC;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_TelescopeCodeC(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_TelescopeCodeC();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 TelescopeCodeD;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_TelescopeCodeD(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_TelescopeCodeD();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 TelescopeCodeE;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_TelescopeCodeE(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_TelescopeCodeE();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 PrisonCodeA;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_PrisonCodeA(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_PrisonCodeA();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 PrisonCodeB;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_PrisonCodeB(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_PrisonCodeB();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 PrisonCodeC;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_PrisonCodeC(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_PrisonCodeC();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 PrisonCodeD;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_PrisonCodeD(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_PrisonCodeD();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 PrisonCodeE;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_PrisonCodeE(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_PrisonCodeE();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 DomeCodeA;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_DomeCodeA(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_DomeCodeA();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 DomeCodeB;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_DomeCodeB(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_DomeCodeB();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 DomeCodeC;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_DomeCodeC(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_DomeCodeC();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 DomeCodeD;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_DomeCodeD(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_DomeCodeD();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 DomeCodeE;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_DomeCodeE(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_DomeCodeE();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   ESubPosRot SubPosRot;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_SubPosRot(ESubPosRot NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   ESubPosRot Get_SubPosRot();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool J_SeenCreepyGirl;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_J_SeenCreepyGirl(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_J_SeenCreepyGirl();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 J_WahrkElevatorPosition;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_J_WahrkElevatorPosition(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_J_WahrkElevatorPosition();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool O_OvenIsOn;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_O_OvenIsOn(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_O_OvenIsOn();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool O_CageIsUp;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_O_CageIsUp(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_O_CageIsUp();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   int32 O_TimesGehnSignaled;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_O_TimesGehnSignaled(int32 NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   int32 Get_O_TimesGehnSignaled();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool T_NewTemple_DoorMain_Open;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_T_NewTemple_DoorMain_Open(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_T_NewTemple_DoorMain_Open();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool T_NewTemple_DoorSide_Open;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_T_NewTemple_DoorSide_Open(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_T_NewTemple_DoorSide_Open();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool T_FissurePlateau_CageLever_Closed;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_T_FissurePlateau_CageLever_Closed(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_T_FissurePlateau_CageLever_Closed();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool T_FissurePlateau_ChoStillPassedOut;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_T_FissurePlateau_ChoStillPassedOut(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_T_FissurePlateau_ChoStillPassedOut();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool S_SeenScribe;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_S_SeenScribe(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_S_SeenScribe();

   UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
   bool B_GehnHasVisited;

   UFUNCTION(BlueprintCallable, Category = SaveGame)
   void Set_B_GehnHasVisited(bool NewVal);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
   bool Get_B_GehnHasVisited();

   /* [[[end]]] */
	
};
