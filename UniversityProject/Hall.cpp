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
	seats = new Seats*[rows];
	for (unsigned i = 0; i < rows; i++)
		seats[i] = new Seats[seatsOnRow];
	seats = other.seats;
}
void Hall::resize(unsigned newCapacity)
{
	if (newCapacity < showCapacity)
		return;
	showCapacity = newCapacity;
	Show* newArr = new Show[showCapacity];
	for (unsigned i = 0; i < showSize; i++)
		newArr[i] = show[i];
	delete[] show;
	show = newArr;
}
Hall::Hall(unsigned _hallNumber, unsigned _rows, unsigned _seatsOnRow, unsigned _showCapacity)
	:show(nullptr), hallNumber(_hallNumber), rows(_rows),
	seatsOnRow(_seatsOnRow), seats(nullptr), showCapacity(_showCapacity), showSize(0)
{
	show = new Show[showCapacity];
	seats = new Seats*[rows];
	for (unsigned i = 0; i < rows; i++)
	{
		seats[i] = new Seats[seatsOnRow];
		for (unsigned j = 0; j < seatsOnRow; j++)
		{
			seats[i][j] = empty;
		}
	}
}

Hall::Hall(Hall const& other)
{
	copy(other);
}

Hall& Hall::operator=(Hall const& other)
{
	if (this != &other)
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

char Hall::place(Seats seat) const
{
	char c{};
	switch (seat)
	{
	case empty:
		c = 'E';
		break;
	case reserved:
		c = 'R';
		break;
	case bought:
		c = 'B';
		break;
	default:
		break;
	}
	return c;
}
void Hall::showSeats(std::ostream& out) const
{

	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < seatsOnRow; j++)
		{
			//	std::cout << seats[i][j];
			std::cout << place(seats[i][j]) << ' ';
		}
		out << '\n';
	}
}

void Hall::buyTickets(unsigned _rowNumber, int* _seats, unsigned numberOfSeats)
{
	for (unsigned i = 0; i < numberOfSeats; i++)
	{
		int place = _seats[i] + 1;
		while (seats[_rowNumber - 1][place] == bought)
		{
			if (seats[_rowNumber - 1][place] == bought)
			{
				//TO DO
			}
			else
			{
				std::cout << "Мястото е вече запазено.\n Моля въведете ново място\n";
				this->showSeats(std::cout);
				std::cin >> place;
			}
		}
		seats[_rowNumber - 1][place] = bought;
	}
}
bool Hall::isEmpty()
{
	return showSize == 0;
}
