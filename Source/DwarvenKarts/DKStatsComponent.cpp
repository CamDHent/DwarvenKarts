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

    const int32 PreviousHealth = CurrentHealth;

    CurrentHealth = FMath::Clamp(
        CurrentHealth - DamageAmount,
        0,
        MaxHealth
    );

    if (PreviousHealth > 0 && CurrentHealth == 0)
    {
        OnPuttPuttModeEntered.Broadcast();
    }
}

void UDKStatsComponent::Heal(int32 HealAmount)
{
    if (HealAmount <= 0)
    {
        return;
    }

    const int32 PreviousHealth = CurrentHealth;

    CurrentHealth = FMath::Clamp(
        CurrentHealth + HealAmount,
        0,
        MaxHealth
    );

    if (PreviousHealth == 0 && CurrentHealth > 0)
    {
        OnPuttPuttModeExited.Broadcast();
    }
}

bool UDKStatsComponent::IsInPuttPuttMode() const
{
    return CurrentHealth <= 0;
}

bool UDKStatsComponent::CanUseCombatSystems() const
{
    return !IsInPuttPuttMode();
}

bool UDKStatsComponent::CanUseAbilities() const
{
    return !IsInPuttPuttMode();
}