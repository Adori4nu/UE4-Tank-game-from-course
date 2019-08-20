// Copyright Adrian Kowarik

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Controller.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	// How close can AI get to player
	float AcceptanceRadius = 3000.0f;
};