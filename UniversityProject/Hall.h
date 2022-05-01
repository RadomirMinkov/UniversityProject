#ifndef _HALL__HPP
#define _HALL_HPP
#include "Show.h"

class Hall
{
private:
	unsigned hallNumber;
	unsigned rowNumber;
	unsigned rows;
	unsigned seatsOnRow;
	bool* seat;
	Show show;
public:
	//Конструктор с параметри по подразбиране
	Hall(unsigned _hallNumber=0, unsigned _rowNumber=0, unsigned _rows=0, unsigned _seatsOnRow=0, bool *seat=nullptr,Show _show=nullptr);
	//копи конструктор, който не кпира заетите места
	Hall(Hall const& other);
	//деструктор
	~Hall();

	//връщане на информация относно  залата
	unsigned getHallNumber() const { return hallNumber; }
	unsigned getRowNumber() const { return rowNumber; }
	unsigned getRows() const { return rows; }
	unsigned getSeatsOnRows() const { return seatsOnRow; }
	const char* getShowName() const { return show.getName(); }
	const char* getShowDate() const { return show.getDate(); }

};

#endif
