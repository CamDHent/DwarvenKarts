#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DKDiceLibrary.generated.h"

/**
 * Core dice rolling functions for Dwarven Karts.
 */
UCLASS()
class DWARVENKARTS_API UDKDiceLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/**
	 * Rolls a single die with the specified number of sides.
	 * Example: RollDie(20) returns a value from 1 through 20.
	 */
	UFUNCTION(BlueprintPure, Category = "Dwarven Karts|Dice")
	static int32 RollDie(int32 Sides);

	/**
 * Rolls multiple dice and returns their total.
 * Example: RollDice(2, 6) rolls 2d6 and returns 2 through 12.
 */
	UFUNCTION(BlueprintPure, Category = "Dwarven Karts|Dice")
	static int32 RollDice(int32 NumberOfDice, int32 Sides);
};