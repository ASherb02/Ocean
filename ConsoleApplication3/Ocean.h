#ifndef OceanDefined
#define OceanDefined
#include "Constants.h"
#include "Coordinate.h"
#include "ConsoleOceanViewer.h"
#include "Random.h"
#include "Visitor.h"


class Cell;

class Visitor;

class Ocean
{

private:
	unsigned numRows;
	unsigned numCols;
	unsigned size;
	unsigned numPrey;
	unsigned numPredators;
	unsigned numObstacles;
	Random random;
	Cell* cells[MaxRows][MaxCols];
	ConsoleOceanViewer viewOwner;
	Visitor _visitor;
		
    //Инициализация
	void initCell();
	void cleanGameField();
	void addObstacles();
	void addPredators();
	void addPrey();
	Coordinate getEmptyCellCoord();

public:

	Ocean() : _visitor(MaxRows* MaxCols)
	{

	}
	void swapCell(Coordinate&, Coordinate&, Cell*);
	void setCell(Coordinate& a_coord, Cell* a_cell);
	//Доступ
	unsigned getNumPrey();
	unsigned getNumPredators();
	unsigned getNumCols();
	unsigned getNumRows();
	unsigned getNumObstacles();
	Cell* getCell(Coordinate a_coord);
	Cell* getCell(unsigned _Rows, unsigned _Cols);
	void setNumPrey(unsigned aNumber);
	void setNumPredators(unsigned aNumber);
	//char getChar(Coordinate);
	Coordinate north(Cell*);
	Coordinate west (Cell*);
	Coordinate south(Cell*);
	Coordinate east (Cell*);


	//Инициализация
	void initialize(Ocean&);

	//Запуск
	void run();

};
#endif // !OceanDefined
