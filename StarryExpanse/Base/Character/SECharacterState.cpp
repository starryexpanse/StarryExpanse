#include "StarryExpanse.h"
#include "SECharacter.h"
#include "SECharacterState.h"

ASECharacterState::ASECharacterState() : Super()
{
    // TODO(philip): Should this be in BeginPlay?
    #if WITH_EDITOR
      CursorState = ECharacterCursorState::Uncontrolled;
    #else
        CursorState = ECharacterCursorState::Locked;
    #endif
}
