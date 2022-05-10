#include "Cell.h"
#include <iostream>

//поиск соседей
Cell* Cell::getCellAt(Coordinate aCoord)
{
	return Ocean1->cells[aCoord.getY()][aCoord.getX()];
}

void Cell::assignCellAt(Coordinate aCoord, Cell* aCell)
{
	Ocean1->cells[aCoord.getY()][aCoord.getX()]=aCell;
}

Cell* Cell::getNeighborWithImage(char anImage)
{
	Cell* neighbors[4];
	unsigned count = 0;

	if (north()->getImage() == anImage) neighbors[count++] = north();
	if(south()->getImage()==anImage) neighbors[count++] = south();
	if (east()->getImage() == anImage) neighbors[count++] = east();
	if (west()->getImage() == anImage) neighbors[count++] = west();
	if (count == 0)
		return this;
	else
		return neighbors[Ocean1->random.NextBetween(0, count - 1)];
}

Coordinate Cell::getEmptyNeighborCoord()
{
	return getNeighborWithImage(DefaultImage)->getOffset();
}

Coordinate Cell::getPreyNeighborCoord()
{
	return getNeighborWithImage(DefaultPreyImage)->getOffset();
}

Cell* Cell::north(void)
{
	unsigned yvalue;
	yvalue = (offset.getY() > 0) ? (offset.getY() - 1) : (Ocean1->numRows - 1);
	return Ocean1->cells[yvalue][offset.getX()];
}

Cell* Cell::south(void)
{
	unsigned yvalue;

	yvalue = (offset.getY() + 1) % Ocean1->numRows;
	return Ocean1->cells[yvalue][offset.getX()];
}

Cell* Cell::east(void)
{
	unsigned xvalue;

	xvalue = (offset.getY() + 1) % Ocean1->numCols;
	return Ocean1->cells[offset.getX()][xvalue];
}

Cell* Cell::west(void)
{
	unsigned xvalue;
	xvalue = (offset.getX() > 0) ? (offset.getX() - 1) : (Ocean1->numCols - 1);
	return Ocean1->cells[offset.getY()][xvalue];
}

Cell* Cell::reproduce(Coordinate anOffset)
{
	Cell* temp = new Cell(anOffset);
	return temp;
}

void Cell::display(void)
{
	printf("%c", Image);
}

char Cell::getImage()
{
	return Image;
}