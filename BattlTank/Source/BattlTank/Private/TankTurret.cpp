// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"



void UTankTurret::Rotate(float RelativeSpeed)
{
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float RotationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotation= RelativeRotation.Yaw + RotationChange;
/*
	auto Rotation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);*/
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

