// Copyright Microgames
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

//Forward declaration
class ATank;
UCLASS()
class BATTLTANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	


private:

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
	//How close can the AI tank get to the player tank
	float AcceptanceRadius = 3000.0f;
	
};
