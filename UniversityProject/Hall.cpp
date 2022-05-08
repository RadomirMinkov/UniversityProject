#include "Hall.h"


void Hall::clear()
{
	delete[] shows;
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
	shows = new Show[showCapacity];
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
void Hall::resize(unsigned newCapacity)
{
	if (newCapacity < showCapacity)
		return;
	showCapacity = newCapacity;
	Show* newArr = new Show[showCapacity];
	for (unsigned i = 0; i < showSize; i++)
		newArr[i] = shows[i];
	delete[] shows;
	shows = newArr;
}
Hall::Hall(unsigned _hallNumber, unsigned _rows, unsigned _seatsOnRow, unsigned _showCapacity)
	:shows(nullptr), hallNumber(_hallNumber), rows(_rows),
	seatsOnRow(_seatsOnRow), showCapacity(_showCapacity), showSize(0)
{
	shows = new Show[showCapacity];
	/*seats = new Seats*[rows];
	for (unsigned i = 0; i < rows; i++)
	{
		seats[i] = new Seats[seatsOnRow];
		for (unsigned j = 0; j < seatsOnRow; j++)
		{
			seats[i][j] = empty;
		}
	}*/
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


//���������� �� ������� �� �������� �� ������������e
bool Hall::addNewShow(Show const& show) 
{
	if (showSize == showCapacity)
		resize(showCapacity * 2);
	for (unsigned i = 0; i < showSize; i++)
	{
		if (show.getDate() == shows[i].getDate())
			return false;
	}
	shows[showSize] = show;
	shows[showSize++].createSeats(rows, seatsOnRow);
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
	out << "�� ������������� " << show.getName() << "��� "
		<< empty << " �������� �����, "
		<< reserved << " ����������� � "
		<< bought << " ������ ����� ";
}
//���������� �� ������� �� ���������� �� ������
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
				std::cout << "������� � ���� ��������.\n ���� �������� ���� �����\n";
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
