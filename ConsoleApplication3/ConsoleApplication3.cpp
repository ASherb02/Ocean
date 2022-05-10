#include <iostream>
#include "Ocean.h"
#include "Cell.h"

Ocean* Cell::Ocean1 = nullptr;

int main()
{
	Ocean* MyOcean = new Ocean;
	MyOcean->initialize();
	MyOcean->run();
}