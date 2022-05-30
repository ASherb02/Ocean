#ifndef PreyDefined
#define PreyDefined
#include "Cell.h"

class Prey :public Cell
{
protected:
	int timeToReproduce;

	//Обработка и отображение
	void moveFrom(Coordinate from, Coordinate to);
	virtual void reproduce(Coordinate anOffset);

public:
	Prey(Coordinate& aCoord,Ocean* owner) :Cell(aCoord,owner)
	{
		timeToReproduce = TimeToReproduce;
		_image = DefaultPreyImage;

	}

	virtual ~Prey(void) {};

	virtual void process()
	{
		Coordinate toCoord;
		toCoord = getNeighborCoord(this);
		moveFrom(_offset, toCoord);
	}

	char getImage()
	{
		return _image;
	}
};


#endif // !PreyDefined


