#pragma once

#include "Base/ReduxSupport/Store.h"
#include "Redux/ReduxState.h"
#include "Redux/Actions/Action.h"

#include "ReduxActor.generated.h"

UCLASS(Blueprintable, Config = Game)
class AReduxActor : public AActor
{
    GENERATED_BODY()

public:
    AReduxActor();
    virtual void BeginPlay() override;
    Store<ReduxState, Action> myStore;

};
