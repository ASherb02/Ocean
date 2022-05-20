#ifndef PredatorDefined
#define PredatorDefined
#include "Prey.h"

class Predator :public Prey
{
private:
	//��������� � �����������
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
		Coordinate toCoord;
		if (--timeToFeed <= 0)//������ �������
		{
			assignCellAt(_offset);
			_owner.setNumPredators(_owner.getNumPredators() - 1);
			delete this;
		}
		else//������� �������� ������
		{
			toCoord = getPreyNeighborCoord();
			if (toCoord != _offset)
			{
				_owner.setNumPrey(_owner.getNumPrey() - 1);
				timeToFeed = TimeToFeed;
				moveFrom(_offset, toCoord);
			}
			else
				Prey::process();//����������� � ������ ������
		}
	}
	char getImage()
	{
		return _image;
	}
};
#endif // !PredatorDefined 
