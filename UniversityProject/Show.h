#ifndef _SHOW_HPP
#define _SHOW_HPP
#include <cstring>
#include <iostream>

//#include "Hall.h"
const int DateLength = 11;

enum Seats
{
	empty = 0,
	reserved = 1,
	bought = 2
};
class Show
{
private:
	 char* name;
	  char date[DateLength];
	  unsigned hallNumber;
	  unsigned rows;
	  unsigned columns;
	  //масив за местата за дадено шоу
	  Seats** seats;
	void clear();
	void copy(Show const& other);
	//дава информация за мястото
	char place(Seats seat) const;
public:
	Show(unsigned _hallNumber=0, const char* _name = "unknown", const char* _date = "unknown");
	Show(Show const& other);
	~Show();
	Show& operator=(Show const& other);

	const char* getName() const { return name; }
	const char* getDate() const { return date; }
	unsigned getHallNumber() const { return hallNumber; }
	Seats getSeat(unsigned rowNumber, unsigned seat) const;
	void setHallNumber(unsigned _hallNumber);
	void setName(const char* _name);
	void setDate(const char* _date);
	void printSeats(std::ostream& out,unsigned rows,unsigned seatsOnRow)const;
	void createSeats(unsigned rows,unsigned seatsOnRow);
	//void updateSeats(unsigned rowNumber, )
	//осигуряване на оператор за въвеждане
	friend std::istream& operator>>(std::istream& in, Show& other);
};


//осигуряване на операор за извеждане
std::ostream& operator<<(std::ostream&  out, Show const& other);

#endif // !_SHOW_HPP



