#include "Random.h"
#include <math.h>
#include <stdlib.h>
#define MAX 32767

float Random::randReal()
{
	int c;
	int first=1;
	
	/* од выполн€етс€ 1 раз*/
	if (first)
	{
		seed1 *= 2;
		seed2 *= 2;
		if (seed1 > MAX)seed1 = MAX;
		if (seed2 > MAX)seed2 = MAX;
		first = 0;
	}
	//возбуждение генератора
	for (int index = 1; index <= 30; index++)
	{
		randReal();
	}
	c = seed1 + seed2;
	if (c > MAX)c = MAX;
	c *= 2;
	if (c > MAX)c = MAX;
	seed1 = seed2;
	seed2 = c;
	return (double)c / 32767.0;
}

int Random::NextBetween(int low, int high)
{
	high++;

	return abs(rand() % (high - low)) + low;
}