// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <set>
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LoadGroups/LoadgroupActor.h"
#include "Actors/EInteractable.h"
#include "SaveGame/RivenSaveGame.h"
#include "RivenGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class STARRYEXPANSE_API URivenGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	// Events
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFrozenForLoadingChangedEvent);
	UPROPERTY(BlueprintAssignable, Category = "Loading State")
		FFrozenForLoadingChangedEvent FrozenForLoadingChangedEvent;

	// Properties

	std::set<FName> OutstandingSaveGameBlockers;

	UPROPERTY(BlueprintReadOnly)
		bool bIsFrozenForLoading;

	UPROPERTY(BlueprintReadOnly)
		ALoadgroupActor* LoadgroupQueen;

	UPROPERTY(BlueprintReadOnly)
		URivenSaveGame* Last_Savable_SaveGame;

	// Methods
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
		void RegisterSaveGameBlocker(FName blockerName);

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
		void UnregisterSaveGameBlocker(FName blockerName);

	UFUNCTION(BlueprintCallable, Category = "LoadGroups")
	void RegisterLoadgroupQueen(ALoadgroupActor* newQueen);

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
