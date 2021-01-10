// Copyright Adrian Kowarik

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	// Called by the engine when actor damage is dealt
	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser
	) override;

	// return current healt as a percentage of starting health, betwen 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	FTankDelegate OnDeath;
protected:
	UPROPERTY(BlueprintReadWrite, Category = "Setup")
		float StartingHealth = 100.f;

	UPROPERTY(BlueprintReadWrite, Category = "Health")
		float CurrentHealth; // Initialised in Begin Play

private:
	ATank();

	virtual void BeginPlay() override;

};
