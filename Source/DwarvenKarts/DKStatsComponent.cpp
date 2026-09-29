// Fill out your copyright notice in the Description page of Project Settings.


#include "DKStatsComponent.h"

// Sets default values for this component's properties
UDKStatsComponent::UDKStatsComponent()
{
	// Set this component to be initialized when the game starts.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UDKStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	
}

void UDKStatsComponent::TakeDamage(int32 DamageAmount)
{
    if (DamageAmount <= 0)
    {
        return;
    }

    CurrentHealth = FMath::Clamp(
        CurrentHealth - DamageAmount,
        0,
        MaxHealth
    );
}

void UDKStatsComponent::Heal(int32 HealAmount)
{
    if (HealAmount <= 0)
    {
        return;
    }

    CurrentHealth = FMath::Clamp(
        CurrentHealth + HealAmount,
        0,
        MaxHealth
    );
}

bool UDKStatsComponent::IsInPuttPuttMode() const
{
    return CurrentHealth <= 0;
}