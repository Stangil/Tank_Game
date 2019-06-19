
#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	///No need to call Super
	FVector TankForward = GetOwner()->GetActorForwardVector();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();
	float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	float RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow);
}
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; };
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO prevent double-speed due to double input
}
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack))  { return; };
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
