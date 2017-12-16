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

  /** Primary draw call for the HUD */
  virtual void DrawHUD() override;

private:
  /** Crosshair asset pointer */
  class UTexture2D *CrosshairTex;
};
