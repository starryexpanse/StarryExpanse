// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "EInventoryItem.generated.h"

UENUM(BlueprintType)
enum class EInventoryItem : uint8
{
	AtrusJournal,
	CatherineJournal,
	TrapBook
};