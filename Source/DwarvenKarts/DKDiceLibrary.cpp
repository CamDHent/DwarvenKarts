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