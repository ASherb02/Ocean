/*#include "Prey.h"

void Prey::moveFrom(Coordinate from, Coordinate to)
{
	Cell* toCell;
	--timeToReproduce;
	if (to != from)
	{
		toCell = getCellAt(to);
		delete toCell;
		setOffset(to);
		assignCellAt(to, this);
		if (timeToReproduce <= 0)
		{
			timeToReproduce = TimeToReproduce;
			assignCellAt(from, reproduce(from));
		}
		else
			assignCellAt(from, new Cell(from));
	}
}

Cell* Prey::reproduce(Coordinate anOffset)
{
	Prey* temp = new Prey(anOffset);
	Ocean1->setNumPrey(Ocean1->getNumPrey() + 1);
	return (Cell*)temp;
}
*/