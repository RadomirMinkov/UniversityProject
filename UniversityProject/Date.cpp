#include "Date.h"

Date::Date(unsigned _day, Month _month , unsigned _year )
{
	setDay(_day);
	setMonth(_month);
	setYear(_year);
}

bool Date::isLeap(unsigned _year)
{
	if (year%400==0)
	{
		return true;
	}
	else if(year%100==0)
	{
		return false;
	}
	else if (year % 4 == 0)
	{
		return true;
	}
	return false;
}
void Date::setDay(unsigned _day)
{
	if (isLeap(year) && month==february)
	{
		assert(_day >= 1 && _day <= 29);
	}
	switch (month)
	{
	case february:
		assert(_day >= 1 && _day <= 28);
		break;
	case january:
	case mmarch:
	case may:
	case july:
	case augusts:
	case october:
	case december:
		assert(_day >= 1  && day <= 31);
		break;
	case april:
	case june:
	september:
	november:
		assert(_day >= 1 && _day <= 30);
	default:
		break;
	}
	day = _day;
}

void Date::setMonth(Month _month)
{
	assert(month >= 1 && month <= 12);
	month = _month;
}

void  Date::setYear(unsigned _year)
{
	assert(_year >= 2000);
	year = _year;
}