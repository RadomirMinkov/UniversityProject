#include "Show.h"

void Show::clear()
{
	delete[] name;
}
Show::~Show()
{
	clear();
}

Show::Show(unsigned _hallNumber,const char* _name, const char* _date)
	:hallNumber(_hallNumber),name(nullptr),seats(nullptr)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	setDate(_date);
}



void Show::copy(Show const& other)
{
	clear();
	name = new char[strlen(other.name)+1];
	strcpy(name, other.name);
	strcpy(date, other.date);
	hallNumber = other.hallNumber;
	seats = nullptr;
	/*seats = new Seats*[rows];
	for (unsigned i = 0; i < rows; i++)
		seats[i] = new Seats[seatsOnRow];
	seats = other.seats;*/
}
char Show::place(Seats seat) const
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
void Show::printSeats(std::ostream& out,unsigned rows,unsigned seatsOnRow)const
{
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < seatsOnRow; j++)
		{
			out << place(seats[i][j]) << ' ';
		}
		out << '\n';
	}
}
void Show::createSeats(unsigned rows, unsigned seatsOnRow)
{
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
Show::Show(Show const& other)
{
	copy(other);
}

Show& Show::operator=(Show const& other)
{
	if (this!=&other)
	{
		copy(other);
	}
	return *this;
}
void Show::setDate(const char* _date)
{
	strcpy(date, _date);
}
void Show::setName(const char* _name)
{
	clear();
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

void Show::setHallNumber(unsigned _hallNumber)
{
	hallNumber = _hallNumber;
}
std::istream& operator>>(std::istream& in, Show& other)
{
	unsigned length;
	in >> other.hallNumber;
	in >> length;
	in.get();
	other.name = new char[length + 1];
	in.getline(other.name,length+1);
	in.getline(other.date, DateLength);
	other.date[DateLength] = '\0';

	return in;
}

std::ostream& operator<<(std::ostream& out, Show const& other)
{
	return out << "Show:\n"
		<<"HallNumber: "<<other.getHallNumber()<<"\n"
		<< "Name: " << other.getName() << '\n'
		<< "Date: " << other.getDate() << '\n';
}