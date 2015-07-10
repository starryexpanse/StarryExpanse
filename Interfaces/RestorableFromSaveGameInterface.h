// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseStarrySaveGame.h"
#include "RestorableFromSaveGameInterface.generated.h"

UINTERFACE(Blueprintable)
class URestorableFromSaveGameInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class STARRYEXPANSE_API IRestorableFromSaveGameInterface
{
	GENERATED_IINTERFACE_BODY()

		UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Restorable From Save Game Interface")
		void RestoreFromSaveGame(bool TriggeredByLoadGroupChange, const UBaseStarrySaveGame * Game);
};

