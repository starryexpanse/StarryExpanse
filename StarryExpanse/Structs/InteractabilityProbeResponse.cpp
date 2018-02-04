//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//

#include "InteractabilityPollResponse.h"

FInteractabilityProbeResponse FInteractabilityProbeResponse::BasicResponse() {
  FInteractabilityProbeResponse response;

  response.CanBeDragged = false;
  response.DragAxisObjectSpace = FVector::ZeroVector;
  response.Zoomyness = 0;
  response.ShouldScanAtComponentLevel = false;

  return response;
}