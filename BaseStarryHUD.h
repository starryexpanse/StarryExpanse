// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "BaseStarryHUD.generated.h"

/**
 * 
 */
UCLASS()
class STARRYEXPANSE_API ABaseStarryHUD : public AHUD
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintImplementableEvent, meta=( DisplayName = "StarryHUD: Show Loading Screen" ))
		virtual void ShowLoadingScreen();

		UFUNCTION(BlueprintImplementableEvent, meta=( DisplayName = "StarryHUD: Hide Loading Screen" ))
		virtual void HideLoadingScreen();

		UFUNCTION(BlueprintImplementableEvent, meta=( DisplayName = "StarryHUD: Changed Free Cursor Mode" ))
		virtual void ChangedFreeCursorMode(bool FreeCursorMode);
	
};
