// Copyright Adrian Kowarik

#include "Public/Tank.h"

float ATank::GetHealthPercent() const
{
	return CurrentHealth / StartingHealth;
}

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	auto DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	//auto DamagePoints; = FPlatformMath::RoundToInt(DamageAmount);
	//DamageToApply = FMath::Clamp(DamageAmount, 0.f, CurrentHealth);
	if (CurrentHealth <= 0.f)
	{
		OnDeath.Broadcast();
		CurrentHealth = 0.f;
		DamageToApply = 0.f;
	}
	else
	{
		CurrentHealth -= DamageToApply;
		UE_LOG(LogTemp, Warning, TEXT("Damage Amount = %f, Damage to apply = %f"), DamageAmount, DamageToApply)
	}
	return DamageToApply;
}