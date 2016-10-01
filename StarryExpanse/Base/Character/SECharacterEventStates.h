#pragma once
#include "SECharacterEventStates.generated.h"

/* List of all possible states that the character can be in */
UENUM(BlueprintType)
enum class ECharacterState : uint8
{
   // Idle:      Not interacting with anything, basic movement allowed
   Idle         UMETA(DisplayName = "Idle"),
   // Observing:   Interacting with an object, and unable to move (ie. zooming)
   Observing      UMETA(DisplayName = "Observing"),
   // Reading:      Interacting with a book or journal, unable to move (ie. UI stuff)
   Reading         UMETA(DisplayName = "Reading"),
   // Linking:      Teleporting to another age
   Linking         UMETA(DisplayName = "Linking")
};

UENUM(BlueprintType)
enum class ECharacterZoomState : uint8
{
   // None:      Not zoomed in to anything
   None         UMETA(DisplayName = "None"),
   // Inward:      Character wants to zoom in
   Inward         UMETA(DisplayName = "Inward"),
   // Outward:      Character wants to zoom out
   Outward         UMETA(DisplayName = "Outward"),
};

UENUM(BlueprintType)
enum class ECharacterCursorState : uint8
{
   // Uncontrolled: Cursor is not controlled at all by the engine
   Uncontrolled    UMETA(DisplayName = "Uncontrolled"),

   // Locked: Cursor is locked to the center of the screen
   Locked         UMETA(DisplayName = "Locked"),

   // Free: View is locked, but cursor can roam freely
   Free         UMETA(DisplayName = "Free")
};

/* List of all possible character-based events that other classes can listen for */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSECharacterStateChanged, ECharacterState, NewState);
