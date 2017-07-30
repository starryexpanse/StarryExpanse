// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelLoadingTwoWayBox.h"
#include "Templates/SharedPointer.h"
#include "LoadGroups/LoadgroupActor.h"
#include "EngineUtils.h"

// Sets default values
ALevelLoadingTwoWayBox::ALevelLoadingTwoWayBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)

{
	RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootComponent"));

	BoxA = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("BoxA"));
	BoxB = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("BoxB"));

	BoxA->SetupAttachment(RootComponent);
	BoxB->SetupAttachment(RootComponent);
	
	// Bind Delegates
	BLoaded_AfterIntersectATowardB.BindUFunction(this, "Cbk_BLoaded_AfterIntersectATowardB");
	ALoaded_AfterBLoaded_AfterIntersectATowardB.BindUFunction(this, "Cbk_ALoaded_AfterBLoaded_AfterIntersectATowardB");
	ALoaded_AfterIntersectAAwayFromB.BindUFunction(this, "Cbk_ALoaded_AfterIntersectAAwayFromB");

}

void ALevelLoadingTwoWayBox::OnConstruction(const FTransform& Transform)
{
	//AActor::OnConstruction(Transform);

	auto PlayerDiameter = 40; // from Character configuration
	auto playerLocalScale = PlayerDiameter / this->GetActorTransform().GetScale3D().Y;
	Separation = FMath::Max(Separation, playerLocalScale);

	auto extent = FVector(90, 0.15, 300);
	BoxA->SetBoxExtent(extent);
	BoxA->RelativeLocation = FVector(0, -Separation, 0);

	BoxB->SetBoxExtent(extent);
	BoxB->RelativeLocation = FVector(0, Separation, 0);
}

void ALevelLoadingTwoWayBox::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	BoxA->OnComponentBeginOverlap.AddDynamic(this, &ALevelLoadingTwoWayBox::Cbk_IntersectA);
	BoxB->OnComponentBeginOverlap.AddDynamic(this, &ALevelLoadingTwoWayBox::Cbk_IntersectB);
}

// Called when the game starts or when spawned
void ALevelLoadingTwoWayBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALevelLoadingTwoWayBox::Cbk_BLoaded_AfterIntersectATowardB() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	Queen->LoadgroupLoadedEvent.Remove(BLoaded_AfterIntersectATowardB);

	if (bShouldRecycle) {
		bShouldRecycle = false;
		Queen->LoadgroupLoadedEvent.Add(ALoaded_AfterBLoaded_AfterIntersectATowardB);
		Queen->LoadLoadGroup(this->ASideLoadGroup);
	} else {
		gameInstance->SetIsFrozenForLoading(false);
	}
}

void ALevelLoadingTwoWayBox::Cbk_ALoaded_AfterBLoaded_AfterIntersectATowardB() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	gameInstance->SetIsFrozenForLoading(false);
}

void ALevelLoadingTwoWayBox::IntersectATowardB() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	Queen->LoadgroupLoadedEvent.Add(this->BLoaded_AfterIntersectATowardB);
	Queen->LoadLoadGroup(this->BSideLoadGroup);
}

void ALevelLoadingTwoWayBox::Cbk_ALoaded_AfterIntersectAAwayFromB() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	gameInstance->SetIsFrozenForLoading(false);
}

void ALevelLoadingTwoWayBox::IntersectAAwayFromB() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	
	if (Queen->IsLoading()) {
		if (Queen->wantedLoadGroup == BSideLoadGroup) {
			bShouldRecycle = true;
			gameInstance->SetIsFrozenForLoading(true);
		} else if (Queen->wantedLoadGroup == ASideLoadGroup) {
			bShouldRecycle = false;
			gameInstance->SetIsFrozenForLoading(true);
		}
	} else if (Queen->currentLoadGroup == BSideLoadGroup) {
		gameInstance->SetIsFrozenForLoading(true);
		Queen->LoadgroupLoadedEvent.Add(ALoaded_AfterIntersectAAwayFromB);
		Queen->LoadLoadGroup(this->ASideLoadGroup);
	}
}

void ALevelLoadingTwoWayBox::Cbk_IntersectA(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

}

void ALevelLoadingTwoWayBox::Cbk_IntersectB(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

}