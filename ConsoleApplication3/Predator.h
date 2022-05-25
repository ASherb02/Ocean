#ifndef PredatorDefined
#define PredatorDefined
#include "Prey.h"

class Predator :public Prey
{
private:
	//Обработка и отображение
	void reproduce(Coordinate an_offset)
	{
		Predator* temp = new Predator(an_offset, &_owner);
		_owner.setNumPredators(_owner.getNumPredators() + 1);
		assignCellAt(an_offset, temp);
	}

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
	void moveFrom (Coordinate to, Coordinate from)
	{
		--timeToReproduce;
		if (to != from)
		{
			if (_owner.getCell(to) == nullptr)
			{
				this->setOffset(to);
				_owner.swapCell(to, from, this);
			}
			std::cout.flush();
			if (timeToReproduce <= 0)
			{
				timeToReproduce = TimeToReproduce;
				reproduce(from);
			}
			else
			{
				assignCellAt(from, nullptr);
			}
		}
	}
	
	char getImage()
	{
		return _image;
	}
};
#endif // !PredatorDefined 
