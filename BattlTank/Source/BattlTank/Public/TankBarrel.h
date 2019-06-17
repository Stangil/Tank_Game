
#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLTANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max downward movement, +1 is max UPWARD movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10.0; 
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 40.0f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = -5.0f;
};
