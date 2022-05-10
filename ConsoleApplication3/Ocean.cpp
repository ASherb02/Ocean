#include "Ocean.h"
#include <ostream>
#include "Obstacle.h"
#include "Cell.h"
#include "Constants.h"
#include "Predator.h"
#include "Prey.h"
#include "Random.h"
#include "Coordinate.h"
#include <iostream>

//Инициализация
void Ocean::initialize(void)
{
	random.initialize();
	numRows = MaxRows;
	numCols = MaxCols;
	size = numRows * numCols;

	numObstacles = DefaultNumObstacles;
	numPredators = DefaultNumPredators;
	numPrey = DefaultNumPrey;

	initCell();
}

void Ocean::initCell(void)
{
	addEmptyCells();

	/*std::cout << "\n\n Enter number of obstacles (default=75):";
	std::cout.flush();
	std::cin >> numObstacles;
	if (numObstacles == size)numObstacles = size;
	std::cout << "\nNumber obstacles accepted = " << numObstacles;
	std::cout.flush();

	std::cout << "\n\n Enter number of predators (default=20):";
	std::cout.flush();
	std::cin >> numPredators;
	if (numPredators == (size - numObstacles))
		numPredators = size - numObstacles;
	std::cout << "\nNumber predators accepted = " << numPredators;
	std::cout.flush();

	std::cout << "\n\n Enter number of prey(default = 150):";
	std::cout.flush();
	std::cin >> numPrey;
	if (numPrey = (size - numObstacles - numPredators))
		numPrey = size - numObstacles - numPredators;
	std::cout << "\nNumber prey accepted =" << numPrey<<"\n\n";
	std::cout.flush();
	*/
	addObstacles();
	/*addPredators();
	addPrey();*/
	displayStats(-1);
	displayCells();
	displayBorder();
	Cell::Ocean1 = this;

}

void Ocean::addEmptyCells()
{
	for (unsigned int row = 0; row < numRows; row++)
	{
		for (unsigned int col = 0; col < numCols; col++)
		{
			cells[row][col] = new Cell (Coordinate(col, row));
		}
	}

}
void Ocean::addObstacles()
{
	Coordinate empty;
	for (unsigned count = 0; count < numObstacles; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Obstacle(empty);
	}
}
/*
void Ocean::addPredators(void)
{
	/*
	Coordinate empty;
	for (unsigned count = 0; count < numPredators; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] =new Predator(empty);
	}
}

void Ocean::addPrey(void)
{
	/*Coordinate empty;
	for (unsigned count = 0; count < numPrey; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Prey(empty);
	}
}*/
Coordinate Ocean::getEmptyCellCoord(void)
{
	unsigned x, y;
	Coordinate empty;

	do 
	{
		x = random.NextBetween(0, numCols - 1);
		y = random.NextBetween(0, numRows - 1);
	} 
	while (cells[y][x]->getImage() != DefaultImage);
	empty = cells[y][x]->getOffset();
	delete cells[y][x];
	return empty;
}

void Ocean::displayCells()
{
	for (unsigned row = 0; row < numRows; row++)
	{
		for (unsigned col = 0; col < numCols; col++)
		{
			cells[row][col]->display();
		}
		std::cout << "\n";
	}
}
void Ocean::displayStats(int iteration)
{
	/*std::cout << "\n\n";
	std::cout << "Iteration number"<<++iteration;
	std::cout << "Obstacles:"<<numObstacles;
	std::cout << "Predators:" << numPrey<<"\n";
	std::cout.flush();
	displayBorder();*/
}

//Запуск процеса моделирования
void Ocean::run(void)
{
	unsigned numIterations = DefaultNumIterations;

	std::cout << "\n\nEnter number of iterations(default max=1000):";
	std::cout.flush();
	std::cin >> numIterations;
	if (numIterations > 1000) numIterations = 1000;
	std::cout << "\nNumber iteration=" << numIterations<<"\nbegin run...\n";
	std::cout.flush();

	for (unsigned iteration = 0; iteration < numIterations; iteration++)
	{
		if (numPredators > 0 && numPrey > 0)
		{
			for (unsigned row = 0; row < numRows; row++)
				for (unsigned col = 0; col < numCols; col++)
					cells[row][col]->process();
			displayStats(iteration);
			displayCells();
			displayBorder();
			std::cout.flush();
		}
	}

}
void Ocean::displayBorder()
{
	for (unsigned col = 0; col < numCols; col++)
	{
		std::cout << "*";
	}
	std::cout << "\n";
}