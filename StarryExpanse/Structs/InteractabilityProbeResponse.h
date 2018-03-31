//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Enums/EInteractable.h"
#include "CoreMinimal.h"
#include "Enums/EZoomCue.h"
#include "InteractabilityProbeResponse.generated.h"

USTRUCT(BlueprintType)
struct FInteractabilityProbeResponse {
  GENERATED_BODY()

  static FInteractabilityProbeResponse NotInteractableResponse();
  static FInteractabilityProbeResponse BasicResponse();

  // Truth here indicates that this struct is not necessarily accurate
  // at the actor level, and a poll should be performed using the actual
  // components.
  // Currently not implemented, but might be nice for Artist Engine Specialists.
  // TODO(philip)
  UPROPERTY(BlueprintReadWrite)
  bool ShouldScanAtComponentLevel = false;

  UPROPERTY(BlueprintReadWrite)
  bool CanBeDragged = false;

  UPROPERTY(BlueprintReadWrite)
  bool CanBeTapped = false;

  // -1 = zooming out;
  //  0 = not zooming;
  // +1 = zooming in
  UPROPERTY(BlueprintReadWrite)
  EZoomCue ZoomCue = EZoomCue::NoZoom;

  // Should be FVector::ZeroVector if no drag axis
  UPROPERTY(BlueprintReadWrite)
  FVector DragAxisObjectSpace = FVector::ZeroVector;
};