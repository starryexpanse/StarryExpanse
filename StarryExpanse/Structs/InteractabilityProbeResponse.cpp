//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#include "InteractabilityProbeResponse.h"
#include "Enums/EZoomCue.h"

FInteractabilityProbeResponse FInteractabilityProbeResponse::NotInteractableResponse() {
  FInteractabilityProbeResponse response;

  response.CanBeTapped = false;
  response.CanBeDragged = false;
  response.DragAxisObjectSpace = FVector::ZeroVector;
  response.ZoomCue = EZoomCue::NoZoom;
  response.ShouldScanAtComponentLevel = false;

  return response;
}

FInteractabilityProbeResponse FInteractabilityProbeResponse::BasicResponse() {
  FInteractabilityProbeResponse response;

  response.CanBeTapped = true;
  response.CanBeDragged = false;
  response.DragAxisObjectSpace = FVector::ZeroVector;
  response.ZoomCue = EZoomCue::NoZoom;
  response.ShouldScanAtComponentLevel = false;

  return response;
}