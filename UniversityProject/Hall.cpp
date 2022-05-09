#include "Hall.h"

void Hall::copy(Hall const& other)
{
	showCapacity = other.showCapacity;
	showSize = other.showSize;
	rows = other.rows;
	seatsOnRow = other.seatsOnRow;
	hallNumber = other.hallNumber;
	shows = other.shows;
	for (unsigned i = 0; i < showSize; i++)
		shows[i] = other.shows[i];
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
void Hall::showSeats(std::ostream& out, Show const& show) const
{
	show.printSeats(out, rows, seatsOnRow);
}

Hall::Hall(unsigned _hallNumber, unsigned _rows, unsigned _seatsOnRow, unsigned _showCapacity)
	: hallNumber(_hallNumber), rows(_rows),seatsOnRow(_seatsOnRow), showCapacity(_showCapacity), showSize(0)
{
	shows = MyVector<Show>();
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

bool Hall::isReserved(Date _date)
{
	for (unsigned i = 0; i < showSize; i++)
		if (_date==shows[i].getDate() == 0)
			return true;
	return false;
}


//реализация на функция за добавяне на представлениe
bool Hall::addNewShow(Show const& show) 
{
	for (unsigned i = 0; i < shows.getSize(); i++)
	{
		if (show.getDate()==shows[i].getDate())
		{
			return false;
		}
	}
	shows.addElement(show);
	shows[shows.getSize()].createSeats(rows, seatsOnRow);
	shows.setSize(shows.getSize() + 1);
	return true;
}

int Hall::getNumberOfSeats() const
{
	return rows * seatsOnRow;
}

void Hall::seatsReference(Show const& show,std::ostream& out) const
{
	unsigned empty{0};
	unsigned reserved{0};
	unsigned bought{0};
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < seatsOnRow; j++)
		{
			switch (place(show.getSeat(i,j)))
			{
			case 0:
				empty++;
				break;
			case 1:
				reserved++;
				break;
			case 2:
				bought++;
				break;
			}
		}
	}
	out << "За представление " << show.getName() << "има "
		<< empty << " свободни места, "
		<< reserved << " резервирани и "
		<< bought << " купени места ";
}
//реализация на функция за закупуване на билети
/*void Hall::buyTickets(unsigned _rowNumber, int* _seats, unsigned numberOfSeats)
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
}*/
bool Hall::isEmpty()
{
	return showSize == 0;
}
