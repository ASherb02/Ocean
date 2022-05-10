/*
#ifndef PredatorDefined
#define PredatorDefined
#include "Prey.h"

class Predator :public Prey
{
private:
	//Обработка и отображение
	virtual Cell* reproduce(Coordinate anOffset);

protected:
	unsigned timeToFeed;

public:
	Predator(Coordinate aCoord) :Prey(aCoord)
	{
		timeToFeed = TimeToFeed;
		Image = DefaultPredImage;

	}

	virtual ~Predator() {};

	void process();
}
#endif // !PredatorDefined 
*/