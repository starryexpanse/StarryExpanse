
#pragma once

#include "Engine/UserDefinedEnum.h"

// https://wiki.unrealengine.com/Enums_For_Both_C%2B%2B_and_BP

// Any game item that can be interacted with (directly or indirectly)
// in the game.
UENUM(BlueprintType)
enum class EInteractable : uint8 {
  T_FissurePlateau_Lever UMETA(DisplayName = "T_FissurePlateau_Lever"),
  T_Telescope_Lever UMETA(DisplayName = "T_Telescope_Lever"),
};

FString GetInteractableEnumAsString(EInteractable interactable);