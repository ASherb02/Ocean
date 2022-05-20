#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Cell.h"

class Obstacle : public Cell
{
public:
	Obstacle(const Coordinate& Coord,Ocean* owner) : Cell(Coord, owner)
	{
		_image = ObstacleImage;
	}
	void process()
	{

	}
	virtual ~Obstacle() {}
};
#endif