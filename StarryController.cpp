// Fill out your copyright notice in the Description page of Project Settings.

#include "StarryExpanse.h"
#include "StarryController.h"


AStarryController::AStarryController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FreeCursorMode = false;
}


void AStarryController::PostProcessInput(const float DeltaTime, const bool bGamePaused) {
	SetIgnoreLookInput(false);
	//APlayerController::PostProcessInput(DeltaTime, bGamePaused);
	if ( FreeCursorMode ) {
		RotationInput = FRotator::ZeroRotator;
	}
	
}

bool AStarryController::TrySwitchCursorMode() {
	FreeCursorMode = !FreeCursorMode;
	return FreeCursorMode;
}

bool AStarryController::TrySetCursorMode(bool bNewMode) {
	FreeCursorMode = bNewMode;
	return FreeCursorMode;
}

//void AStarryController::SetMousePosition(float LocationX, float LocationY) {
//	FViewport* v = CastChecked<ULocalPlayer>(this->Player)->ViewportClient->Viewport;
//	int intX = (int)LocationX;
//	int intY = (int)LocationY;
//	FIntPoint sz = v->GetSizeXY();
//	
//	FIntPoint x = v->ViewportToVirtualDesktopPixel(FVector2D(1,1));
//	v->SetMouse(x.X, x.Y);
//}

//EMouseCursor::Type APlayerController::GetMouseCursor() const {
//	return EMouseCursor::Default;
//}

