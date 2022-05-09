#ifndef _RESERVATION_HPP
#define _RESERVATION_HPP
#include <cstring>
#include <iostream>

#include "MyStr.h"
class Reservation
{
private:

	MyStr password;
	MyStr note;
	unsigned rowNumber;
	unsigned seat;
	void copy(Reservation const& other);
	//void resize(unsigned newCap);
public:
	Reservation()=default;
	Reservation(unsigned rowNumber,unsigned seat, MyStr _password , MyStr _note);
	Reservation(Reservation const& other) = delete;
	Reservation& operator=(Reservation const& other);
	MyStr getPassword() const { return password; }
	MyStr getNote() const { return note; }
	unsigned getRowNumber() const { return rowNumber; }
	unsigned getSeat() const { return seat; }
	void addToNote(MyStr text);
	void replaceNote(MyStr newNote);

	bool operator==(Reservation const& other) const;
	friend std::istream& operator>>(std::istream& in, Reservation& reservation);
};

std::ostream& operator<<(std::ostream& out, Reservation const& reservation);
#endif // !_RESERVATION__HPP

