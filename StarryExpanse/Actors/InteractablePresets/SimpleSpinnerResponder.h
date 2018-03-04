//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Enums/EInteractable.h"
#include "GameFramework/Actor.h"
#include "Interfaces/RivenInteractable.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Structs/InteractabilityProbeResponse.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "SaveGame/ESaveGameField.h"
#include "Structs/InteractableSettingsAxial.h"
#include "SimpleSpinnerResponder.generated.h"

//
// An actor with a single moveable component (static mesh). This class handles
// animating the component around a single relative axis when touched, and
// informing the game when the animation is complete. Will also initialize the
// component to that rotation value when initialized.
//
UCLASS()
class STARRYEXPANSE_API ASimpleSpinnerResponder : public AActor,
                                                  public IRivenInteractable {
  GENERATED_BODY()

public:
  ASimpleSpinnerResponder(const FObjectInitializer &ObjectInitializer);

  // Methods:
  UFUNCTION(BlueprintCallable)
  void Initialize(FInteractableSettingsAxial Settings);

  // Actor:
  void BeginPlay() override;
  void Tick(float DeltaTime) override;

  // RivenInteractable:
  void LookingAt_Implementation() override;
  void Touched_Implementation() override;
  FInteractabilityProbeResponse ProbeInteractability_Implementation() override;

private:
  UFUNCTION(Category = Gameplay)
  void AnimationProgressCallback(float val);
  UFUNCTION(Category = Gameplay)
  void AnimationDone();

  void SetRotation(float val);

  ESaveGameField m_save_game_field;
  UStaticMeshComponent *m_moveablePart = nullptr;
  FTimeline m_timeline;
  EAxis::Type m_axis = EAxis::None;
};