#ifndef _DATE_HPP
#define  _DATE_HPP

#include <iostream>
#include <cassert>
/**
 * @brief enum that includes the months in a yea 
 * 
 */
enum  Month
{
	january = 1,
	february = 2,
	march = 3,
	april=4,
	may=5,
	june=6,
	july=7,
	august=8,
	september=9,
	october=10,
	november=11,
	december=12
};
/**
 * @brief class date which makes the work with dates easier
 * 
 */
class Date
{
	/**
	 * @brief private properties of the class
	 * 
	 */
private:
    /// day
	unsigned day;
	///month
	Month month;
	///year
	unsigned year;
	/**
	 * @brief checks if the year is leap
	 * 
	 * @param _year the year we are checking
	 * @return true it is leap
	 * @return false it is not leap
	 */
	bool isLeap(unsigned _year);
public:

	/**
	 * @brief constructor with default parameters
	 * 
	 * @param _day day
	 * @param _month momth
	 * @param year year
	 */
	Date(unsigned _day = 1, Month _month = january, unsigned year = 2000);

	/**
	 * @brief get the day of the year
	 * 
	 * @return reutrn the day 
	 */
	unsigned getDay() const { return day; }
	///get the month of the year
	Month getMonth() const { return month; }
	//get the year
	unsigned getYear() const { return year; }
	/**
	 * @brief prints month with string
	 * 
	 * @param month the month that is printed
	 * @return const char*  the type that is returned
	 */
	const char* printMonth(Month month) const;
	/**
	 * @brief changing the day
	 * 
	 * @param _day new day
	 */
	void setDay(unsigned _day);
	/**
	 * @brief changing the month
	 * 
	 * @param _month new month
	 */
	void setMonth(unsigned _month);
	/**
	 * @brief changing the year
	 * 
	 * @param _year new year
	 */
	void setYear(unsigned _year);

/**
 * @brief checks if two dates are equal
 * 
 * @param other the second date
 * @return true they are equal
 * @return false they are not equal
 */
	bool operator==(Date const& other) const;
	/**
	 * @brief check if two date are different
	 * 
	 * @param other the second date
	 * @return true they are different
	 * @return false they are the same
	 */
	bool operator!=(Date const& other) const;
	/**
	 * @brief comparing two dates
	 * 
	 * @param other the second date
	 * @return true second is bigger
	 * @return false first is bigger
	 */
	bool operator<=(Date const& other) const;
	/**
	 * @brief comparing two dates
	 * 
	 * @param other the second date
	 * @return true first is bigger
	 * @return false second is bigger
	 */
	bool operator<(Date const& other) const;
	/**
	 * @brief comparing two dates
	 * 
	 * @param other the second date
	 * @return true first is smaller
	 * @return false second is smaller
	 */
	bool operator>=(Date const& other) const;
	/**
	 * @brief comparing two dates
	 * 
	 * @param other the second date
	 * @return true second is smaller
	 * @return false first is bigger
	 */
	bool operator>(Date const& other) const;
};

/**
 * @brief operator for input
 * 
 * @param in the stream that we input from
 * @param _date the object we put the information in
 * @return std::istream& refference to the stream
 */
std::istream& operator>>(std::istream& in, Date& _date);
/**
 * @brief operator for output 
 * 
 * @param out the stream we output to
 * @param _date the object we take the information from
 * @return std::ostream& refference to the stream
 */
std::ostream& operator<<(std::ostream& out, Date const& _date);
#endif // !_DATE_HPP


