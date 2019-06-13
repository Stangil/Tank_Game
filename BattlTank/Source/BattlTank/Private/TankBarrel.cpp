// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel the right amount this frame
	//GIven a max elevation speed, and the frame time
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float ElevationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	 
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation , 0, 0));
}