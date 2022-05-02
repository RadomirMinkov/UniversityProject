#ifndef _SHOW_HPP
#define _SHOW_HPP
#include <cstring>
#include <iostream>

const int DateLength = 10;
class Show
{
private:
	 char* name;
	  char date[DateLength+1];
	void clear();
	void copy(Show const& other);
public:

	Show(const char* _name = "unknown", const char* _date = "unknown");
	Show(Show const& other);
	~Show();
	Show& operator=(Show const& other);

	const char* getName() const { return name; }
	const char* getDate() const { return date; }
	void setName(const char* _name);
	void setDate(const char* _date);

	//осигуряване на оператор за въвеждане
	friend std::istream& operator>>(std::istream& in, Show& other);
};


//осигуряване на операор за извеждане
std::ostream& operator<<(std::ostream&  out, Show& other);

#endif // !_SHOW_HPP



