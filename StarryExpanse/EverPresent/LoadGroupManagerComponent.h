#pragma once
#include "Config/ELoadGroups.h"
#include "LoadGroupManagerComponent.generated.h"

UCLASS(Blueprintable, Config = Game)
class ULoadGroupManagerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Class Constructor
    ULoadGroupManagerComponent();

    UFUNCTION(Category = "Callbacks")
    void LevelLoaded();

    void LoadLoadGroup();
};
