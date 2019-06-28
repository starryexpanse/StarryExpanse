#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "VRHUD.generated.h"

UCLASS()
class AVRHUD : public AHUD {
  GENERATED_BODY()

public:
  AVRHUD();

  virtual void DrawHUD() override;

private:
  class UTexture2D *CrosshairTex;
};
