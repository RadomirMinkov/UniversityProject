#include "Hall.h"


void Hall::clear()
{
	for (int i = 0; i < rows; i++)
		delete seats[i];
	delete[] seats;
}
Hall::~Hall()
{
	clear();
}

