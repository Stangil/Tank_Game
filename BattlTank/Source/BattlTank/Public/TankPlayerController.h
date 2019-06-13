// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"// needs to be included last

//Forward declaration
class ATank;
UCLASS()
class BATTLTANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	ATank* GetControlledTank() const;
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	//Start moving the barrel so that a shot intersects where the shot will hit
	void AimTowardCrosshair();
	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;



	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;
	
};
