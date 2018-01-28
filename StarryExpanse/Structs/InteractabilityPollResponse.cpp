//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//

#include "InteractabilityPollResponse.h"

FInteractabilityPollResponse FInteractabilityPollResponse::BasicResponse() {
  FInteractabilityPollResponse response;

  response.CanBeDragged = false;
  response.DragAxisObjectSpace = FVector::ZeroVector;
  response.Zoomyness = 0;
  response.ShouldScanAtComponentLevel = false;

  return response;
}