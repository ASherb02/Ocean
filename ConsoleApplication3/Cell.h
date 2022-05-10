#ifndef CellDefined
#define CellDefined

#include"Ocean.h"

class Cell
{
	friend class Ocean;

protected:
	static Ocean* Ocean1;
	Coordinate offset;
	char Image;

	//Поиск соседей
	Cell* getCellAt(Coordinate aCoord);
	void assignCellAt(Coordinate aCoord, Cell* aCell);
	Cell* getNeighborWithImage(char aImage);
	Coordinate getEmptyNeighborCoord();
	Coordinate getPreyNeighborCoord();
	Cell* north();
	Cell* south();
	Cell* east();
	Cell* west();
	

	//Обработка и отображение
	virtual Cell* reproduce(Coordinate anOffset);

public:
	Cell(const Coordinate& aCoord) :offset(aCoord) { Image = DefaultImage; }
	virtual ~Cell() {};
	
	//Доступ
	Coordinate& getOffset() { return offset; }
	void setOffset(Coordinate& anOffset) { offset = anOffset; }
	char getImage();

	//Обработка и отображение
	void display();
	virtual void process() {};//ничего не делает

};
#endif // !CellDefined

