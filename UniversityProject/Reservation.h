#ifndef _RESERVATION_HPP
#define _RESERVATION_HPP
#include <cstring>
#include <iostream>

class Reservation
{
private:

	char* password;
	char* note;
	unsigned rowNumber;
	unsigned seat;
	void clear();
	void copy(Reservation const& other);
	//void resize(unsigned newCap);
public:
	Reservation(const char* _password=nullptr, const char* _note=nullptr,unsigned rowNumber=0,unsigned seat=0);
	Reservation(Reservation const& other) = delete;
	Reservation& operator=(Reservation const& other);
	~Reservation();
	const char* getPassword() const { return password; }
	const char* getNote() const { return note; }
	unsigned getRowNumber() const { return rowNumber; }
	unsigned getSeat() const { return seat; }
	void addToNote(const char* text);
	void replaceNote(const char* text);

	friend std::istream& operator>>(std::istream& in, Reservation& reservation);
};

std::ostream& operator<<(std::ostream& out, Reservation& reservation);
#endif // !_RESERVATION__HPP

