#include <iostream>
#include "Ocean.h"
#include "Cell.h"


int main()
{
	Ocean* MyOcean = new Ocean;
	MyOcean->initialize(*MyOcean);
	MyOcean->run();
}