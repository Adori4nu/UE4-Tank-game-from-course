// Copyright Adrian Kowarik

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo,
};

// Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

// Holds barrel's properties and Elevate method
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

	EFiringState GetFiringState() const;
	
	UFUNCTION(BlueprintCallable, Category = "Firing")
		int GetRoundsLeft() const;

	UPROPERTY(BlueprintReadWrite)
		int MaxAmmo;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Reloading;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 12525;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 2;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		int CurrentAmmoCapacity = 21;

	double LastFireTime = 0;

	FVector AimDirection;
};
