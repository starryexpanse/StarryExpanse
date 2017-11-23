//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//
#include "Actors/EInteractable.h"

FString GetInteractableEnumAsString(EInteractable interactable)
{
  const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EInteractable"), true);
  if (!EnumPtr) return FString("Invalid");

  return EnumPtr->GetNameByValue((int64)interactable).ToString();
}