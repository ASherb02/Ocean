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
	addEmptyCells();
	std::string temp;
	/*std::cout << "\n\n Enter number of obstacles (default=75):";
	std::cout.flush();
	std::getline(std::cin, temp);
	numObstacles=std::stoi(temp);
	if (numObstacles == size)numObstacles = size;
	std::cout << "\nNumber obstacles accepted = " << numObstacles;
	std::cout.flush();*/
	numObstacles = 10;

	/*std::cout << "\n\n Enter number of predators (default=20):";
	std::cout.flush();
	std::getline(std::cin, temp);
	numPredators = std::stoi(temp);
	if (numPredators == (size - numObstacles))
		numPredators = size - numObstacles;
	std::cout << "\nNumber predators accepted = " << numPredators;
	std::cout.flush();*/
	numPredators = 20;
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
	numPrey = 10;
	addObstacles();
	addPredators();
	addPrey();
	
	viewOwner.displayStats(this->getNumObstacles(),this->getNumPrey(),-1,this->getNumCols());
	viewOwner.displayCells(this->getNumRows(),this->getNumCols(),this);
	viewOwner.displayBorder(this->getNumCols());
	
}

void Ocean::addEmptyCells()
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
		if (numPredators > 0 && numPrey > 0)
		{
			for (unsigned row = 0; row < numRows; row++)
				for (unsigned col = 0; col < numCols; col++)
				{
					cells[row][col]->process();
				}
					
			viewOwner.displayStats(this->getNumObstacles(), this->getNumPrey(), iteration, this->getNumCols());
			viewOwner.displayCells(this->getNumRows(), this->getNumCols(), this);
			viewOwner.displayBorder(this->getNumCols());
			std::cout.flush();
		}
	}

}
/*char Ocean::getChar(Cell* SearchCell)
{
   //Cell* SearchCell = cells [aCoord.getY()][aCoord.getX()];
    if (SearchCell == nullptr) 
    {
        return DefaultImage;
    }
    else 
    {
        return SearchCell->getImage();
    }
}*/
