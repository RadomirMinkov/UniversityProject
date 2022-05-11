#include "Hall.h"

void Hall::copy(Hall const& other)
{
	rows = other.rows;
	seatsOnRow = other.seatsOnRow;
	hallNumber = other.hallNumber;
	shows = other.shows;
}
/*char Hall::place(Seats seat) const
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
}*/
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
void Hall::buyTicket(Show show, unsigned _rowNumber, unsigned _seat)
{
	Seats place;
	MyStr password;
	MyStr userPassword;
	for (unsigned i = 0; i < shows.getSize(); i++)
	{
		if (show == shows[i])
		{
			place = shows[i].getSeat(_rowNumber, _seat);
			switch (place)
			{
			case empty:
				shows[i].buyTicket(_rowNumber, _seat);
				//std::cout<<shows[i].getSeat(_rowNumber, _seat);
				break;
			case reserved:
				password = shows[i].getReservation(_rowNumber, _seat).getPassword();
				std::cout << "The place is reserved. Enter password.";
				std::cin >> userPassword;
				if (password == userPassword)
				{
					shows[i].buyTicket(_rowNumber, _seat);
					shows[i].cancelReservation(shows[i].getReservation(_rowNumber, _seat));
					//shows[i].cancelReservation(Reservation(2, 3, "rado", "penka"));
				}
				break;
			case bought:
				std::cout << "The seat is already bought!";
				break;
			default:
				break;
			}
		}
	}
}

void Hall::reserveTicket(Show show, unsigned _rowNumber, unsigned _seat)
{
	for (unsigned i = 0; i < shows.getSize(); i++)
	{
		if (show == shows[i])
		{
			Reservation reservation;
			std::cin >> reservation;
			MyStr answer;// MyStr();
			do
			{
				std::cout << "Do you want to add note to the reservation?\nAnswer yes or no";
				std::cin >> answer;
				answer.toLower();
			} while (answer != "yes" && answer != "no");
			if (answer == "yes") {
				std::cout << "Enter the note: ";
				std::cin >> answer;
				reservation.replaceNote(answer);
			}
			shows[i].addReservation(reservation);
		}
	}

}
bool Hall::isEmpty()
{
	return shows.getSize() == 0;
}

std::istream& operator>>(std::istream& in, Hall& hall)
{
	return in >> hall.hallNumber >> hall.rows >> hall.seatsOnRow;
}

std::ostream& operator<<(std::ostream& out, Hall const& hall)
{
	return out << "Hall: \n"
		<< "Hall number: " << hall.getHallNumber() << '\n'
		<< "Rows: " << hall.getRows() << '\n'
		<< "Seats on row: " << hall.getSeatsOnRows() << '\n';
}
