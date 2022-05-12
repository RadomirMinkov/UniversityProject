#ifndef _HALL_HPP
#define _HALL_HPP
#include <iostream>
#include <cassert>
#include <fstream>

#include "Types.h"
#include "MyVector.h"
#include "Show.h"
#include "Reservation.h"
#include "MyStr.h"

const int MAX_ANSWER_BUFFER = 3;
class Hall
{
private:
	//свойства на класа

	//номер на залата
	unsigned hallNumber;
	//брой редове
	unsigned rows;
	//места на ред
	unsigned seatsOnRow;
	//списък с представления в залата
	MyVector<Show> shows;

	//функция за копиране на информацията от един клас в друг
	void copy(Hall const& other);
	Reservation enterReservatoin() const;
	//връща колко места има в залата
	int  getNumberOfSeats() const;
public:
	//Конструктор с параметри по подразбиране
	Hall(unsigned _hallNumber=0,unsigned _rows=0, unsigned _seatsOnRow=0);
	//копи конструктор, който не кпира заетите места
	Hall(Hall const& other);
	//оператор за присвояване
	Hall& operator=(Hall const& other);

	//връщане на информация относно  залата
	unsigned getHallNumber() const { return hallNumber; }
	unsigned getRows() const { return rows; }
	unsigned getSeatsOnRows() const { return seatsOnRow; }
	MyVector<Show> getShows() const { return shows; }
	//проверка дали залата е резервирана на дадена дата
	bool isReserved(Date _date);

	//добавяне на ново представление
	bool addNewShow(Show const& show);
	//купуване на места
	bool buyTicket(Show show,unsigned _rowNumber,unsigned _seat);

	//void sortShowsByDate();
	//показва списък с местата в залата
	void showSeats(std::ostream& out,Show const& show) const;
	void seatsReference(Show const& show, std::ostream& out=std::cout) const;
	//резервиране на билети
	bool reserveTicket(Show show);
	//извеждане на информация за залата
	void printBoughtSeats(std::ofstream& out,Date beginingDate, Date endingDate) const;
	void printReservedSeats(std::ofstream& out,Date date,MyStr name)const;
	void printEmptySeats(std::ostream& out, Show show)const;
	void print(std::ostream& out)const;
	bool cancelShowReservation(std::istream& in,Show const& show);
	bool operator==(Hall const& other)const;
	//проверка дали има резервирани дати
	bool isEmpty();
	friend std::istream& operator>>(std::istream& in, Hall& hall);
};

std::ostream& operator<<(std::ostream& out, Hall const& hall);

#endif
