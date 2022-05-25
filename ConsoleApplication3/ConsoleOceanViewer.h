#pragma once
class Ocean;

class ConsoleOceanViewer
{
	public:

	void display(char);
	void displayBorder(unsigned);
	void displayStats(unsigned, unsigned , unsigned, unsigned,unsigned);
	void displayCells(unsigned, unsigned,Ocean*);
};

