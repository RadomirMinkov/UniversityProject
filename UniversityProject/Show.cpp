#include "Show.h"


void Show::clear()
{
	//printSeats(std::cout, hall->getRows(), hall->getSeatsOnRows());
	if (hall == nullptr)
		return;
	for (unsigned i = 0; i < hall->getRows(); i++)
		delete seats[i];
	delete[] seats;
}
Show::~Show()
{
	//std::cout << *this;
	clear();
}

const char* Show::getSeatStringType(Seats seat)const
{
	switch (seat)
	{
	case empty:
		return "empty";
		break;
	case reserved:
		return "reserved";
		break;
	case bought:
		return "bought";
		break;
	default:
		break;
	}
}
bool Show::cancelReservation(Reservation reservation)
{
	for (unsigned i = 0; i < reservations.getSize(); i++) {
		if (reservations[i] == reservation)
		{
			for (unsigned j = i; j < reservations.getSize() - 1; j++)
			{
				reservations[j] = reservations[j + 1];
			}
			reservations.setSize(reservations.getSize() - 1);
			updateSeats(reservation.getRowNumber(), reservation.getSeat(), empty);
			return true;
		}
	}
	return false;
}
Show::Show(MyStr _name, Date _date, unsigned _capacity, Hall* _hall)
	: name(_name), seats(nullptr), hall(_hall), soldTickets(0)
{
	reservations = MyVector<Reservation>(_capacity);
	setDate(_date);
	createSeats(hall->getRows(), hall->getSeatsOnRows());
}


void Show::updateSeats(unsigned rowNumber, unsigned place, Seats seatType)
{
	seats[rowNumber - 1][place - 1] = seatType;
}

void Show::addReservation(Reservation const& reservation)
{
	reservations.addElement(reservation);
	updateSeats(reservation.getRowNumber(), reservation.getSeat(), reserved);
	reservedTickets++;
}
void Show::copy(Show const& other)
{
	name = other.name;
	date = other.date;
	hall = other.hall;
	reservations = other.reservations;
	seats = new Seats*[hall->getRows()];
	for (unsigned i = 0; i < hall->getRows(); i++)
	{
		seats[i] = new Seats[hall->getSeatsOnRows()];
		for (unsigned j = 0; j < hall->getSeatsOnRows(); j++)
			seats[i][j] = other.seats[i][j];
	}
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
Reservation Show::getReservation(unsigned row, unsigned seat)const
{
	Reservation reservation;
	for (unsigned i = 0; i < reservations.getSize(); i++)
	{
		if (row == reservations[i].getRowNumber() && seat == reservations[i].getSeat())
			reservation = reservations[i];
	}
	return reservation;
}
Seats Show::getSeat(unsigned rowNumber, unsigned seat) const
{
	return seats[rowNumber - 1][seat - 1];
}
void Show::buyTicket(unsigned rowNumber, unsigned seat)
{
	updateSeats(rowNumber, seat, bought);
	soldTickets++;
}

void Show::printSeatsType(std::ostream& out, Seats seat)const
{
	for (unsigned i = 0; i < hall->getRows(); i++)
	{
		for (unsigned j = 0; j < hall->getSeatsOnRows(); j++)
		{
			if (seats[i][j] == seat)
			{
				out << "Place: (" << i + 1 << ',' << j + 1 << ") is " << getSeatStringType(seat) << "!\n";
			}
		}
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
Show::Show()
{
	hall = nullptr;
	seats = nullptr;
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
void Show::printReservations(std::ostream& out)const
{
	for (unsigned i = 0; i < reservations.getSize(); i++)
		out << reservations[i];
}
bool Show::operator==(Show const& other)const
{
	return hall == other.hall && name == name && date == other.date;
}
std::istream& operator>>(std::istream& in, Show& other)
{
	std::cout << "Show:\n";
	other.seats = nullptr;
	Hall hall;
	in >> hall;
	other.hall = &hall;
	if (&std::cin == &in)
		std::cout << "Enter the name of the show\n";
	in >> other.name;
	if (&std::cin == &in)
		std::cout << "Enter the date of the show\n";
	return	in >> other.date;

}

std::ostream& operator<<(std::ostream& out, Show const& other)
{
	out << "Show:\n";
	other.getHall()->print(std::cout);
	out << "Name: " << other.getName() << '\n'
		<< "Date: " << other.getDate() << '\n';
	other.printReservations(out);
	return out;
}