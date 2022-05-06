#include "Show.h"

void Show::clear()
{
	delete[] name;
	delete[] reservations;
}
Show::~Show()
{
	clear();
}

Show::Show()
	:hallNumber(0), name(nullptr), seats(nullptr),reservations(nullptr),capacity(2),size(0)
{
	Date newDate;
	date = newDate;
}
Show::Show(Date _date, unsigned _hallNumber, const char* _name,unsigned _capacity)
	: hallNumber(_hallNumber), name(nullptr), seats(nullptr),size(0),capacity(_capacity),reservations(nullptr)
{
	reservations = new Reservation[capacity];
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	setDate(_date);
}

void Show::resize(unsigned newCap)
{
	if (capacity <= newCap)
		return;
	capacity = newCap;
	Reservation* newArr = new Reservation[capacity];
	for (unsigned i = 0; i < size; i++)
		newArr[i] = reservations[i];
	delete[] reservations;
	reservations = newArr;
}
void Show::copy(Show const& other)
{
	clear();
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	date = other.date;
	hallNumber = other.hallNumber;
	seats = nullptr;
	capacity = other.capacity;
	size = other.size;
	reservations = new Reservation[capacity];
	for (int i = 0; i < size; i++)
		reservations[i] = other.reservations[i];
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
void Show::printSeats(std::ostream& out, unsigned rows, unsigned seatsOnRow)const
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
Seats Show::getSeat(unsigned rowNumber, unsigned seat) const
{
	return seats[rowNumber - 1][seat - 1];
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
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
void Show::setDate(Date newDate)
{
	date = newDate;
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
	in.getline(other.name, length + 1);
	in >> other.date;
	return in;
}

std::ostream& operator<<(std::ostream& out, Show const& other)
{
	return out << "Show:\n"
		<< "Hall: " << other.getHallNumber() << "\n"
		<< "Name: " << other.getName() << '\n'
		<< "Date: " << other.getDate() << '\n';
}