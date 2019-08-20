// Copyright Adrian Kowarik

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// TODO remove once firing is moved to aimingcomponent
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 167000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	// Local barrel reference
	UTankBarrel* Barrel = nullptr; // TODO Remove
};
