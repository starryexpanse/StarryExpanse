// Fill out your copyright notice in the Description page of Project Settings.

#include "RivenGameInstance.h"
#include "LoadGroups/LoadgroupActor.h"

	
void URivenGameInstance::SetFrozenForLoading(bool newFrozen) {
	bool changed = newFrozen != this->bIsFrozenForLoading;
	this->bIsFrozenForLoading = newFrozen;
	if (changed) {
		FrozenForLoadingChangedEvent.Broadcast();
	}
}

void URivenGameInstance::RegisterLoadgroupQueen(ALoadgroupActor* newQueen) {
	this->LoadgroupQueen = newQueen;
}