#include "MyStr.h"

void MyStr::clear()
{
	delete[] arr;
}

MyStr::~MyStr()
{
	clear();
}

MyStr::MyStr(const char* _arr)
	:size(strlen(_arr)),arr(nullptr)
{
	arr = new char[size + 1];
	strcpy(arr, _arr);
}
void MyStr::copy(MyStr const& other)
{
	if (other.arr==nullptr)
	{
		std::cout << "Couldn't copy the string!";
		return;
	}
	size = other.size;
	clear();
	arr = new char[size + 1];
	strcpy(arr, other.arr);
}
MyStr::MyStr(MyStr const& other)
:arr(nullptr)
{
	copy(other);
}

MyStr& MyStr::operator=(MyStr const& other)
{
	if (this!=&other)
	{
		copy(other);
	}
	return *this;
}

MyStr& MyStr::operator+(MyStr const& other)
{
   char* temp = new char[size + other.size + 1];
	strcpy(temp, arr);
	strcat(temp, other.arr);
	delete[] arr;
	arr = new char[strlen(temp) + 1];
	strcpy(arr, temp);
	size = strlen(temp);
	return *this;
}

bool MyStr::cmp(MyStr const& other)const
{
	if (strcmp(arr, other.arr) == 0)
		return true;
	return false;
}
std::ostream& operator<<(std::ostream& out, MyStr const& other)
{
	return out << other.getString();
}

std::istream& operator>>(std::istream& in, MyStr& other)
{
	other.clear();
	in >> other.size;
	other.arr = new char[other.size + 1];
	in.getline(other.arr, other.size + 1);
	return in;
}