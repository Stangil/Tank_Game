// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}
void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward: %f"),Throw);
	if (!LeftTrack || !RightTrack) { return; };
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODOD prevent double-speed due to double input
}
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward: %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; };
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//TODOD prevent double-speed due to double input
}