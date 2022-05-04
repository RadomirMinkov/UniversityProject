#ifndef _SHOW_HPP
#define _SHOW_HPP
#include <cstring>
#include <iostream>

const int DateLength = 11;
class Show
{
private:
	 char* name;
	  char date[DateLength];
	  unsigned hallNumber;
	void clear();
	void copy(Show const& other);
public:
	Show(unsigned _hallNumber=0, const char* _name = "unknown", const char* _date = "unknown");
	Show(Show const& other);
	~Show();
	Show& operator=(Show const& other);

	const char* getName() const { return name; }
	const char* getDate() const { return date; }
	unsigned getHallNumber() const { return hallNumber; }
	void setHallNumber(unsigned _hallNumber);
	void setName(const char* _name);
	void setDate(const char* _date);


	//осигуряване на оператор за въвеждане
	friend std::istream& operator>>(std::istream& in, Show& other);
};


//осигуряване на операор за извеждане
std::ostream& operator<<(std::ostream&  out, Show const& other);

#endif // !_SHOW_HPP



