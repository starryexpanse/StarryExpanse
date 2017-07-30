// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelLoadingTwoWayBox.h"
#include "Templates/SharedPointer.h"
#include "LoadGroups/LoadgroupActor.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Classes/Components/CapsuleComponent.h"
#include "EngineUtils.h"
#include "StarryExpanse.h"

// Sets default values
ALevelLoadingTwoWayBox::ALevelLoadingTwoWayBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	auto DefaultSceneRoot = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("DefaultSceneRoot"));

	BoxA = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("BoxA"));
	BoxB = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("BoxB"));

	BoxA->SetupAttachment(DefaultSceneRoot);
	BoxB->SetupAttachment(DefaultSceneRoot);
	
	// Bind Delegates
	BLoaded_AfterIntersectATowardB.BindUFunction(this, "Cbk_BLoaded_AfterIntersectATowardB");
	ALoaded_AfterBLoaded_AfterIntersectATowardB.BindUFunction(this, "Cbk_ALoaded_AfterBLoaded_AfterIntersectATowardB");
	ALoaded_AfterIntersectAAwayFromB.BindUFunction(this, "Cbk_ALoaded_AfterIntersectAAwayFromB");
	ALoaded_AfterIntersectBTowardA.BindUFunction(this, "Cbk_ALoaded_AfterIntersectBTowardA");
	BLoaded_AfterALoaded_AfterIntersectBTowardA.BindUFunction(this, "Cbk_BLoaded_AfterALoaded_AfterIntersectBTowardA");
	BLoaded_AfterIntersectBAwayFromA.BindUFunction(this, "Cbk_BLoaded_AfterIntersectBAwayFromA");
}

void ALevelLoadingTwoWayBox::OnConstruction(const FTransform& Transform)
{
	AActor::OnConstruction(Transform);

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

// Intersect A Callbacks

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
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	Queen->LoadgroupLoadedEvent.Remove(ALoaded_AfterBLoaded_AfterIntersectATowardB);
}

void ALevelLoadingTwoWayBox::Cbk_ALoaded_AfterIntersectAAwayFromB() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	gameInstance->SetIsFrozenForLoading(false);
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	Queen->LoadgroupLoadedEvent.Remove(ALoaded_AfterIntersectAAwayFromB);
}

void ALevelLoadingTwoWayBox::IntersectATowardB() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	Queen->LoadgroupLoadedEvent.Add(this->BLoaded_AfterIntersectATowardB);
	Queen->LoadLoadGroup(this->BSideLoadGroup);
	UE_LOG(StarryDebug, Display, TEXT("Inter A toward B"));
}

void ALevelLoadingTwoWayBox::Cbk_IntersectA(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	auto Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (Character == nullptr) {
		return;
	}
	if (Cast<ACharacter>(OtherActor) != Character) {
		return;
	}
	auto Capsule = Character->GetCapsuleComponent();
	if (Capsule == nullptr || OtherComp == nullptr || Cast<UCapsuleComponent>(OtherComp) != Capsule) {
		return;
	}
	auto vel = OtherActor->GetVelocity();
	auto transform = this->GetTransform();
	auto velLocal = transform.TransformVector(vel);
	bool fromBToA = velLocal.Y >= 0;
	if (fromBToA) {
		this->IntersectAAwayFromB();
	}
	else {
		this->IntersectATowardB();
	}
}

void ALevelLoadingTwoWayBox::IntersectAAwayFromB() {
	UE_LOG(StarryDebug, Display, TEXT("Inter A away from B"));

	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;

	if (Queen->IsLoading()) {
		if (Queen->wantedLoadGroup == BSideLoadGroup) {
			bShouldRecycle = true;
			gameInstance->SetIsFrozenForLoading(true);
		}
		else if (Queen->wantedLoadGroup == ASideLoadGroup) {
			bShouldRecycle = false;
			gameInstance->SetIsFrozenForLoading(true);
		}
	}
	else if (Queen->currentLoadGroup == BSideLoadGroup) {
		gameInstance->SetIsFrozenForLoading(true);
		Queen->LoadgroupLoadedEvent.Add(ALoaded_AfterIntersectAAwayFromB);
		Queen->LoadLoadGroup(this->ASideLoadGroup);
	}
}

// Intersect B Callbacks

void ALevelLoadingTwoWayBox::Cbk_ALoaded_AfterIntersectBTowardA() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	Queen->LoadgroupLoadedEvent.Remove(ALoaded_AfterIntersectBTowardA);

	if (bShouldRecycle) {
		bShouldRecycle = false;
		Queen->LoadgroupLoadedEvent.Add(BLoaded_AfterALoaded_AfterIntersectBTowardA);
		Queen->LoadLoadGroup(this->BSideLoadGroup);
	}
	else {
		gameInstance->SetIsFrozenForLoading(false);
	}
}

void ALevelLoadingTwoWayBox::Cbk_BLoaded_AfterALoaded_AfterIntersectBTowardA() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	gameInstance->SetIsFrozenForLoading(false);
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	Queen->LoadgroupLoadedEvent.Remove(BLoaded_AfterALoaded_AfterIntersectBTowardA);
}

void ALevelLoadingTwoWayBox::Cbk_BLoaded_AfterIntersectBAwayFromA() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	gameInstance->SetIsFrozenForLoading(false);
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	Queen->LoadgroupLoadedEvent.Remove(BLoaded_AfterIntersectBAwayFromA);
}

void ALevelLoadingTwoWayBox::IntersectBTowardA() {
	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
	Queen->LoadgroupLoadedEvent.Add(this->ALoaded_AfterIntersectBTowardA);
	Queen->LoadLoadGroup(this->ASideLoadGroup);
	UE_LOG(StarryDebug, Display, TEXT("Inter B toward A"));
}

void ALevelLoadingTwoWayBox::Cbk_IntersectB(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	auto Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (Character == nullptr) {
		return;
	}
	if (Cast<ACharacter>(OtherActor) != Character) {
		return;
	}
	auto Capsule = Character->GetCapsuleComponent();
	if (Capsule == nullptr || OtherComp == nullptr || Cast<UCapsuleComponent>(OtherComp) != Capsule) {
		return;
	}
	auto vel = OtherActor->GetVelocity();
	auto transform = this->GetTransform();
	auto velLocal = transform.TransformVector(vel);
	bool fromBToA = velLocal.Y >= 0;
	if (fromBToA) {
		this->IntersectBTowardA();
	}
	else {
		this->IntersectBAwayFromA();
	}
}

void ALevelLoadingTwoWayBox::IntersectBAwayFromA() {
	UE_LOG(StarryDebug, Display, TEXT("Inter B away from A"));

	auto gameInstance = (URivenGameInstance*)GetWorld()->GetGameInstance();
	ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;

	if (Queen->IsLoading()) {
		if (Queen->wantedLoadGroup == ASideLoadGroup) {
			bShouldRecycle = true;
			gameInstance->SetIsFrozenForLoading(true);
		}
		else if (Queen->wantedLoadGroup == BSideLoadGroup) {
			bShouldRecycle = false;
			gameInstance->SetIsFrozenForLoading(true);
		}
	}
	else if (Queen->currentLoadGroup == ASideLoadGroup) {
		gameInstance->SetIsFrozenForLoading(true);
		Queen->LoadgroupLoadedEvent.Add(BLoaded_AfterIntersectBAwayFromA);
		Queen->LoadLoadGroup(this->BSideLoadGroup);
	}
}