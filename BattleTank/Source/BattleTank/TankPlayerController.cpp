// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	auto TankPossessed = GetControlledTank();
	if (!TankPossessed)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank Possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(TankPossessed->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		
		// UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point

	}
	
}
// Get world location of linetrace through crosshair, true if hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairXLocation);

	// "De-project" the screen position of crosshair to a world direction
	FVector LookDirection;
	if(GetLookDirection(ScreenLocation, LookDirection))
	{ 
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString()); 
	}
	// Line-trace along that LookDirection, and see what we hit(up to max range)
	
	/*FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);
	HitLocation = PlayerViewPointLocation + PlayerViewPointRotation.Vector();
	*/
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}