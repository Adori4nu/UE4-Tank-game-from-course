// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto TankPossessed = GetControlledTank();
	if(!TankPossessed)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possessing a: %s"), *(TankPossessed->GetName()));
	}
	
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI didn't find a player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI %s found a Player: %s"), *(TankPossessed->GetName()), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

APlayerController* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController();
	if (!PlayerPawn) { return nullptr; }
	return PlayerPawn;
}
