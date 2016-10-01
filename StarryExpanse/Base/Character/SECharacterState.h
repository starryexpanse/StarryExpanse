#pragma once

#include "GameFramework/PlayerState.h"
#include "SECharacterState.generated.h"

/* Forward Declarations */
enum class ECharacterCursorState : uint8;

/* Class Declaration */
UCLASS(Config = Game)
class STARRYEXPANSE_API ASECharacterState : public APlayerState
{
	GENERATED_BODY()
	
public:
	/* Class Contructor */
	ASECharacterState();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "StarryExpanse|Character|Input")
	ECharacterCursorState	CursorState;
};
