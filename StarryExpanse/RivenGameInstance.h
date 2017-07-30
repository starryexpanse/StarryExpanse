// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LoadGroups/LoadgroupActor.h"
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
	UPROPERTY(BlueprintReadOnly)
		bool bIsFrozenForLoading;

	UPROPERTY(BlueprintReadOnly)
		ALoadgroupActor* LoadgroupQueen;

	// Methods
	UFUNCTION(BlueprintCallable, Category = "LoadGroups")
	void RegisterLoadgroupQueen(ALoadgroupActor* newQueen);

	UFUNCTION(BlueprintCallable, Category = "LoadGroups")
	void SetIsFrozenForLoading(bool newFrozen);

};
