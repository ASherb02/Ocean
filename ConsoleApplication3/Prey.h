/*#ifndef PreyDefined
#define PreyDefined
#include "Cell.h"

class Prey :public Cell
{
protected:
	int timeToReproduce;

	//Обработка и отображение
	void moveFrom(Coordinate from, Coordinate to);
	virtual Cell* reproduce(Coordinate anOffset);

public:
	Prey(Coordinate& aCoord) :Cell(aCoord)
	{
		timeToReproduce = TimeToReproduce;
		Image = DefaultPreyImage;

	}

	virtual ~Prey(void) {};

	virtual void procces(void)
	{
		Coordinate toCoord;
		toCoord = getEmptyNeighborCoord();
		moveFrom(offset, toCoord);

	}

};


#endif // !PreyDefined
*/


