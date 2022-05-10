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

	//����� �������
	Cell* getCellAt(Coordinate aCoord);
	void assignCellAt(Coordinate aCoord, Cell* aCell);
	Cell* getNeighborWithImage(char aImage);
	Coordinate getEmptyNeighborCoord();
	Coordinate getPreyNeighborCoord();
	Cell* north();
	Cell* south();
	Cell* east();
	Cell* west();
	

	//��������� � �����������
	virtual Cell* reproduce(Coordinate anOffset);

public:
	Cell(const Coordinate& aCoord) :offset(aCoord) { Image = DefaultImage; }
	virtual ~Cell() {};
	
	//������
	Coordinate& getOffset() { return offset; }
	void setOffset(Coordinate& anOffset) { offset = anOffset; }
	char getImage();

	//��������� � �����������
	void display();
	virtual void process() {};//������ �� ������

};
#endif // !CellDefined

