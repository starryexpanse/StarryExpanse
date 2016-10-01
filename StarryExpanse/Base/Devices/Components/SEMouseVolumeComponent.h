#pragma once

#include "SEMouseVolumeComponent.generated.h"

UCLASS()
class STARRYEXPANSE_API USEMouseVolumeComponent : public USphereComponent
{
   GENERATED_BODY()

public:
   USEMouseVolumeComponent();

   UFUNCTION()
   void OnBeginCursorOver_Callback(UPrimitiveComponent *TouchedComponent);
   UFUNCTION()
   void OnEndCursorOver_Callback(UPrimitiveComponent *TouchedComponent);

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = Devices)
   bool HasCursorOver() { return bHasCursorOver; }

   UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Device Cursors")
   UTexture2D *HoverTexture;
   UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Device Cursors")
   UTexture2D *ClickTexture;

private:
   bool bHasCursorOver;
};
