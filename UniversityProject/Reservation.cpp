#include "Reservation.h"


void Reservation::copy(Reservation const& other)
{
	password = other.password;
	note = other.note;
	rowNumber = other.rowNumber;
	seat = other.seat;

}
Reservation::Reservation(unsigned _rowNumber, unsigned _seat, MyStr _password, MyStr _note)
	:password(_password), note(_note), rowNumber(_rowNumber), seat(_seat)
{
}

Reservation::Reservation(Reservation const& other)
{
	copy(other);
}
Reservation& Reservation::operator=(Reservation const& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

void Reservation::replaceNote(MyStr newNote)
{
	note = newNote;
}

void Reservation::addToNote(MyStr newNote)
{
	note = note + newNote;
}

bool Reservation::operator==(Reservation const& other) const
{
	return rowNumber == other.rowNumber && password == other.password && note == other.note &&  seat == other.seat;
}

std::ostream& operator<<(std::ostream& out, Reservation const& reservation)
{
	return out << "Reservation: \n"
		<< "RowNumber: " << reservation.getRowNumber() << '\n'
		<< "Seat: " << reservation.getSeat() << '\n'
		<< "Note: " << reservation.getNote();
}

std::istream& operator>>(std::istream& in, Reservation& reservation)
{
	if (&in == &std::cin)
	std::cout << "Creating a password!\n";
	in >> reservation.password;
	//	in.get();
	if (&in == &std::cin)
		std::cout << "Enter the number of the row: ";
	in >> reservation.rowNumber;
	if (&in == &std::cin)
		std::cout << "Enter the number of the seat: ";
	in >> reservation.seat;
	return in;
}