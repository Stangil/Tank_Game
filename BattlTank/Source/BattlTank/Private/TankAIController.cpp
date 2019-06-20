// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankAIController.h"
#include "Engine/World.h"


void  ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto  PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn(); 
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; };
		//  Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);//TODO check radius is in centimeters

		auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
		if (!ensure(AimingComponent)) { return; }
		//Aim towards the player
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		//TODO Fix firing
		//ControlledTank->Fire();//TODO Limit firing rate
}


