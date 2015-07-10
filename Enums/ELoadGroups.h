// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "ELoadGroups.generated.h"


UENUM(BlueprintType)
enum class ELoadGroups : uint8
{
	JVillageVista UMETA(DisplayName = "Jungle Village Vista"),
	JPrisonInterior UMETA(DisplayName = "Jungle Prison Interior")
};