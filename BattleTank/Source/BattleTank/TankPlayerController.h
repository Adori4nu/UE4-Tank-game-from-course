// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <BattleTank\Public\Tank.h>
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();


	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLOcation) const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;
	
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
};
