#include "Hall.h"


void Hall::clear()
{
	for (unsigned i = 0; i < rows; i++)
		delete seats[i];
	delete[] seats;
	delete[] show;
}
Hall::~Hall()
{
	clear();
}

void Hall::copy(Hall const& other)
{
	clear();
	showCapacity = other.showCapacity;
	showSize = other.showSize;
	rows = other.rows;
	seatsOnRow = other.seatsOnRow;
	hallNumber = other.hallNumber;
	show = new Show[showCapacity];
	for (unsigned i = 0; i < showSize; i++)
		show[i] = other.show[i];
	seats = new bool*[rows];
	for (unsigned i = 0; i < rows; i++)
		seats[i] = new bool[seatsOnRow];
	seats = other.seats;
}
void Hall::resize(unsigned newCapacity)
{
	if (newCapacity < showCapacity)
		return;
	showCapacity = newCapacity;
	Show* newArr=new Show[showCapacity];
	for (unsigned i = 0; i < showSize; i++)
		newArr[i] = show[i];
	delete[] show;
	show = newArr;
}
Hall::Hall(unsigned _hallNumber,unsigned _rows, unsigned _seatsOnRow,unsigned _showCapacity)
	:show(nullptr),hallNumber(_hallNumber), rows(_rows), 
	seatsOnRow(_seatsOnRow),seats(nullptr), showCapacity(_showCapacity),showSize(0)
{
	show = new Show[showCapacity];
	seats = new bool*[rows];
	for (unsigned i = 0; i < rows; i++)
		seats[i] = new bool[seatsOnRow];
}

Hall::Hall(Hall const& other)
{
	copy(other);
}

Hall& Hall::operator=(Hall const& other)
{
	if (this!=&other)
	{
		copy(other);
	}
	return *this;
}

bool Hall::isReserved(const char* date)
{
	for (unsigned i = 0; i < showSize; i++)
		if (strcmp(date, show[i].getDate()) == 0)
			return true;
	return false;
}

void Hall::showSeats(std::ostream& out) const
{
	char fullSpot = 251;
	char emptySpot = 'X';
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < seatsOnRow; j++)
		{
			if (seats[i][j] == 0)
				out << fullSpot<<' ';
			out << emptySpot << ' ';
		}
		out << '\n';
	}
}
bool Hall::isEmpty()
{
	return showSize == 0;
}
