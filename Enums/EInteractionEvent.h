// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "EInteractionEvent.generated.h"

UENUM(BlueprintType)
enum class EInteractionEvent : uint8
{
	Tap,
	DragStart,
	DragRelease
};