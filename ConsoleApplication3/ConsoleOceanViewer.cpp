#include "ConsoleOceanViewer.h"
#include "Cell.h"
#include "Ocean.h"
#include <iostream>

void ConsoleOceanViewer::display(char _image)
{
	std::cout << _image;
}

void ConsoleOceanViewer::displayBorder(unsigned _NumCols)
{
	for (unsigned col = 0; col < _NumCols; col++)
	{
		std::cout << "*";
	}
	std::cout << "\n";
}

void ConsoleOceanViewer::displayStats(unsigned _numObstacles, unsigned _numPredators,unsigned _numPrey,unsigned _iteration,unsigned _numCols)
{
	std::cout << "\n\n";
	std::cout << "Iteration number" << ++_iteration;
	std::cout << std::endl;
	std::cout << "Obstacles:" << _numObstacles;
	std::cout << std::endl;
	std::cout << "Prey:" << _numPrey;
	std::cout << std::endl;
	std::cout << "Predators:" << _numPredators << "\n";
	std::cout.flush();
	displayBorder(_numCols);
}

void ConsoleOceanViewer::displayCells(unsigned _numRows, unsigned _numCols,Ocean * _owner)
{
	Cell* _cell;
	for (unsigned row = 0; row < _numRows; row++)
	{
		for (unsigned col = 0; col < _numCols; col++)
		{
			_cell = _owner->getCell(row,col);
			if (_cell == nullptr)
			{
				display(DefaultImage);
			}
			else
			{
				display(_cell->getImage());
			}
		}
		std::cout << "\n";
	}
}