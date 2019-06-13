
#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLTANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; 
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = -5.0f;
};
