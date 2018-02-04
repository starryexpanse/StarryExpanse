//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#include "RivenInteractable.h"

URivenInteractable::URivenInteractable(
    const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {}

void IRivenInteractable::LookingAt_Implementation() {}

void IRivenInteractable::Touched_Implementation() {}

FInteractabilityPollResponse IRivenInteractable::PollInteractability_Implementation() {
  return FInteractabilityPollResponse::BasicResponse();
}

