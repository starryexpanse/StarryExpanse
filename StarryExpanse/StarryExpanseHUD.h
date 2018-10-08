// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "StarryExpanseHUD.generated.h"

UCLASS()
class AStarryExpanseHUD : public AHUD {
  GENERATED_BODY()

public:
  AStarryExpanseHUD();

  static FVector2D GetCrosshairDrawPosition(FVector2D crosshairDims,
                                            FVector2D screenDims,
                                            FVector2D cursorPosition);

  UFUNCTION()
  UTexture2D *GetCursorTexture(FVector2D screenDims, FVector2D cursorPosition);

  /** Primary draw call for the HUD */
  virtual void DrawHUD() override;

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  UWidget* GetLoadingGuiWidget();

private:
  /** Crosshair asset pointer */
  class UTexture2D *TexHollowRing;
  class UTexture2D *TexDot;
  class UTexture2D *TexZoomOut;
};
