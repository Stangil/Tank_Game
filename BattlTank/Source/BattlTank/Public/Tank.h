// Copyright Microgames

#pragma once
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"// Must be last include

//Forward declaration
class UTankBarrel; 
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();
protected:
	//Variables
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:

	void BeginPlay();
	// Sets default values for this pawn's properties
	ATank();

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
