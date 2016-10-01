#pragma once
#include "Config/ELoadGroups.h"
#include "EverpresentLoadGroupManager.generated.h"

/* Class Declaration */
UCLASS(Blueprintable, Config = Game)
class AEverpresentLoadGroupManager : public AActor
{
    GENERATED_BODY()

public:
    // Class Constructor
    AEverpresentLoadGroupManager();

    // Public Methods
    void NotifyOfOverlapBegin();
    void NotifyOfOverlapEnd();

    UFUNCTION(BlueprintCallable, Category="LoadGroups")
    void LoadLoadGroup(ELoadGroups LoadGroup);
private:
    // Private Methods

    // Private Fields

};
