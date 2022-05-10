#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Cell.h"

class Obstacle : public Cell
{
public:
	Obstacle(const Coordinate& Coord) : Cell(Coord)
	{
		Image = ObstacleImage;
	}

	virtual ~Obstacle() {}
};
#endif