// Fill out your copyright notice in the Description page of Project Settings.

#include "StarryExpanse.h"
#include "InteractionInfo.h"


UInteractionInfo* UInteractionInfo::MakeInteractionInfo(TEnumAsByte<EInteractionEvent> evt) {

	UInteractionInfo* x = new UInteractionInfo;
	return x;
}
