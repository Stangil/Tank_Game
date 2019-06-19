// Copyright Microgames

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"// needs to be included last

//Forward declaration
class ATank;
class UTankAimingComponent;
/*
Responsible for helping player aim
*/
UCLASS()
class BATTLTANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	//Start moving the barrel so that a shot intersects where the shot will hit
	void AimTowardCrosshair();
	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;



	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0f;
	
};
