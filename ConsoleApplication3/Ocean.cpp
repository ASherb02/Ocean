#include "Ocean.h"
#include <ostream>
#include "Obstacle.h"
#include "Cell.h"
#include "Constants.h"
#include "Predator.h"
#include "Prey.h"
#include "Random.h"
#include "Coordinate.h"
#include "ConsoleOceanViewer.h"
#include <iostream>
#include <string>

//Инициализация
void Ocean::initialize(Ocean&)
{
	//random.initialize();
	numRows = MaxRows;
	numCols = MaxCols;
	size = numRows * numCols;

	numObstacles = DefaultNumObstacles;
	numPredators = DefaultNumPredators;
	numPrey = DefaultNumPrey;

	initCell();
}

void Ocean::initCell()
{
	cleanGameField();
	std::string temp;
	/*std::cout << "\n\n Enter number of obstacles (default=75):";
	std::cout.flush();
	std::getline(std::cin, temp);
	numObstacles=std::stoi(temp);
	if (numObstacles == size)numObstacles = size;
	std::cout << "\nNumber obstacles accepted = " << numObstacles;
	std::cout.flush();*/
	numObstacles = 50;

	/*std::cout << "\n\n Enter number of predators (default=20):";
	std::cout.flush();
	std::getline(std::cin, temp);
	numPredators = std::stoi(temp);
	if (numPredators == (size - numObstacles))
		numPredators = size - numObstacles;
	std::cout << "\nNumber predators accepted = " << numPredators;
	std::cout.flush();*/
	numPredators = 30;
	/*
	std::cout << "\n\n Enter number of prey(default = 150):";
	std::cout.flush();
	std::getline(std::cin, temp);
	numPrey = std::stoi(temp);
	if (numPrey = (size - numObstacles - numPredators))
		numPrey = size - numObstacles - numPredators;
	std::cout << "\nNumber prey accepted =" << numPrey<<"\n\n";
	std::cout.flush();
	*/
	numPrey = 150;
	addObstacles();
	addPredators();
	addPrey();
	
	viewOwner.displayStats(this->getNumObstacles(),this->getNumPredators(),this->getNumPrey(),-1,this->getNumCols());
	viewOwner.displayCells(this->getNumRows(),this->getNumCols(),this);
	viewOwner.displayBorder(this->getNumCols());
	
}

void Ocean::cleanGameField()
{
	for (unsigned int row = 0; row < numRows; row++)
	{
		for (unsigned int col = 0; col < numCols; col++)
		{
			cells[row][col] = nullptr;
		}
	}

}
void Ocean::addObstacles()
{
	Coordinate empty;
	for (unsigned count = 0; count < numObstacles; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Obstacle(empty, this);
	}
}

void Ocean::addPredators()
{
	
	Coordinate empty;
	for (unsigned count = 0; count < numPredators; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] =new Predator(empty, this);
	}
}

void Ocean::addPrey()
{
	Coordinate empty;
	for (unsigned count = 0; count < numPrey; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Prey(empty, this);
	}
}
Coordinate Ocean::getEmptyCellCoord(void)
{
	unsigned x, y;

	do 
	{ 
		x = random.NextBetween(0, numCols - 1);
		y = random.NextBetween(0, numRows - 1);

	} 
	while (cells[y][x] != nullptr /* ? 0 : cells[y][x]->getImage() != DefaultImage */ );
    Coordinate empty(x, y);//cells[y][x]->getOffset();
	//delete cells[y][x];
	return empty;
}

//Запуск процеса моделирования
void Ocean::run()
{
	unsigned numIterations = DefaultNumIterations;
	std::string temp;
	std::cout << "\n\nEnter number of iterations(default max=1000):";
	std::cout.flush();
	std::getline(std::cin, temp);
	numIterations = std::stoi(temp);
	if (numIterations > 1000) numIterations = 1000;
	std::cout << "\nNumber iteration=" << numIterations<<"\nbegin run...\n";
	std::cout.flush();

	for (unsigned iteration = 0; iteration < numIterations; iteration++)
	{
		_visitor.clear();

		if (numPredators > 0 && numPrey > 0)
		{
			for (unsigned row = 0; row < numRows; row++)
			{
				for (unsigned col = 0; col < numCols; col++)
				{
					Cell* currentItem = cells[row][col];

					if (!_visitor.isVisited(cells[row][col]) && currentItem != nullptr)
					{
						currentItem->process();
						_visitor.visit(currentItem);
					}
				}
			}
		}
		viewOwner.displayStats(this->getNumObstacles(),this->getNumPredators(), this->getNumPrey(), iteration, this->getNumCols());
		viewOwner.displayCells(this->getNumRows(), this->getNumCols(), this);
		viewOwner.displayBorder(this->getNumCols());
		std::cout.flush();
	}

}
Coordinate Ocean::north(Cell* center)
{

	unsigned yvalue;

	yvalue = (center->getOffset().getY() > 0) ? (center->getOffset().getY() - 1) : numCols - 1;

	Coordinate temp(center->getOffset().getX(), yvalue);

	return temp;
}

Coordinate Ocean::south(Cell* center)
{
	unsigned yvalue;

	yvalue = (center->getOffset().getY() + 1) % numCols;

	Coordinate temp(center->getOffset().getX(), yvalue);

	return temp;
}

Coordinate Ocean::east(Cell* center)
{
	unsigned xvalue;

	xvalue = (center->getOffset().getX() + 1) % numCols;

	Coordinate temp(xvalue, center->getOffset().getY());

	return temp;
}

Coordinate Ocean::west(Cell* center)//TODO:Coordinate вместо Cell
{
	unsigned xvalue;

	xvalue = (center->getOffset().getX() > 0) ? (center->getOffset().getX() - 1) : numCols - 1;

	Coordinate temp(xvalue, center->getOffset().getY());

	return temp;
}

void Ocean::swapCell(Coordinate& to, Coordinate& from, Cell* item)
{
	setCell(to, item);
	cells[from.getY()][from.getX()] = nullptr;
}

unsigned Ocean::getNumPrey()
{
	return numPrey;
}

unsigned Ocean::getNumPredators()
{
	return numPredators;
}

unsigned Ocean::getNumCols()
{
	return numCols;
}

unsigned Ocean::getNumRows()
{
	return numRows;
}

unsigned Ocean::getNumObstacles()
{
	return numObstacles;
}

Cell* Ocean::getCell(Coordinate a_coord)
{
	return cells[a_coord.getY()][a_coord.getX()];
}

Cell* Ocean::getCell(unsigned _Rows, unsigned _Cols)
{
	return cells[_Rows][_Cols];
}

void Ocean::setNumPrey(unsigned aNumber)
{
	numPrey = aNumber;
}

void Ocean::setNumPredators(unsigned aNumber)
{
	numPredators = aNumber;
}
void Ocean::setCell(Coordinate& a_coord, Cell* a_cell)
{
	cells[a_coord.getY()][a_coord.getX()] = a_cell;
}