// Copyright Microgames

#pragma once
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"// Must be last include

//Forward declaration
class UTankBarrel; 
class AProjectile;

UCLASS()
class BATTLTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

private:

	void BeginPlay();
	// Sets default values for this pawn's properties
	ATank();

	//TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000.0f; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.0f;

	double LastFireTime = 0.0;// double because FPlatformTime::Seconds(); returns a double

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	//Local barrel reference for spawing projectile
	UTankBarrel* Barrel = nullptr;//TODO Remove
};
