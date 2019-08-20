// Copyright Adrian Kowarik

#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Public/TankAIController.h"
#include "TankPlayerController.h"
#include "Public/TankAimingComponent.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();
	if (!ensure(PlayerTank && AITank)) { return; }
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm
		// Aim towards the player
		auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		AimingComponent->Fire(); // TODO Dont fire every frame
}