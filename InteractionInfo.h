// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "Enums/EInteractionEvent.h"
#include "InteractionInfo.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Category = "Interaction Info")
class STARRYEXPANSE_API UInteractionInfo : public UUserDefinedStruct
{
	GENERATED_BODY()


public:

		UFUNCTION(BlueprintCallable, BlueprintPure, Category="Interaction Info")
			static UInteractionInfo* MakeInteractionInfo(TEnumAsByte<EInteractionEvent> evt);
		
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction Info")
		TEnumAsByte<EInteractionEvent> EventType;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction Info")
		FVector2D Start;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction Info")
		FVector2D End;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction Info")
		FVector RayPointInitial;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction Info")
		FVector RayPointFinal;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction Info")
		FVector RayDirectionInitial;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction Info")
		FVector RayDirectionFinal;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction Info")
		FHitResult HitResult;
	
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction Info")
		float DpiMultiplier;
};
