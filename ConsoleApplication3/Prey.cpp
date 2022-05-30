#include "Prey.h"
#include <iostream>
void Prey::moveFrom(Coordinate from, Coordinate to)
{
	Cell* toCell;
	--timeToReproduce;
	if (to != from)
	{
		if (_owner.getCell(to) == nullptr)
		{
			this->setOffset(to);
			_owner.swapCell(to, from, this);
		}
		std::cout.flush();
		if (timeToReproduce <= 0)
		{
			timeToReproduce = TimeToReproduce;
			reproduce(from);
		}
		else
		{
			assignCellAt(from, nullptr);
		}
	}
}

 void Prey::reproduce(Coordinate anOffset)
{
	Prey* temp = new Prey(anOffset, &_owner );
	_owner.setNumPrey(_owner.getNumPrey() + 1);
	assignCellAt(anOffset, temp);
}
