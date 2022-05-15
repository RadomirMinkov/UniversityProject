#include "Hall.h"

void Hall::copy(Hall const& other)
{
	rows = other.rows;
	seatsOnRow = other.seatsOnRow;
	hallNumber = other.hallNumber;
	shows = other.shows;
}
void Hall::showSeats(std::ostream& out, Show const& show) const
{
	unsigned i{ 0 };
	while (!(show == shows[i]) && i < shows.getSize())
		i++;
	if (i != shows.getSize())
		shows[i].printSeats(std::cout, rows, seatsOnRow);
}


Hall::Hall(unsigned _hallNumber, unsigned _rows, unsigned _seatsOnRow)
	: hallNumber(_hallNumber), rows(_rows), seatsOnRow(_seatsOnRow)
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
	for (unsigned i = 0; i < shows.getSize(); i++)
		if (_date == shows[i].getDate() == 0)
			return true;
	return false;
}


//реализация на функция за добавяне на представлениe
bool Hall::addNewShow(Show const& show)
{
	for (unsigned i = 0; i < shows.getSize(); i++)
	{
		if (show.getDate() == shows[i].getDate())
		{
			return false;
		}
	}
	shows.addElement(show);
	return true;
}
void Hall::print(std::ostream& out)const
{
	out << *this;
}
void Hall::printEmptySeats(std::ostream& out, Show const& show) const
{
	for (unsigned i = 0; i < shows.getSize(); i++)
	{
		if (show == shows[i])
		{
			unsigned emptySeats = getNumberOfSeats() - shows[i].getReservedTickets() - shows[i].getSoldTickets();
			out << "There are " << emptySeats << " seats for the show!\n";
			shows[i].printSeats(out, rows, seatsOnRow);
			shows[i].printSeatsType(out, empty);
		}
	}
}

void Hall::printReservedSeats(std::ofstream& out, Date const& date, MyStr const& name)const
{
	if (name == "all")
	{
		for (unsigned i = 0; i < shows.getSize(); i++)
		{
			if (date == shows[i].getDate())
			{
				out << shows[i];
				out << "For this show " << shows[i].getReservedTickets() << " are reserved!\n";
				shows[i].printSeatsType(out, reserved);
				shows[i].printSeats(out, rows, seatsOnRow);
			}
		}
	}
	else
	{
		for (unsigned i = 0; i < shows.getSize(); i++)
		{
			if (date == shows[i].getDate() && name == shows[i].getName())
			{
				out << shows[i];
				out << "For this show " << shows[i].getReservedTickets() << " are reserved!\n";
				shows[i].printSeatsType(out, reserved);
				shows[i].printSeats(out, rows, seatsOnRow);
			}
		}
	}

}

void Hall::printBoughtSeats(std::ofstream& out, Date const& beginingDate, Date const& endingDate)const
{

	for (unsigned i = 0; i < shows.getSize(); i++)
	{
		if (shows[i].getDate() >= beginingDate && shows[i].getDate() <= endingDate)
		{
			out << shows[i];
			out << "For this show " << shows[i].getSoldTickets() << " are bought!\n";
			shows[i].printSeatsType(out, bought);
			shows[i].printSeats(out, rows, seatsOnRow);
		}
	}
}
int Hall::getNumberOfSeats() const
{
	return rows * seatsOnRow;
}

void Hall::seatsReference(Show const& show, std::ostream& out) const
{
	unsigned empty{ 0 };
	unsigned reserved{ 0 };
	unsigned bought{ 0 };
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < seatsOnRow; j++)
		{
			switch (show.place(show.getSeat(i, j)))
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
bool Hall::buyTicket(Show const& show)
{
	Seats place;
	MyStr password;
	MyStr userPassword;
	for (unsigned i = 0; i < shows.getSize(); i++)
	{
		if (show == shows[i])
		{
			shows[i].printSeats(std::cout,rows, seatsOnRow);
			std::cout << "You are buying a ticket!\n";
			unsigned rowNumber;
			unsigned seat;
			std::cout << "Enter row: ";
			std::cin >> rowNumber;
			std::cout << "Enter seat: ";
			std::cin >> seat;
			place = shows[i].getSeat(rowNumber, seat);
			switch (place)
			{
			case empty:
				shows[i].buyTicket(rowNumber, seat);
				return true;
				break;
			case reserved:
				password = shows[i].getReservation(rowNumber, seat).getPassword();
				std::cout << "The place is reserved. Enter password.\n";
				std::cin >> userPassword;
				if (password == userPassword)
				{
					shows[i].buyTicket(rowNumber, seat);
					shows[i].cancelReservation(shows[i].getReservation(rowNumber, seat));
					return true;
				}
				return false;
				break;
			case bought:
				std::cout << "The seat is already bought!";
				return true;
				break;
			default:
				break;
			}
		}
	}
	return false;
}

Reservation Hall::enterReservatoin()const
{
	Reservation reservation;
	std::cin >> reservation;
	MyStr answer;
	do
	{
		std::cout << "Do you want to add note to the reservation?\nAnswer yes or no\n";
		std::cin >> answer;
		//std::cin.ignore();
		answer.toLower();
	} while (answer != "yes" && answer != "no");
	if (answer == "yes") {
		std::cout << "Enter the note: ";
		std::cin >> answer;
		reservation.replaceNote(answer);
	}
	return reservation;
}
bool Hall::reserveTicket(Show const& show)
{
	for (unsigned i = 0; i < shows.getSize(); i++)
	{
		if (show == shows[i])
		{
			shows[i].printSeats(std::cout, rows, seatsOnRow);
			std::cout << "You are making a new reservation:\n";
			Reservation reservation = enterReservatoin();
			Seats seat{};
			seat = shows[i].getSeat(reservation.getRowNumber(), reservation.getSeat());
			switch (seat)
			{
			case empty:
				shows[i].updateSeats(reservation.getRowNumber(), reservation.getSeat(), reserved);
				shows[i].addReservation(reservation);
				return true;
				break;
			case reserved:
				"The place is already reserved!!!";
				return false;
				break;
			case bought:
				"The place is already bought!!!";
				return false;
				break;
			default:
				break;
			}
		}
	}
	return false;
}
bool Hall::isEmpty()
{
	return shows.getSize() == 0;
}
bool Hall::operator==(Hall const& other)const
{
	return (hallNumber == other.hallNumber) && (rows == other.rows) && (seatsOnRow == other.seatsOnRow);
}

std::istream& operator>>(std::istream& in, Hall& hall)
{
	if (&in == &std::cin)
	{
		std::cout << "Hall:\n";
		std::cout << "Hall number:";
	}
	in >> hall.hallNumber;
	if (&in == &std::cin)
		std::cout << "Enter rows: ";
	in >> hall.rows;
	if (&in == &std::cin)
		std::cout << "Enter seats on row: ";
	return in >> hall.seatsOnRow;
}

bool Hall::cancelShowReservation(std::istream& in, Show const& show)
{
	for (unsigned i = 0; i < shows.getSize(); i++)
	{
		if (show == shows[i])
		{
			shows[i].printSeats(std::cout, rows, seatsOnRow);
			std::cout << "Enter the reservation that you want to cancel:\n";
			Reservation reservation = enterReservatoin();
			return shows[i].cancelReservation(reservation);
		}
	}
	return false;
}
void Hall::readFromText(std::ifstream& out)
{
	out >> *this;
}

std::ostream& operator<<(std::ostream& out, Hall const& hall)
{
	return out << "Hall: \n"
		<< "Hall number: " << hall.getHallNumber() << '\n'
		<< "Rows: " << hall.getRows() << '\n'
		<< "Seats on row: " << hall.getSeatsOnRows() << '\n';
}
