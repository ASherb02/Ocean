/*#include "Predator.h"

//ќбработка и отображени€
void Predator::process()
{
	Coordinate toCoord;
	if (--timeToFeed <= 0)//хищник умирает
	{
		assignCellAt(offset, new Cell(offset));
		Ocean1->setNumPredators(Ocean1->getNumPredators() - 1);
		delete this;
	}
	else//сьедает соседнюю добычу
	{
		toCoord = getPreyNeighborCoord();
		if (toCoord != offset)
		{
			Ocean1->setNumPrey(Ocean1->getNumPrey() - 1);
			timeToFeed = TimeToFeed;
			moveFrom(offset, toCoord);
		}
		else
			Prey::procces();//перемещение в пустую €чейку
	}
}

Cell* Predator::reproduce(Coordinate anOffset)
{
	Predator* temp = new Predator(anOffset);
	Ocean1->setNumPredators(Ocean1->getNumPredators());
	return (Cell*)temp;
}
*/