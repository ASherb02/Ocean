#include "Cell.h"
#include <iostream>

//поиск соседей
Cell* Cell::getCellAt(Coordinate aCoord,Ocean* _owner)
{
	return _owner->getCell(aCoord);
}

void Cell::assignCellAt(Coordinate aCoord, Cell* _aCell)
{
	_owner.setCell(aCoord, _aCell);
}

                                                
Coordinate Cell::getNeighborCoord(Cell* item)
{
	unsigned rand_world_side = rand() % 3 + 0;

	switch (rand_world_side)
	{
	case 0:
	{
		Coordinate temp(_owner.north(item).getX(), _owner.north(item).getY());

		return temp;
		break;
	}
	case 1:
	{
		Coordinate temp(_owner.south(item).getX(), _owner.south(item).getY());

		return temp;
		break;
	}
	case 2:
	{
		Coordinate temp(_owner.east(item).getX(), _owner.east(item).getY());

		return temp;
		break;
	}
	case 3:
	{
		Coordinate temp(_owner.west(item).getX(), _owner.west(item).getY());

		return temp;
		break;
	}
	default:
	{
		break;
	}
	}
}


Cell* Cell::getPreyNeighborCoord(Cell* item)
{
	Cell* temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());
	if (temp != nullptr)
	{
		if (temp->getImage() == DefaultPreyImage)
		{
			return temp;
		}

	}
	temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());

	if (temp != nullptr)
	{
		if (temp->getImage() == DefaultPreyImage)
		{
			return temp;
		}
	}
	temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());
	if (temp != nullptr)
	{
		if (temp->getImage() == DefaultPreyImage)
		{
			return temp;
		}
	}
	temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());
	if (temp != nullptr)
	{
		if (temp->getImage() == DefaultPreyImage)
		{
			return temp;
		}
	}

	return nullptr;
}

Cell* Cell::reproduce()
{
	Cell* temp = nullptr;
	return temp;
}
char Cell::getImage()
{
	return _image;
}