// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "EInteractionCue.generated.h"


UENUM(BlueprintType)
enum class EInteractionCue : uint8
{
	NotInteractible,
	Clickable,
	Grabbable,
	ClimbableDown,
	ClimbableUp,
	ZoomIn,
	ZoomOut,
	TurnPageRight,
	TurnPageLeft,
	Zip
};