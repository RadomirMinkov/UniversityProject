#ifndef _MYSTR_HPP
#define _MYSTR_HPP

#include <iostream>
#include <cstring>

class MyStr
{
private:
	char* arr;
	size_t size;

	void clear();
public:
	MyStr(const char* str="unknown");
	MyStr(MyStr const& other);
	~MyStr();
	MyStr& operator=(MyStr const& other);

	const char* getString() const { return arr; }
	size_t  getSize()const { return size; }

	void copy(MyStr const& other);
	void toLower();
	//bool cmp(MyStr const& other) const;
	bool operator==(MyStr const& other)const;
	bool operator!=(MyStr const& other) const;
	 friend std::istream& operator>>(std::istream& in,MyStr& other);
	 MyStr& operator+(MyStr const& other);
};

std::ostream& operator<<(std::ostream& out, MyStr const& other);
#endif // !_MYSTR_HPP


