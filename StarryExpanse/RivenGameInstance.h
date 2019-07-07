// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enums/EInteractable.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LoadGroups/LoadgroupActor.h"
#include "SaveGame/RivenSaveGame.h"
#include "Structs/RivenGameInstanceVars.h"
#include <set>
#include "RivenGameInstance.generated.h"

/**
 *
 */
UCLASS()
class STARRYEXPANSE_API URivenGameInstance : public UGameInstance {
  GENERATED_BODY()

public:
  UPROPERTY(BlueprintReadOnly)
  FRivenGameInstanceVars GameInstanceVars;

  // "Game instance vars" have changed. This is generally whenever some global
  // shared state has changed. Try to keep this to a minimum as it is a little
  // expensive.
  DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameInstanceVarsChanged);
  UPROPERTY(BlueprintAssignable, Category = "Game Instance Vars")
  FGameInstanceVarsChanged GameInstanceVarsChanged;

  // Properties

  std::set<FName> OutstandingSaveGameBlockers;

  UPROPERTY(BlueprintReadWrite)
  bool bWasAppStartedInVRMode;

  UPROPERTY(BlueprintReadOnly)
  bool bIsFrozenForLoading;

  UPROPERTY(BlueprintReadOnly)
  ALoadgroupActor *LoadgroupQueen;

  // Reserved for future use:
  UPROPERTY(BlueprintReadOnly)
  URivenSaveGame *Last_Savable_SaveGame;

  // Methods

  void Init() override;

  UFUNCTION(BlueprintCallable, Category = "StarryExpanse VR")
  void SetWasAppStartedInVRMode(bool value);

  UFUNCTION(BlueprintCallable, Category = "SaveGame")
  void RegisterSaveGameBlocker(FName blockerName);

  UFUNCTION(BlueprintCallable, Category = "SaveGame")
  void UnregisterSaveGameBlocker(FName blockerName);

  UFUNCTION(BlueprintCallable, Category = "LoadGroups")
  void RegisterLoadgroupQueen(ALoadgroupActor *newQueen);

  UFUNCTION(BlueprintCallable, Category = "LoadGroups")
  void SetIsFrozenForLoading(bool newFrozen);

  UFUNCTION(BlueprintCallable, Category = Gameplay)
  void SetInteractableState(EInteractable interactable, float state);

  UFUNCTION(BlueprintCallable, Category = Gameplay)
  float GetInteractableState(EInteractable interactable);

private:
  // Temporary hack. Will move into a proper game state object.
  float m_fissurePlateauLeverState = 1.0;
};
