// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "StringUtilities.generated.h"

/**
 * 
 */
UCLASS()
class STARRYEXPANSE_API UStringUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		public:
		UFUNCTION(BlueprintCallable, Category="Utilities/String")
		static FString JoinStringsWithNewlines(TArray<FString> strings);
	
	
};
