#include "Show.h"

void Show::clear()
{
	delete[] name;
}
Show::~Show()
{
	clear();
}

Show::Show(const char* _name, const char* _date)
	:name(nullptr)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);

}

void Show::copy(Show const& other)
{
	clear();
	name = new char[strlen(other.name)+1];
	strcpy(name, other.name);
	strcpy(date, other.date);
}

Show::Show(Show const& other)
{
	copy(other);
}

Show& Show::operator=(Show const& other)
{
	if (this!=&other)
	{
		copy(other);
	}
	return *this;
}
void Show::setDate(const char* _date)
{
	strcpy(date, _date);
}
void Show::setName(const char* _name)
{
	clear();
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

std::istream& operator>>(std::istream& in, Show& other)
{
	unsigned length;
	in >> length;
	other.name = new char[length + 1];
	in.get();
	in.getline(other.name,length);
	in.getline(other.date, DateLength);
	other.date[DateLength] = '\0';

	return in;
}

std::ostream& operator<<(std::ostream& out, Show const& other)
{
	return out << "Show:\n"
		<< "Name: " << other.getName() << '\n'
		<< "Date: " << other.getDate() << '\n';
}