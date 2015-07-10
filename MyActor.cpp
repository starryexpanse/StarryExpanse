// Fill out your copyright notice in the Description page of Project Settings.

#include "StarryExpanse.h"
#include "MyActor.h"


AMyActor::AMyActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void AMyActor::BeginPlay() {
	FLatentActionInfo fli;
	UGameplayStatics::LoadStreamLevel(this, FName(TEXT("J_Basin")), true, true, fli);
}