//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Object.h"
#include "Structs/InteractabilityProbeResponse.h"
#include "Structs/DragCallbackPreferences.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/CoreUObject/Public/UObject/Interface.h"
#include "RivenInteractable.generated.h"

// https://wiki.unrealengine.com/Blueprints,_Empower_Your_Entire_Team_With_BlueprintImplementableEvent
// https://wiki.unrealengine.com/Interfaces_in_C%2B%2B

UINTERFACE()
class STARRYEXPANSE_API URivenInteractable : public UInterface {
  GENERATED_BODY()
};

class IRivenInteractable {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  void LookingAt_Begin(FHitResult HitInfo);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  void LookingAt_End();

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  void Touched();

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  FDragCallbackPreferences Drag_Begin(FHitResult HitInfo, FVector2D Origin,
                                      AActor *DragOwner);

  // This will be called if the drag callback preferences specify that extra
  // details are wanted,
  // before every call to Drag_Update.
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  void Extra_Drag_Details_Available(FHitResult HitInfo);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  void Drag_Update(FVector2D Origin, FVector2D SmallDelta,
                   FVector2D OverallDelta);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  void Drag_Finished(FHitResult HitInfo, FVector2D Origin, FVector2D SmallDelta,
                     FVector2D OverallDelta, bool WasDragCanceled);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
  FInteractabilityProbeResponse ProbeInteractability();
};