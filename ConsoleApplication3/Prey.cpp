#include "Prey.h"

void Prey::moveFrom(Coordinate from, Coordinate to)
{
	Cell* toCell;
	--timeToReproduce;
	if (to != from)
	{
		toCell = getCellAt(to);
		delete toCell;
		setOffset(to);
		assignCellAt(to);
		if (timeToReproduce <= 0)
		{
			timeToReproduce = TimeToReproduce;
			assignCellAt(from, reproduce(from));
		}
		else
			assignCellAt(from,this);
	}
}

Cell* Prey::reproduce(Coordinate anOffset)
{
	Prey* temp = new Prey(anOffset, &_owner );
	_owner.setNumPrey(_owner.getNumPrey() + 1);
	return (Cell*)temp;
}
