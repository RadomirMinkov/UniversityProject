#ifndef _SHOW_HPP
#define _SHOW_HPP
class Show
{
private:
	const char* name;
	const char* date;
public:

	Show(const char* _name = "uknwon", const char* _date = "unknown");
	Show(Show const& other);
	~Show();

	const char* getName() const { return name; }
	const char* getDate() const { return date; }
};

#endif // !_SHOW_HPP



