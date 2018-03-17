//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#include "RivenInteractable.h"

URivenInteractable::URivenInteractable(
    const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {}

void IRivenInteractable::LookingAt_Begin_Implementation() {}

void IRivenInteractable::LookingAt_End_Implementation() {}

void IRivenInteractable::Drag_Update_Implementation(FVector2D Origin, FVector2D SmallDelta, FVector2D OverallDelta) {}

FDragCallbackPreferences IRivenInteractable::Drag_Begin_Implementation(FHitResult HitInfo, FVector2D Origin, AActor* DragOwner) {
  return FDragCallbackPreferences::ModerateDelay_Simple();
}

void IRivenInteractable::Extra_Drag_Details_Available_Implementation(FHitResult HitInfo) {}

void IRivenInteractable::Drag_Finished_Implementation(FHitResult HitInfo, FVector2D Origin, FVector2D SmallDelta, FVector2D OverallDelta, bool WasDragCanceled) {}

void IRivenInteractable::Touched_Implementation() {}

FInteractabilityProbeResponse IRivenInteractable::ProbeInteractability_Implementation() {
  return FInteractabilityProbeResponse::BasicResponse();
}

