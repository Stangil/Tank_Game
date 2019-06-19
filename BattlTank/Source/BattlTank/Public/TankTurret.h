//Copyright Microgames

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLTANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:	
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 25.0;
	
	
};
