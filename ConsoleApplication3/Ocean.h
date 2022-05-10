#ifndef OceanDefined
#define OceanDefined
#include "Constants.h"
#include "Coordinate.h"
#include "Random.h"
#pragma once

class Cell;

class Ocean
{
	friend class Cell;

private:
	unsigned numRows;
	unsigned numCols;
	unsigned size;//numRows*numCols
	unsigned numPrey;
	unsigned numPredators;
	unsigned numObstacles;
	Random random;
	Cell* cells[MaxRows][MaxCols];
		
    //Инициализация
	void initCell();
	void addEmptyCells();
	void addObstacles();
	//void addPredators();
	void addPrey();
	Coordinate getEmptyCellCoord();

	//Отображение
	void displayBorder();
	void displayCells();
	void displayStats(int);

public:

	//Доступ
	unsigned getNumPrey(void) { return numPrey; }
	unsigned getNumPredators(void) { return numPredators; }
	void setNumPrey(unsigned aNumber) { numPrey = aNumber; }
	void setNumPredators(unsigned aNumber) { numPredators = aNumber; }

	//Инициализация
	void initialize(void);

	//Запуск
	void run(void);

};
#endif // !OceanDefined
