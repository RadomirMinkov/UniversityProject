#ifndef _HALL__HPP
#define _HALL_HPP
#include <iostream>
#include <cassert>

#include "Show.h"
#include "Reservation.h"
class Hall
{
private:
	//свойства на класа

	//номер на залата
	unsigned hallNumber;
	//брой редове
	unsigned rows;
	//борй представления
	size_t showSize;
	//големина на списък от представления
	unsigned showCapacity;
	//места на ред
	unsigned seatsOnRow;
	//списък с представления в залата
	Show *shows;

	//изчистване на паметта
	void clear();
	//уголемяване на списъка от представления
	void resize(unsigned newCapacity);
	//функция за копиране на информацията от един клас в друг
	void copy(Hall const& other);
	//дава информация за мястото
	char place(Seats seat) const;
	//връща колко места има в залата
	int  getNumberOfSeats() const;
public:
	//Конструктор с параметри по подразбиране
	Hall(unsigned _hallNumber=0,unsigned _rows=0, unsigned _seatsOnRow=0, unsigned _showCapacity=2);
	//копи конструктор, който не кпира заетите места
	Hall(Hall const& other);
	//оператор за присвояване
	Hall& operator=(Hall const& other);
	//деструктор
	~Hall();

	//връщане на информация относно  залата
	unsigned getHallNumber() const { return hallNumber; }
	unsigned getRows() const { return rows; }
	unsigned getSeatsOnRows() const { return seatsOnRow; }
	unsigned getShowCapacity() const { return showCapacity; }
	unsigned getShowSize() const { return showSize; }

	//проверка дали залата е резервирана на дадена дата
	bool isReserved(Date _date);

	//добавяне на ново представление
	bool addNewShow(Show const& show);
	//купуване на места
	void buyTickets(unsigned _hallNumber, int* seats, unsigned numberOfSeats);

	//показва списък с местата в залата
	void showSeats(std::ostream& out,Show const& show) const;
	void seatsReference(Show const& show, std::ostream& out=std::cout) const;
	//резервиране на билети
	Reservation reserveTickets(unsigned _hallNumber, int* seats, unsigned numberOfSeats);
	//извеждане на информация за залата
	void print() const;
	//проверка дали има резервирани дати
	bool isEmpty();
};

#endif
