#pragma once
#include "GameFramework/HUD.h"
#include "SEHUD.generated.h"

USTRUCT(BlueprintType)
struct FSECursorTexture
{
   GENERATED_BODY()

public:

   UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
   UTexture2D *Texture;
   UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
   FVector2D HotSpot;
};

UCLASS()
class ASEHUD : public AHUD
{
   GENERATED_BODY()

public:
   ASEHUD();

   /* Primary draw call for the HUD */
   virtual void DrawHUD() override;

   /* Public Member Functions */
   UTexture2D *GetCursorTexture();
   void SetCursorTexture(UTexture2D *Texture);
   void SetCursorOpacity(float Opacity);

private:
   /* Cursor asset */
   FSECursorTexture CursorTexture;
   float CursorOpacity;
};
