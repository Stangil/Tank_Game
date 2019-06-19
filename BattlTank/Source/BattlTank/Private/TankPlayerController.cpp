// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "TankAimingComponent.h"
void  ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent))
	{
		FoundAimingComponent(AimingComponent);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No AimingComponent at Begin Play"));
	}
	auto ControlledTank = GetControlledTank();
	if (!ensure(ControlledTank))
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possesing Tank"));
	}
}



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!ensure(GetControlledTank())) { return; }

	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side effect", is going to line trace
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}
//get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find Crosshair position in pixel coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	//"Deproject " Screen postiton of the cross hair to a world position
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Linetrace along that LookDirection, and see what we hit(up to max range) 
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	
	return true;
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if(GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;// To be discarded
	
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
		);	
}

