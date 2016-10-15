#pragma once

#include "EActionTypes.h"

struct Action
{
    EActionTypes type;
    Action (EActionTypes myType): type(myType) {}
};

struct SurveyElevatorGoingDownAction : Action
{
    SurveyElevatorGoingDownAction() : Action(EActionTypes::SURVEY_ELEVATOR_GOING_DOWN)
    {
    }
};

struct SurveyElevatorGoingUpAction : Action
{
    SurveyElevatorGoingUpAction() : Action(EActionTypes::SURVEY_ELEVATOR_GOING_UP)
    {
    }
};
