#ifndef _MYSTR_HPP
#define _MYSTR_HPP

#include <iostream>
#include <cstring>

#include "Types.h"
#include "Date.h"
/**
 * @brief creating strng class that provides the needed function and handles the dynamic memory
 * 
 */
class MyStr
{
	///private properties
private:
    ///char* wchich will be modified
	char* arr;
	///the size of the array
	size_t size;
	///function that deletes the memory
	void clear();
	/**
	 * @brief transforming charachter to digit
	 * 
	 * @param charachter the charachter that will be transformed
	 * @return unsigned the type of the digit
	 */
	unsigned charachterToDigit(char charachter) const;
public:
/**
 * @brief constructor with deffault parameters  
*
 * @param str the string 
 */
	MyStr(const char* str="unknown");
	/**
	 * @brief Copy constructor
	 * 
	 * @param other the object we are copying from
	 */
	MyStr(MyStr const& other);
	/**
	 * @brief Destroy the object
	 * 
	 */
	~MyStr();
	/**
	 * @brief operator = which provides the possibility to appropriate one string to another
	 * 
	 * @param other the object we will appropriate from
	 * @return MyStr& refference to the object
	 */
	MyStr& operator=(MyStr const& other);
	/// get the string
	const char* getString() const { return arr; }
	/// get the size og the string
	size_t  getSize()const { return size; }
	/**
	 * @brief function that copies the information from one string to other
	 * 
	 * @param other the object we copy from
	 */
	void copy(MyStr const& other);
	///function that makes the big charachters to low
	void toLower();
	/**
	 * @brief transforming the array to date
	 * 
	 * @return Date&  the date that was created
	 */
	Date toDate() ;
	//bool cmp(MyStr const& other) const;
	/**
	 * @brief operator that checks if two strings are equal
	 * 
	 * @param other the second string
	 * @return true they are equal
	 * @return false they are not equal
	 */
	bool operator==(MyStr const& other)const;
	/**
	 * @brief operator that checks if two string are different
	 * 
	 * @param other the second string
	 * @return true they are different
	 * @return false they are the same
	 */
	bool operator!=(MyStr const& other) const;
	/**
	 * @brief operator for input
	 * 
	 * @param in the stream that will be inputed from
	 * @param other the object in which the information will be stored
	 * @return std::istream& refferenceto the stream
	 */
	 friend std::istream& operator>>(std::istream& in,MyStr& other);
	 /**
	  * @brief operator for concatinating two strings
	  * 
	  * @param other the second string
	  * @return MyStr& refference to the new string
	  */
	 MyStr& operator+(MyStr const& other);
};
/**
 * @brief operator for output
 * 
 * @param out the stream that will be printed to
 * @param other the object from which the information will be taken from
 * @return std::ostream& refference to the stream
 */
std::ostream& operator<<(std::ostream& out, MyStr const& other);
#endif // !_MYSTR_HPP


