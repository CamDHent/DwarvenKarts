#include "DKDiceLibrary.h"

int32 UDKDiceLibrary::RollDie(int32 Sides)
{
	if (Sides <= 0)
	{
		return 0;
	}

	return FMath::RandRange(1, Sides);
}

int32 UDKDiceLibrary::RollDice(int32 NumberOfDice, int32 Sides)
{
    if (NumberOfDice <= 0 || Sides <= 0)
    {
        return 0;
    }

    int32 Total = 0;

    for (int32 Die = 0; Die < NumberOfDice; ++Die)
    {
        Total += RollDie(Sides);
    }

    return Total;
}

int32 UDKDiceLibrary::RollDiceWithModifier(
    int32 NumberOfDice,
    int32 Sides,
    int32 Modifier)
{
    return RollDice(NumberOfDice, Sides) + Modifier;
}

bool UDKDiceLibrary::DiceCheck(
    int32 NumberOfDice,
    int32 Sides,
    int32 Modifier,
    int32 Difficulty)
{
    int32 Total = RollDiceWithModifier(NumberOfDice, Sides, Modifier);

    return Total >= Difficulty;
}

FDiceCheckResult UDKDiceLibrary::DiceCheckDetailed(
    int32 NumberOfDice,
    int32 Sides,
    int32 Modifier,
    int32 Difficulty)
{
    FDiceCheckResult Result;

    Result.RollTotal = RollDice(NumberOfDice, Sides);
    Result.Modifier = Modifier;
    Result.FinalTotal = Result.RollTotal + Modifier;
    Result.Difficulty = Difficulty;
    Result.bSuccess = Result.FinalTotal >= Difficulty;

    return Result;
}