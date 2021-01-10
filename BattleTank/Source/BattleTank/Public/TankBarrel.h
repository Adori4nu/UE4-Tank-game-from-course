// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10; // Sensible value

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevation = 30.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevation = -5.0f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	bool PreventSelfColision = false;
};
