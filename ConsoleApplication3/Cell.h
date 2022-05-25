#ifndef CellDefined
#define CellDefined

#include"Ocean.h"

class Cell
{

protected:
	 Ocean& _owner;
	Coordinate _offset;
	char _image;

	//����� �������
	Cell* getCellAt(Coordinate,Ocean*);
	void assignCellAt(Coordinate aCoord);
	void assignCellAt(Coordinate aCoord, Cell* aCell);
	Coordinate getNeighborCoord(Cell*);
	Cell* getPreyNeighborCoord(Cell*);
	char north();
	

	//��������� � �����������
	virtual Cell* reproduce();
	//TODO: ��������� ��� SmartPointer
public:
	Cell(const Coordinate& aCoord,Ocean* owner) :_offset(aCoord), _owner(*owner) {
		_image = DefaultImage; }
	virtual ~Cell() {};
	
	//������
	Coordinate& getOffset() { return _offset; }
	void setOffset(Coordinate& anOffset) { _offset = anOffset; }
	char getImage();
	//��������� � �����������
	virtual void process() = 0;

};
#endif // !CellDefined

