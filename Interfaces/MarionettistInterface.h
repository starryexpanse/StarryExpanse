// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enums/EMarionettist.h"
#include "BaseStarryCharacter.h"
#include "MarionettistInterface.generated.h"

UINTERFACE(Blueprintable)
class UMarionettistInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class STARRYEXPANSE_API IMarionettistInterface
{
	GENERATED_IINTERFACE_BODY()

		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Marionettist Interface")
		void BecomeMarionettist(const ABaseStarryCharacter *Character, bool Instantly);

		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Marionettist Interface")
		void RelinquishMarionette();

		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Marionettist Interface")
		EMarionettist GetWorldUniqueMarionettistName();

};

