// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DKStatsComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPuttPuttModeEntered);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPuttPuttModeExited);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DWARVENKARTS_API UDKStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDKStatsComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dwarven Karts|Stats")
	int32 MaxHealth = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dwarven Karts|Stats")
	int32 CurrentHealth = 100;

	/**
	* Removes health from this component.
	* Health will never drop below 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Dwarven Karts|Stats")
	void TakeDamage(int32 DamageAmount);

	/**
	* Restores health to this component.
	* Health will never exceed MaxHealth.
	*/
	UFUNCTION(BlueprintCallable, Category = "Dwarven Karts|Stats")
	void Heal(int32 HealAmount);

	/**
	 * Returns true when this kart has entered PuttPutt Mode.
	 * A kart enters PuttPutt Mode when its health reaches zero.
	 */
	UFUNCTION(BlueprintPure, Category = "Dwarven Karts|Stats")
	bool IsInPuttPuttMode() const;

	/**
	* Returns true when this kart is allowed to use
	* its normal combat systems.
	*/
	UFUNCTION(BlueprintPure, Category = "Dwarven Karts|Stats")
	bool CanUseCombatSystems() const;

	/**
	* Returns true when this kart is allowed to use
	* its normal character abilities.
	*/
	UFUNCTION(BlueprintPure, Category = "Dwarven Karts|Stats")
	bool CanUseAbilities() const;

	/**
	* Fired when this component's health reaches zero
	* and the kart enters PuttPutt Mode.
	*/
	UPROPERTY(BlueprintAssignable, Category = "Dwarven Karts|Stats")
	FOnPuttPuttModeEntered OnPuttPuttModeEntered;

	/**
	* Fired when this component recovers from zero health
	* and exits PuttPutt Mode.
	*/
	UPROPERTY(BlueprintAssignable, Category = "Dwarven Karts|Stats")
	FOnPuttPuttModeExited OnPuttPuttModeExited;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
