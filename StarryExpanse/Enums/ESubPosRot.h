// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "ESubPosRot.generated.h"


UENUM(BlueprintType)
enum class ESubPosRot : uint8
{
	Plat_N UMETA(DisplayName = "Plateau looking North"),
	Plat_S UMETA(DisplayName = "Plateau looking South"),
	N1_N UMETA(DisplayName = "Node 1 looking North"),
	N1_S UMETA(DisplayName = "Node 2 looking South"),
	N2_E UMETA(DisplayName = "Node 2 looking East"),
	N2_W UMETA(DisplayName = "Node 2 looking West"),
	N3_E UMETA(DisplayName = "Node 3 looking East"),
	N3_W  UMETA(DisplayName = "Node 2 looking East"),
	N4_N  UMETA(DisplayName = "Node 4 looking North"),
	N4_S  UMETA(DisplayName = "Node 4 looking South"),
	N5_N  UMETA(DisplayName = "Node 5 looking North"),
	N5_S  UMETA(DisplayName = "Node 5 looking South"),
	N6_E  UMETA(DisplayName = "Node 6 looking East"),
	N6_W  UMETA(DisplayName = "Node 6 looking West"),
	N7_N  UMETA(DisplayName = "Node 7 looking North"),
	N7_S  UMETA(DisplayName = "Node 7 looking South")
};

