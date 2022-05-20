#include "Cell.h"
#include <iostream>

//поиск соседей
Cell* Cell::getCellAt(Coordinate aCoord)
{
	return _owner.cells[aCoord.getY()][aCoord.getX()];
}

void Cell::assignCellAt(Coordinate aCoord)
{
	_owner.cells[aCoord.getY()][aCoord.getX()] = nullptr;
}
void Cell::assignCellAt(Coordinate aCoord, Cell* aCell)
{
	_owner.cells[aCoord.getY()][aCoord.getX()]=aCell;
}

// кол-во                                                      соседи
/*int*/ Cell* Cell::getNeighborWithImage(char anImage /*, Cell* neighbors[4] */)
{
	Cell* neighbors[4];
	unsigned count = 0;

	if (anImage == north())//сравнивает image с image c кординатами north
		neighbors[count++] = ;
	/*if (anImage == west(this))
		neighbors[count++] = this;
	if (anImage == east(this))
		neighbors[count++] = this;
	if (anImage == south(this))
		neighbors[count++] = ;*/
	if (count == 0)
		return this;
	else
		return neighbors[_owner.random.NextBetween(0, count - 1)];
		
}

Coordinate Cell::getEmptyNeighborCoord()
{
	std::cout << "getEmptyNeighborCoord ";
	std::cout << "X:" << this->_offset.getX() << " ";
	std::cout << "Y:" << this->_offset.getY();

	return getNeighborWithImage(DefaultImage)->getOffset();
}

Coordinate Cell::getPreyNeighborCoord()
{
	std::cout << ":getPreyNeighborCoord ";
	std::cout << "image:" << this->_image<<" ";
	std::cout<<"X:" << this->_offset.getX() << " ";
	std::cout<<"Y:" << this->_offset.getY();

	return getNeighborWithImage(DefaultPreyImage)->getOffset();
}

char Cell::north()
{

	if ((_offset.getY() <= 0) && (_owner.cells[_offset.getY() - 1][_offset.getX()]  == nullptr))//если  nullptr 
	{
		return DefaultImage;//координаты текущей точки
	}
	else
	{
		return _owner.cells[_offset.getY() - 1][_offset.getX()]->getImage();//координаты точки повыше
	}
}

/*Cell* Cell::south()
{
	if ((_offset.getY() + 1) == _owner.getNumRows())
	{
		return _owner.cells[_offset.getY()][_offset.getX()];
	}
	else
	{
		return _owner.cells[_offset.getY() + 1][_offset.getX()];
	}
}

Cell* Cell::east(void)
{
	if ((_offset.getX() + 1) == _owner.getNumCols())
	{
		return _owner.cells[_offset.getX()][_offset.getY()];
	}
	else
	{
		return _owner.cells[_offset.getX() + 1][_offset.getY()];
	}
}

Cell* Cell::west(void)
{
	if ((_offset.getX() - 1) < 0)
	{
		return _owner.cells[_offset.getX()][_offset.getY()];
	}
	else
	{
		return _owner.cells[_offset.getX() - 1][_offset.getY()];
	}
}*/

Cell* Cell::reproduce()
{
	Cell* temp = nullptr;
	return temp;
}
char Cell::getImage()
{
	return _image;
}