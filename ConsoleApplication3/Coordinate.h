#ifndef CoordinateDefined
#define CoordinateDefined

class Coordinate
{
private:
	 int x;
	 int y;

public:
	Coordinate( int aX,  int aY) :x(aX), y(aY) {};
	Coordinate() { x = 0; y = 0; };
	Coordinate(const Coordinate& aCoord)
	{
		x = aCoord.x;
		y = aCoord.y;
	}

	~Coordinate(void) {};

	//Доступ
	unsigned getX(void) { return x; }
	unsigned getY(void) { return y; }
	void setX(unsigned aX) { x = aX; }
	void setY(unsigned aY) { y = aY; }
	
	//Присвоение и сравнение
	void operator = (const Coordinate& Coord)
	{
		x = Coord.x;
		y = Coord.y;
	}

	int operator == (Coordinate& c)
	{
		return (x == c.x && y == c.y);
	}

	int operator != (Coordinate& c)
	{
		return (x != c.x || y != c.y);

	}
};
#endif // !CoordinateDefined

