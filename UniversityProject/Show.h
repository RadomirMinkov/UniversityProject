#ifndef _SHOW_HPP
#define _SHOW_HPP

#include <cstring>
#include <iostream>
#include <fstream>

#include "Types.h"
#include "MyStr.h"
#include "Date.h"
#include "Hall.h"
#include "MyVector.h"
#include "Reservation.h"


enum Seats
{
	empty = 0,
	reserved = 1,
	bought = 2
};
class Show
{
private:
	 MyStr name;
	  Date date;

	  Hall* hall;
	  //вектор с резервациите 
	  MyVector<Reservation> reservations;
	  //масив за местата за дадено шоу
	  Seats** seats;
	void copy(Show const& other);
	void clear();
public:
	Show();
	Show(MyStr _name, Date _date,unsigned _capacity,Hall* hall=nullptr);
	Show(Show const& other);
	Show& operator=(Show const& other);
	~Show();

	MyStr getName() const { return name; }
	Date getDate() const { return  date; }
	const Hall* getHall() const { return hall; }
	Seats getSeat(unsigned rowNumber, unsigned seat) const;
	void setName(MyStr _name);
	void setDate(Date newDate);
	void printSeats(std::ostream& out,unsigned rows,unsigned seatsOnRow)const;
	void createSeats(unsigned rows,unsigned seatsOnRow);
	void updateSeats(unsigned rowNumber, unsigned seat,Seats seatType);
	void addReservation(Reservation const& reservation);
	bool cancelReservation(Reservation reservation);
	void buyTicket(unsigned rowNumber, unsigned seat);
	void printReservations(std::ostream& out) const ;
	Reservation getReservation(unsigned row, unsigned seat)const;
	bool operator==(Show const& other) const;
	//дава информация за мястото
	char place(Seats seat) const;
	//осигуряване на оператор за въвеждане
	friend std::istream& operator>>(std::istream& in, Show& other);
};


//осигуряване на операор за извеждане
std::ostream& operator<<(std::ostream&  out, Show const& other);//Not fully functioning

#endif // !_SHOW_HPP



