// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EMarionettist.generated.h"
#include "Engine/UserDefinedEnum.h"

UENUM(BlueprintType)
enum class EMarionettist : uint8 {
  NoMarionettist,

  /* O Marionettists */
  OLadder,
  OStove,
  OCanen,
  OLinkingBookP,
  OLinkingBookJ,
  OLinkingBookG,
  OLinkingBookB,
  OLinkingBookT,

  /* J Marionettists */
  JVillageLadder1,
  JVillageLadder2,
  JSubmarine,
  JTMagLev UMETA(DisplayName = "MagLev (Jungle <-> Temple)")
};
