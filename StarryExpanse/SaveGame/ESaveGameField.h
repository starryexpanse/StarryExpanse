// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "ESaveGameField.generated.h"


UENUM(BlueprintType)
enum class ESaveGameField : uint8
{
	/*
	[[[cog
		import cog
		from rivensavegame_generator import vars, p

		for var in vars:
			p('%s,' % (var[1],))
	]]] */
	CurrentLoadGroup,
	CurrentMarionettist,
	CurrentZoomedLinkingBookIsOpen,
	GehnIsTrapped,
	HaveTrapBook,
	CatherineIsFree,
	CharacterTransform,
	TelescopeCodeA,
	TelescopeCodeB,
	TelescopeCodeC,
	TelescopeCodeD,
	TelescopeCodeE,
	PrisonCodeA,
	PrisonCodeB,
	PrisonCodeC,
	PrisonCodeD,
	PrisonCodeE,
	DomeCodeA,
	DomeCodeB,
	DomeCodeC,
	DomeCodeD,
	DomeCodeE,
	SubPosRot,
	J_SeenCreepyGirl,
	J_WahrkElevatorPosition,
	O_OvenIsOn,
	O_CageIsUp,
	O_TimesGehnSignaled,
	T_NewTemple_DoorMain_Open,
	T_NewTemple_DoorSide_Open,
	T_FissurePlateau_CageLever_Closed,
	T_FissurePlateau_ChoStillPassedOut,
	S_SeenScribe,
	B_GehnHasVisited,
	// [[[end]]]
	
};
