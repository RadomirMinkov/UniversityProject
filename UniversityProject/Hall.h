#ifndef _HALL__HPP
#define _HALL_HPP
#include "Show.h"
class Hall
{
private:
	//свойства на класа

	//номер на залата
	unsigned hallNumber;
	//номер на реда
	unsigned rowNumber;
	//брой редове
	unsigned rows;
	//места на ред
	unsigned seatsOnRow;
	//масив със заети места в залата
	bool** seats;
	//списък с представления в залата
	Show *show;
	//изчистване на паметта
	void clear();
public:
	//Конструктор с параметри по подразбиране
	Hall(unsigned _hallNumber=0, unsigned _rowNumber=0, unsigned _rows=0, unsigned _seatsOnRow=0, bool** seats=nullptr, bool _isReserved=false);
	//копи конструктор, който не кпира заетите места
	Hall(Hall const& other);
	//оператор за присвояване
	Hall& operator=(Hall const& other);
	//деструктор
	~Hall();

	//връщане на информация относно  залата
	unsigned getHallNumber() const { return hallNumber; }
	unsigned getRowNumber() const { return rowNumber; }
	unsigned getRows() const { return rows; }
	unsigned getSeatsOnRows() const { return seatsOnRow; }

};

#endif
