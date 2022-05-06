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
	Date(unsigned _day = 1, Month _month = january, unsigned year = 2000);

	//������� �� ���������� �� ����������
	unsigned getDay() const { return day; }
	Month getMonth() const { return month; }
	unsigned getYear() const { return year; }
	const char* printMonth(Month month) const;
	//������� �� ����
	void setDay(unsigned _day);
	//������� �� ������
	void setMonth(unsigned _month);
	//������� �� ��������
	void setYear(unsigned _year);

	bool operator==(Date const& other) const;
};

std::istream& operator>>(std::istream& in, Date& _date);
std::ostream& operator<<(std::ostream& out, Date const& _date);
#endif // !_DATE_HPP


