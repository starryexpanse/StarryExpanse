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
  bool IsGehnTrapped;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsGehnTrapped(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsGehnTrapped();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool HasTrapBook;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_HasTrapBook(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_HasTrapBook();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsCatherineFreed;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsCatherineFreed(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsCatherineFreed();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  FTransform CharacterTransform;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CharacterTransform(FTransform NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  FTransform Get_CharacterTransform();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 ValvePosition;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_ValvePosition(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_ValvePosition();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsSelectorValveTowardsPump;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsSelectorValveTowardsPump(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsSelectorValveTowardsPump();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsLevelSelectorUp;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsLevelSelectorUp(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsLevelSelectorUp();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsHeaterOn;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsHeaterOn(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsHeaterOn();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsFullOfWater;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsFullOfWater(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsFullOfWater();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool PlatformRaised;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_PlatformRaised(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_PlatformRaised();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  ESubPosRot PositionAndRotation;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_PositionAndRotation(ESubPosRot NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  ESubPosRot Get_PositionAndRotation();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool HasSeenCreepyGirl;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_HasSeenCreepyGirl(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_HasSeenCreepyGirl();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 ElevatorPosition;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_ElevatorPosition(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_ElevatorPosition();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsOn;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsOn(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsOn();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 TimesPressed;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_TimesPressed(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_TimesPressed();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsInUnlockedState;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsInUnlockedState(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsInUnlockedState();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeA;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeA();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeB;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeB();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeC;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeC();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeD;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeD();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeE;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeE();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsInClosedPosition;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsInClosedPosition(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsInClosedPosition();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsStillPassedOut;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsStillPassedOut(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsStillPassedOut();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeA;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeA();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeB;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeB();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeC;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeC();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeD;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeD();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeE;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeE();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsOpen;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsOpen();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  bool IsOpen;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_IsOpen(bool NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  bool Get_IsOpen();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeA;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeA(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeA();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeB;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeB(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeB();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeC;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeC(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeC();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeD;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeD(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeD();

  UPROPERTY(VisibleAnywhere, SaveGame, Category = SaveGame)
  int32 CodeE;

  UFUNCTION(BlueprintCallable, Category = SaveGame)
  void Set_CodeE(int32 NewVal);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = SaveGame)
  int32 Get_CodeE();

  /* [[[end]]] */
};
