#include "Show.h"


Show::Show()
	:hallNumber(0), name(nullptr), seats(nullptr)
{
	Date newDate;
	date = newDate;
	reservations = MyVector<Reservation>(2);
}
bool Show::cancelReservation(Reservation reservation)
{
	for (unsigned i = 0; i <reservations.getSize(); i++) {
		if (reservations[i] == reservation)
		{
			for (unsigned j = i; j < reservations.getSize(); j++)
			{
				reservations[j] = reservations[j + 1];
			}
			reservations.setSize(reservations.getSize()-1);
			return true;
		}
	}
	return false;
}
Show::Show( unsigned _hallNumber,MyStr _name, Date _date,unsigned _capacity)
	: hallNumber(_hallNumber), name(_name), seats(nullptr)
{
	reservations = MyVector<Reservation>(_capacity);
	setDate(_date);
}


void Show::updateSeats(unsigned rowNumber, unsigned place,Seats seatType)
{
	seats[rowNumber - 1][place - 1] = seatType;
}

void Show::addReservation(Reservation const& reservation)
{
	reservations.addElement(reservation);
}
void Show::copy(Show const& other)
{
	name = other.name;
	date = other.date;
	hallNumber = other.hallNumber;
	seats = nullptr;
	reservations = other.reservations;
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
void Show::buyTicket(unsigned rowNumber, unsigned seat)
{
	updateSeats(rowNumber, seat, bought);
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
void Show::setName(MyStr _name)
{
	name = _name;
}

void Show::setHallNumber(unsigned _hallNumber)
{
	hallNumber = _hallNumber;
}
std::istream& operator>>(std::istream& in, Show& other)
{
	in >> other.hallNumber;
	in >> other.name;
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