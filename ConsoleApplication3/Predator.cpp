/*#include "Predator.h"

//��������� � �����������
void Predator::process()
{
	Coordinate toCoord;
	if (--timeToFeed <= 0)//������ �������
	{
		assignCellAt(offset, new Cell(offset));
		Ocean1->setNumPredators(Ocean1->getNumPredators() - 1);
		delete this;
	}
	else//������� �������� ������
	{
		toCoord = getPreyNeighborCoord();
		if (toCoord != offset)
		{
			Ocean1->setNumPrey(Ocean1->getNumPrey() - 1);
			timeToFeed = TimeToFeed;
			moveFrom(offset, toCoord);
		}
		else
			Prey::procces();//����������� � ������ ������
	}
}

Cell* Predator::reproduce(Coordinate anOffset)
{
	Predator* temp = new Predator(anOffset);
	Ocean1->setNumPredators(Ocean1->getNumPredators());
	return (Cell*)temp;
}
*/