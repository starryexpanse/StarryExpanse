#include "StarryExpanse.h"
#include "ReduxActor.h"
#include "Redux/Reducers/Reducers.h"

/* Class constructor */
AReduxActor::AReduxActor() : Super()
{

}

void AReduxActor::BeginPlay() {
  // Set up Redux store
  myStore.dispatcher->registerReducer(surveyReducer);
}
