#pragma once
#include "GameFramework/Character.h"
#include "SECharacterEventStates.h"
#include "SECharacter.generated.h"

/* Forward Declarations */
class UInputComponent;
enum class ECharacterState : uint8;
enum class ECharacterZoomState : uint8;

/* Class Declaration */
UCLASS(Config = Game)
class ASECharacter : public ACharacter
{
   GENERATED_BODY()

public:



   ASECharacter();

   virtual void BeginPlay() override;

   // Public Exposed Methods
   UFUNCTION(BlueprintCallable, Category = "StarryExpanse|Character|Input")
   void ToggleCursorMode();
   UFUNCTION(BlueprintCallable, Category = "StarryExpanse|Character|Input")
   void ToggleZoomMode();

   // Public Exposed Variables
   UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
   float BaseTurnRate;
   UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
   float BaseLookUpRate;

   UFUNCTION(exec)
   void FreeCursor();

   FORCEINLINE UCameraComponent* GetCameraComponent() const {
      return CameraComponent;
   }

   ECharacterState            State;
   ECharacterZoomState         ZoomState; // TODO: Remove this, and replace it's functionality based upon if we click inside/outside of an object
   FSECharacterStateChanged   OnCharacterStateChanged;

protected:
   // Protected Overrides
   void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

   // Protected Event Callbacks

   // Protected Methods
   void MoveForward(float Val);
   void MoveRight(float Val);
   void Turn(float Val);
   void LookUp(float Val);
   void TurnAtRate(float Rate);
   void LookUpAtRate(float Rate);

private:
   // Private Exposed Variables
   UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
   class UCameraComponent*      CameraComponent;

};
