#ifndef _DATE_HPP
#define  _DATE_HPP

#include <iostream>
#include <cassert>
enum Month
{
	january = 1,
	february = 2,
	mmarch = 3,
	april=4,
	may=5,
	june=6,
	july=7,
	augusts=8,
	september=9,
	october=10,
	november=11,
	december=12
};

class Date
{
private:
	unsigned day;
	Month month;
	unsigned year;
	bool isLeap(unsigned _year);
public:

	//����������� � ��������� �� ������������
	Date(unsigned _day = 0, Month _month = january, unsigned year = 2000);

	//������� �� ���������� �� ����������
	unsigned getDay() const { return day; }
	Month getMonth() const { return month; }
	unsigned getYear() const { return year; }

	//������� �� ����
	void setDay(unsigned _day);
	//������� �� ������
	void setMonth(Month _month);
	//������� �� ��������
	void setYear(unsigned _year);

};

std::istream& operator>>(std::istream& in, Date& _date);
std::ostream& operator<<(std::ostream& out, Date const& _date);
#endif // !_DATE_HPP


