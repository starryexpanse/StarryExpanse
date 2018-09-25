// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelLoadingTwoWayBox.h"
#include "Classes/Components/CapsuleComponent.h"
#include "EngineUtils.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "LoadGroups/LoadgroupActor.h"
#include "StarryExpanse.h"
#include "Templates/SharedPointer.h"

auto HitSphereComponentName = FString("LoadgroupHitSphere");

// Sets default values
ALevelLoadingTwoWayBox::ALevelLoadingTwoWayBox(
    const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {
  auto DefaultSceneRoot =
      ObjectInitializer.CreateDefaultSubobject<USceneComponent>(
          this, TEXT("DefaultSceneRoot"));

  MainBox = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(
      this, TEXT("Box"));
  BoxA = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this,
                                                                 TEXT("BoxA"));
  BoxB = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this,
                                                                 TEXT("BoxB"));

  MainBox->SetupAttachment(DefaultSceneRoot);
  BoxA->SetupAttachment(DefaultSceneRoot);
  BoxB->SetupAttachment(DefaultSceneRoot);

  // Bind Delegates
  BLoaded_AfterIntersectFromA.BindUFunction(this,
                                            "Cbk_BLoaded_AfterIntersectFromA");
  BLoaded_AfterALoaded_AfterIntersectFromB.BindUFunction(
      this, "Cbk_BLoaded_AfterALoaded_AfterIntersectFromB");
  BLoaded_AfterLeaveToB.BindUFunction(this, "Cbk_BLoaded_AfterLeaveToB");
  ALoaded_AfterBLoaded_AfterIntersectFromA.BindUFunction(
      this, "Cbk_ALoaded_AfterBLoaded_AfterIntersectFromA");
  ALoaded_AfterIntersectFromB.BindUFunction(this,
                                            "Cbk_ALoaded_AfterIntersectFromB");
  ALoaded_AfterLeaveToA.BindUFunction(this, "Cbk_ALoaded_AfterLeaveToA");
}

void ALevelLoadingTwoWayBox::OnConstruction(const FTransform &Transform) {
  AActor::OnConstruction(Transform);

  auto PlayerDiameter = 40; // from Character configuration
  auto playerLocalScale = PlayerDiameter / GetActorTransform().GetScale3D().Y;
  Separation = FMath::Max(Separation, playerLocalScale);

  MainBox->SetBoxExtent(FVector(90, Separation, 300));
  MainBox->RelativeLocation = FVector::ZeroVector;

  auto outerBoxPosition = Separation + playerLocalScale;
  auto extent = FVector(90, playerLocalScale, 300);
  BoxA->SetBoxExtent(extent);
  BoxA->RelativeLocation = FVector(0, -outerBoxPosition, 0);

  BoxB->SetBoxExtent(extent);
  BoxB->RelativeLocation = FVector(0, outerBoxPosition, 0);
}

void ALevelLoadingTwoWayBox::PostInitializeComponents() {
  Super::PostInitializeComponents();
  MainBox->OnComponentBeginOverlap.AddDynamic(
      this, &ALevelLoadingTwoWayBox::Cbk_Intersect);
  MainBox->OnComponentEndOverlap.AddDynamic(this,
                                            &ALevelLoadingTwoWayBox::Cbk_Leave);
}

// Called when the game starts or when spawned
void ALevelLoadingTwoWayBox::BeginPlay() { Super::BeginPlay(); }

void ALevelLoadingTwoWayBox::Cbk_Intersect(
    UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
    UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult &SweepResult) {
  auto Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
  if (Character == nullptr || Cast<ACharacter>(OtherActor) != Character) {
    return;
  }
  auto Capsule = Character->GetCapsuleComponent();
  if (OtherComp == nullptr || OtherComp->GetName() != HitSphereComponentName) {
    return;
  }
  auto vel = OtherActor->GetVelocity();
  auto transform = GetTransform();
  auto velLocal = transform.TransformVector(vel);
  bool toRight = velLocal.Y >= 0;
  if (toRight) {
    IntersectFromA();
  } else {
    IntersectFromB();
  }
}

void ALevelLoadingTwoWayBox::Cbk_Leave(UPrimitiveComponent *OverlappedComponent,
                                       AActor *OtherActor,
                                       UPrimitiveComponent *OtherComp,
                                       int32 OtherBodyIndex) {
  auto Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
  if (Character == nullptr || Cast<ACharacter>(OtherActor) != Character) {
    return;
  }
  auto Capsule = Character->GetCapsuleComponent();
  if (OtherComp == nullptr || OtherComp->GetName() != HitSphereComponentName) {
    return;
  }
  auto vel = OtherActor->GetVelocity();
  auto transform = GetTransform();
  auto velLocal = transform.TransformVector(vel);
  bool toB = velLocal.Y >= 0;
  if (toB) {
    LeaveToB();
  } else {
    LeaveToA();
  }
}

// Left to right flow

void ALevelLoadingTwoWayBox::IntersectFromA() {
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  Queen->LoadgroupLoadedEvent.Add(BLoaded_AfterIntersectFromA);
  Queen->LoadLoadGroup(BSideLoadGroup);
  UE_LOG(StarryDebug, Display, TEXT("Intersect from A"));
}

void ALevelLoadingTwoWayBox::Cbk_BLoaded_AfterIntersectFromA() {
  UE_LOG(StarryDebug, Display, TEXT("B loaded after intersect from A"));
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  Queen->LoadgroupLoadedEvent.Remove(BLoaded_AfterIntersectFromA);

  if (bShouldRecycle) {
    UE_LOG(StarryDebug, Display, TEXT("should recycle? yes"));
    bShouldRecycle = false;
    Queen->LoadgroupLoadedEvent.Add(ALoaded_AfterBLoaded_AfterIntersectFromA);
    Queen->LoadLoadGroup(ASideLoadGroup);
  } else {
    UE_LOG(StarryDebug, Display, TEXT("should recycle? no"));
    gameInstance->SetIsFrozenForLoading(false);
  }
}

void ALevelLoadingTwoWayBox::Cbk_ALoaded_AfterBLoaded_AfterIntersectFromA() {
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  gameInstance->SetIsFrozenForLoading(false);
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  Queen->LoadgroupLoadedEvent.Remove(ALoaded_AfterBLoaded_AfterIntersectFromA);
}

void ALevelLoadingTwoWayBox::LeaveToB() {
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  if (Queen->IsLoading()) {
    if (Queen->wantedLoadGroup == BSideLoadGroup) {
      gameInstance->SetIsFrozenForLoading(true);
    } else {
      bShouldRecycle = true;
    }
  } else {
    gameInstance->SetIsFrozenForLoading(true);
    Queen->LoadgroupLoadedEvent.Add(BLoaded_AfterLeaveToB);
    Queen->LoadLoadGroup(BSideLoadGroup);
  }
  UE_LOG(StarryDebug, Display, TEXT("Leave to B"));
}

void ALevelLoadingTwoWayBox::Cbk_BLoaded_AfterLeaveToB() {
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  gameInstance->SetIsFrozenForLoading(false);
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  Queen->LoadgroupLoadedEvent.Remove(BLoaded_AfterLeaveToB);
}

// Right to left flow

void ALevelLoadingTwoWayBox::IntersectFromB() {
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  Queen->LoadgroupLoadedEvent.Add(ALoaded_AfterIntersectFromB);
  Queen->LoadLoadGroup(ASideLoadGroup);
  UE_LOG(StarryDebug, Display, TEXT("Intersect from B"));
}

void ALevelLoadingTwoWayBox::Cbk_ALoaded_AfterIntersectFromB() {
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  Queen->LoadgroupLoadedEvent.Remove(ALoaded_AfterIntersectFromB);

  if (bShouldRecycle) {
    bShouldRecycle = false;
    Queen->LoadgroupLoadedEvent.Add(BLoaded_AfterALoaded_AfterIntersectFromB);
    Queen->LoadLoadGroup(BSideLoadGroup);
  } else {
    gameInstance->SetIsFrozenForLoading(false);
  }
}

void ALevelLoadingTwoWayBox::Cbk_BLoaded_AfterALoaded_AfterIntersectFromB() {
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  gameInstance->SetIsFrozenForLoading(false);
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  Queen->LoadgroupLoadedEvent.Remove(BLoaded_AfterALoaded_AfterIntersectFromB);
}

void ALevelLoadingTwoWayBox::LeaveToA() {
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  if (Queen->IsLoading()) {
    if (Queen->wantedLoadGroup == ASideLoadGroup) {
      gameInstance->SetIsFrozenForLoading(true);
    } else {
      bShouldRecycle = true;
    }
  } else {
    gameInstance->SetIsFrozenForLoading(true);
    Queen->LoadgroupLoadedEvent.Add(ALoaded_AfterLeaveToA);
    Queen->LoadLoadGroup(ASideLoadGroup);
  }
  UE_LOG(StarryDebug, Display, TEXT("Leave to A"));
}

void ALevelLoadingTwoWayBox::Cbk_ALoaded_AfterLeaveToA() {
  auto gameInstance = (URivenGameInstance *)GetWorld()->GetGameInstance();
  gameInstance->SetIsFrozenForLoading(false);
  ALoadgroupActor *Queen = gameInstance->LoadgroupQueen;
  Queen->LoadgroupLoadedEvent.Remove(ALoaded_AfterLeaveToA);
}
