//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#include "RivenInteractable.h"

URivenInteractable::URivenInteractable(
    const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {}

void IRivenInteractable::LookingAt_Implementation() {}

void IRivenInteractable::Touched_Implementation() {}

FInteractabilityProbeResponse IRivenInteractable::PollInteractability_Implementation() {
  return FInteractabilityProbeResponse::BasicResponse();
}

