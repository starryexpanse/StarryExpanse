#pragma once
#include "SEGlobalEventStates.generated.h"

/* List of all possible global states */
// (None currently)

/* List of all possible generic events that other classes can listen for */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSEActorInitializedEvent, AActor*, Actor, UClass*, ActorClass);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSEActorClickedEvent, AActor*, Actor, UClass*, ActorClass);

/* Class definition */
UCLASS()
class USEGlobalEventStates : public UObject
{
	GENERATED_BODY()

public:
	static FSEActorInitializedEvent OnActorInitialized;
	static FSEActorClickedEvent OnActorClicked;
};