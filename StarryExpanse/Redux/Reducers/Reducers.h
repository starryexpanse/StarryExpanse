#include "../ReduxState.h"
#include "../Actions/Action.h"

ReduxState handleSurveyElevatorGoingDown(ReduxState state, const SurveyElevatorGoingDownAction& action) {
    state.SurveyElevatorWasLastStoppedAtUpperLevel = true;
    state.SurveyElevatorIsMoving = true;
    return state;
}

ReduxState handleSurveyElevatorGoingUp(ReduxState state, const SurveyElevatorGoingUpAction& action) {
    state.SurveyElevatorWasLastStoppedAtUpperLevel = false;
    state.SurveyElevatorIsMoving = true;
    return state;
}

ReduxState surveyReducer(ReduxState state, const Action& action) {
    switch(action.type) {
        case EActionTypes::SURVEY_ELEVATOR_GOING_DOWN:
            return handleSurveyElevatorGoingDown(
                state,
                static_cast<const SurveyElevatorGoingDownAction&>(action)
            );
        case EActionTypes::SURVEY_ELEVATOR_GOING_UP:
            return handleSurveyElevatorGoingUp(
                state,
                static_cast<const SurveyElevatorGoingUpAction&>(action)
            );
    }
    return state;
}
