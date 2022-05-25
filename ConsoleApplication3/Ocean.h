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
	// TODO: Убрать friend class
	//friend class Cell;

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
	void setCell(Coordinate& a_coord, Cell* a_cell)
	{
		cells[a_coord.getY()][a_coord.getX()] = a_cell;
	}
	//Доступ
	unsigned getNumPrey() 
	{
		return numPrey; 
	}
	unsigned getNumPredators() 
	{ 
		return numPredators;
	}
	unsigned getNumCols() 
	{
		return numCols;
	}
	unsigned getNumRows() 
	{
		return numRows;
	}
	unsigned getNumObstacles() 
	{
		return numObstacles; 
	}
	Cell* getCell(Coordinate a_coord)
	{
		return cells[a_coord.getY()][a_coord.getX()];
	}
	Cell* getCell(unsigned _Rows, unsigned _Cols) 
	{
		return cells[_Rows][_Cols]; 
	}
	void setNumPrey(unsigned aNumber)
	{
		numPrey = aNumber; 
	}
	void setNumPredators(unsigned aNumber) 
	{
		numPredators = aNumber;
	}
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
