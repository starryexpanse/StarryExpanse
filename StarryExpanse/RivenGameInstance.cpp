// Fill out your copyright notice in the Description page of Project Settings.

#include "RivenGameInstance.h"
#include "LoadGroups/LoadgroupActor.h"
#include "Engine/Engine.h"


void URivenGameInstance::SetIsFrozenForLoading(bool newFrozen) {
  bool changed = newFrozen != this->bIsFrozenForLoading;
  this->bIsFrozenForLoading = newFrozen;
  if (changed) {
    FrozenForLoadingChangedEvent.Broadcast();
  }
}

void URivenGameInstance::RegisterLoadgroupQueen(ALoadgroupActor* newQueen) {
  this->LoadgroupQueen = newQueen;
}

void URivenGameInstance::RegisterSaveGameBlocker(FName blockerName) {
	OutstandingSaveGameBlockers.insert(blockerName);
}

void URivenGameInstance::UnregisterSaveGameBlocker(FName blockerName) {
	OutstandingSaveGameBlockers.erase(blockerName);
}

void URivenGameInstance::SetInteractableState(EInteractable interactable, float state) {
  switch (interactable) {
  case EInteractable::T_FissurePlateau_Lever:
    m_fissurePlateauLeverState = state;
    break;
  }
  UEngine* engine = GetEngine();
  if (engine) {
    FString name = GetInteractableEnumAsString(interactable);
    // this is a kludge - can't figure out how to use FString::Printf with a FString type.
    FString msg = "Just set \"";
    msg += name;
    msg += FString::Printf(TEXT("\" to %f."), state);
    engine->AddOnScreenDebugMessage(INDEX_NONE, 15.0, FColor::Yellow, msg);
  }
}

float URivenGameInstance::GetInteractableState(EInteractable interactable) {
  switch (interactable) {
  case EInteractable::T_FissurePlateau_Lever:
    return m_fissurePlateauLeverState;
  }
  return -1.0;
}