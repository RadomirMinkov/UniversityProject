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

std::ostream& operator<<(std::ostream& out, Reservation const& reservation)
{
	return out << "Reservation: \n"
		<< "RowNumber: " << reservation.getRowNumber() << '\n'
		<< "Seat: " << reservation.getSeat() << '\n'
		<< "Note: " << reservation.getNote();
}

bool Reservation::operator==(Reservation const& other) const
{
	return rowNumber == other.rowNumber && password == other.password && note == other.note &&  seat == other.seat;
}

std::istream& operator>>(std::istream& in, Reservation& reservation)
{
	if (&in == &std::cin)
		std::cout << "You are entering reservation:\n";
	in >> reservation.password;
	//	in.get();
	in >> reservation.rowNumber;
	in >> reservation.seat;
	return in;
}