// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "StarryController.generated.h"

/**
 * 
 */
UCLASS()
class STARRYEXPANSE_API AStarryController : public APlayerController
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool FreeCursorMode;

	UFUNCTION(BlueprintCallable, Category = "Game|Player")
	bool TrySwitchCursorMode();

	UFUNCTION(BlueprintCallable, Category = "Game|Player")
	bool TrySetCursorMode(bool bNewMode);

	//UFUNCTION(BlueprintCallable, Category = "Game|Player")
	//void SetMousePosition(float LocationX, float LocationY);

	//virtual EMouseCursor::Type GetMouseCursor() const;

protected:

	virtual void PostProcessInput(const float DeltaTime, const bool bGamePaused) override;
	
};
