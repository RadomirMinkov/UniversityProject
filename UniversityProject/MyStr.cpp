#include "MyStr.h"

void MyStr::clear()
{
	//arr = nullptr;
	delete[] arr;
}

MyStr::~MyStr()
{
	clear();
}

MyStr::MyStr(const char* _arr)
	:size(strlen(_arr)), arr(nullptr)
{
	arr = new char[size + 1];
	strcpy(arr, _arr);
}
void MyStr::copy(MyStr const& other)
{
	if (other.arr == nullptr)
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
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

bool MyStr::operator!=(MyStr const& other)const
{
	return !(*this == other);
}
void MyStr::toLower()
{
	for (unsigned i = 0; i < size; i++)
		if (arr[i] >= 'A' && arr[i] <= 'Z')
			arr[i] = arr[i] + 32;
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

unsigned MyStr::charachterToDigit(char charachter) const
{
	return charachter - '0';
}
Date MyStr::toDate()
{
	if (size != 3)
	{
		Date newDate;
		unsigned number{ 0 };
		unsigned index{ 0 };
		unsigned count{ 0 };
		for (unsigned i = 0; i < size; i++)
		{
			if (arr[i] == '/')
			{
				count++;
				if (count == 1)
				{
					for (unsigned j = 0; j < i; j++)
					{
						number = 10 * number + (arr[j] - '0');
					}
					newDate.setDay(number);
				}
				else if (count == 2)
				{
					for (unsigned j = index; j < i; j++)
					{
						number = 10 * number + (arr[j] - '0');
					}
					newDate.setMonth(number);
					number = 0;
					for (unsigned j = i + 1; j < size; j++)
					{
						number = 10 * number + (arr[j] - '0');
					}
					newDate.setYear(number);
					return newDate;
				}
				index = i + 1;
			}
			number = 0;
		}
	}
}
bool MyStr::operator==(MyStr const& other)const
{
	return  strcmp(arr, other.arr) == 0;
}
std::ostream& operator<<(std::ostream& out, MyStr const& other)
{
	return out << other.getString();
}

std::istream& operator>>(std::istream& in, MyStr& other)
{
	other.clear();
	if (&in == &std::cin)
		std::cout << "Enter the length of the string: ";
	in >> other.size;
	in.get();
	other.arr = new char[other.size + 1];
	if (&in == &std::cin)
		std::cout << "Enter the  string: ";
	in.getline(other.arr, other.size + 1);
	return in;
}