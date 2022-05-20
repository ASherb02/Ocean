#ifndef OceanDefined
#define OceanDefined
#include "Constants.h"
#include "Coordinate.h"
#include "ConsoleOceanViewer.h"
#include "Random.h"
#pragma once

class Cell;

class Ocean
{
	// TODO: ������ friend class
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
	ConsoleOceanViewer viewOwner;
		
    //�������������
	void initCell();
	void addEmptyCells();
	void addObstacles();
	void addPredators();
	void addPrey();
	Coordinate getEmptyCellCoord();

public:

	//������
	unsigned getNumPrey() { return numPrey; }
	unsigned getNumPredators() { return numPredators; }
	unsigned getNumCols() { return numCols; }
	unsigned getNumRows() { return numRows; }
	unsigned getNumObstacles() { return numObstacles; }
	Cell* getCells(unsigned _Rows, unsigned _Cols) { return cells[_Rows][_Cols]; }
	void setNumPrey(unsigned aNumber) { numPrey = aNumber; }
	void setNumPredators(unsigned aNumber) { numPredators = aNumber; }
	//char getChar(Coordinate);


	//�������������
	void initialize(Ocean&);

	//������
	void run(void);

};
#endif // !OceanDefined
