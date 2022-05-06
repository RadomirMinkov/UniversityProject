#include "Reservation.h"

void Reservation::clear()
{
	delete[] password;
	delete[] note;
}

Reservation::~Reservation()
{
	clear();
}

void Reservation::copy(Reservation const& other)
{
	clear();
	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);
	note = new char[strlen(other.note) + 1];
	strcpy(note, other.note);
	rowNumber = other.rowNumber;
	seat = other.seat;

}
Reservation::Reservation(const char* _password, const char* _note,unsigned _rowNumber,unsigned _seat)
	:password(nullptr), note(nullptr),rowNumber(_rowNumber), seat(_seat)
{
	password = new char[strlen(_password) + 1];
	strcpy(password, _password);
	note = new char[strlen(_note) + 1];
	strcpy(note, _note);
}
Reservation& Reservation::operator=(Reservation const& other)
{
	if (this!=&other)
	{
		copy(other);
	}
	return *this;
}

void Reservation::replaceNote(const char* newNote)
{
	delete[] note;
	note = new char[strlen(newNote) + 1];
	strcpy(note, newNote);
}

void Reservation::addToNote(const char* newNote)
{
	char* temp = new char[strlen(note) + strlen(newNote) +1];
	strcpy(temp, note);
	strcat(temp, newNote);
	delete[] note;
	note = new char[strlen(temp) + 1];
	strcpy(note, temp);
	//strcat(note, newNote);
	//std::cout << ' ' << strlen(note) << ' ' << strlen(temp) << ' ' << strlen(newNote);
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
	size_t length{ 0 };
	in >> length;
	reservation.password = new char[length + 1];
	in.getline(reservation.password, length + 1);
	in.get();
	in >> reservation.rowNumber;
	in >> reservation.seat;
	in >> length;
	reservation.note = nullptr;
	return in;
}