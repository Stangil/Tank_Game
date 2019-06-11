// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void  ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possesing Tank"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player Controller Possesing: %s"), *(ControlledTank->GetName()));
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
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side effect", is going to line trace
	{
		//TODO Tell Controlled tank to aim at this point
	}
}
//get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find Crosshair position
	int32 ViewPortsizeX, ViewPortSizeY;
	GetViewportSize(ViewPortsizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortsizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	//"Deproject " Screen postiton of the cross hair to a world position
	//Linetrace along that look  direction, and see what we hit(up to max range) 
	return true;
}
