#include "Date.h"

Date::Date(unsigned _day, Month _month, unsigned _year)
{
	setYear(_year);
	setMonth(_month);
	setDay(_day);
}

bool Date::isLeap(unsigned _year)
{
	if (year % 400 == 0)
	{
		return true;
	}
	else if (year % 100 == 0)
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
	if (isLeap(year) && month == february)
	{
		assert(_day >= 1 && _day <= 29);
	}
	switch (month)
	{
	case february:
		assert(_day >= 1 && _day <= 28);
		break;
	case january:
	case march:
	case may:
	case july:
	case august:
	case october:
	case december:
		assert(_day >= 1 && _day <= 31);
		break;
	case april:
	case june:
	case september:
	case november:
		assert(_day >= 1 && _day <= 30);
	default:
		break;
	}
	day = _day;
}

void Date::setMonth(unsigned _month)
{
	assert(_month >= 1 && _month <= 12);
	switch (_month)
	{
	case 1:
		month = january;
		break;
	case 2:
		month = february;
		break;
	case 3:
		month = march;
		break;
	case 4:
		month = april;
		break;
	case 5:
		month = may;
		break;
	case 6:
		month = june;
		break;
	case 7:
		month = july;
		break;
	case 8:
		month = august;
		break;
	case 9:
		month = september;
		break;
	case 10:
		month = october;
		break;
	case 11:
		month = november;
		break;
	case 12:
		month = december;
		break;
	}
}

void  Date::setYear(unsigned _year)
{
	assert(_year >= 2000 && _year <= 2100);
	year = _year;
}

const char* Date::printMonth(Month _month) const
{
	switch (_month)
	{
	case january:
		return "january";	break;
	case february:
		return "february";	break;
	case march:
		return "march"; 	break;
	case april:
		return "april"; 	break;
	case may:
		return "may";	    break;
	case june:
		return "june";  	break;
	case july:
		return "july";	    break;
	case august:
		return "august";    break;
	case september:
		return "september";	break;
	case october:
		return "octomber";  break;
	case november:
		return "november";  break;
	case december:
		return "december";	break;
	default:
		return "error"; break;
	}
}
bool Date::operator==(Date const& other) const
{
	return day == other.day && month == other.month && year == other.year;
}
std::istream& operator>>(std::istream& in, Date& date)
{
	unsigned day;
	unsigned month;
	unsigned year;
	if (&in == &std::cin)
		std::cout << "Enter day: ";
	in >> day;
	if (&in == &std::cin)
		std::cout << "Enter month with digits: ";
	in >> month;
	if (&in == &std::cin)
		std::cout << "Enter year: ";
	in >> year;;
	date.setYear(year);
	date.setMonth(month);
	date.setDay(day);
	return in;
}
bool Date::operator!=(Date const& other) const
{
	return !(*this == other);
}
bool Date::operator>(Date const& other) const
{
	return !(*this <= other);
}

bool Date::operator<=(Date const& other) const
{
	if (year == other.year && month == other.month && day == other.day)
	{
		return true;
	}
	if (year < other.year)
	{
		return true;
	}
	else if (year > other.year)
	{
		return false;
	}
	else
	{
		if (month < other.month)
		{
			return true;
		}
		else if (month > other.month)
		{
			return false;
		}
		else
		{
			if (day <= other.day)
			{
				return true;
			}
			return false;
		}
	}
}
bool Date::operator<(Date const& other) const
{
	return !(*this >= other);
}
bool Date::operator>=(Date const& other) const
{
	if (year==other.year && month== other.month && day==other.day)
	{
		return true;
	}
	if (year>other.year)
	{
		return true;
	}
	else if (year<other.year)
	{
		return false;
	}
	else
	{
		if (month>other.month)
		{
			return true;
		}
		else if (month<other.month)
		{
			return false;
		}
		else
		{
			if (day>=other.day)
			{
				return true;
			}
			return false;
		}
	}
}
std::ostream& operator<<(std::ostream& out, Date const& date)
{
	out << date.getDay() << '/' << date.getMonth() << '/' << date.getYear() << '\n';
		return out;
}
