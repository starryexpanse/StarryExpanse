#pragma once

#include "Engine/UserDefinedEnum.h"
#include "EActionTypes.generated.h"

UENUM(BlueprintType)
enum class EActionTypes : uint8
{
    SURVEY_ELEVATOR_GOING_DOWN,
    SURVEY_ELEVATOR_GOING_UP,
};
