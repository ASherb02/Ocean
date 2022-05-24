#ifndef PredatorDefined
#define PredatorDefined
#include "Prey.h"

class Predator :public Prey
{
private:
	//Обработка и отображение
	virtual Cell* reproduce(Coordinate anOffset)
	{
		Predator* temp = new Predator(anOffset, &_owner);
		_owner.setNumPredators(_owner.getNumPredators());
		return (Cell*)temp;
	};

protected:
	unsigned timeToFeed;

public:
	Predator(Coordinate aCoord,Ocean* owner) :Prey(aCoord,owner)
	{
		timeToFeed = TimeToFeed;
		_image = DefaultPredImage;

	}

	virtual ~Predator() {};

	void process()
	{
		if (--timeToFeed <= 0)
		{
			assignCellAt(_offset, nullptr);
			_owner.setNumPrey(_owner.getNumPrey() - 1);
			delete this;
		}
		else
		{
			if (getPreyNeighborCoord(this) != nullptr)
			{
				Coordinate to_coord = getPreyNeighborCoord(this)->getOffset();
				_owner.setNumPrey(_owner.getNumPrey() - 1);
				assignCellAt(to_coord, nullptr);
				timeToFeed =TimeToFeed;
				moveFrom(to_coord, _offset);
			}
			else
			{
				Coordinate to;

				to = getNeighborCoord(this);
				moveFrom(to, _offset);
			}
		}
	}
	char getImage()
	{
		return _image;
	}
};
#endif // !PredatorDefined 
