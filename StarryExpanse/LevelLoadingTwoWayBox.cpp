// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelLoadingTwoWayBox.h"
#include "Templates/SharedPointer.h"
#include "LoadGroups/LoadgroupActor.h"
#include "EngineUtils.h"

// Sets default values
ALevelLoadingTwoWayBox::ALevelLoadingTwoWayBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)

{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootComponent"));

	BoxA = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("BoxA"));
	BoxB = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("BoxB"));

	BoxA->SetupAttachment(RootComponent);
	BoxB->SetupAttachment(RootComponent);
	
	// Bind Delegates
	BLoaded_AfterIntersectATowardB.BindUFunction(this, "BLoaded_AfterIntersectATowardB");
	ALoaded_AfterBLoaded_AfterIntersectATowardB.BindUFunction(this, "ALoaded_AfterBLoaded_AfterIntersectATowardB");
	ALoaded_AfterIntersectAAwayFromB.BindUFunction(this, "ALoaded_AfterIntersectAAwayFromB");

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

// Called when the game starts or when spawned
void ALevelLoadingTwoWayBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelLoadingTwoWayBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelLoadingTwoWayBox::EnterATowardsB() {
	ALoadgroupActor *Queen;
	for (TActorIterator<ALoadgroupActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
		Queen = *ActorItr;
	}


//	Queen->LoadgroupLoadedEvent.Add();
	//Queen->LoadgroupLoadedEvent.Remove;
}