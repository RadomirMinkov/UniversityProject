#ifndef _RESERVATION_HPP
#define _RESERVATION_HPP
#include <cstring>
#include <iostream>

#include "MyStr.h"
/**
 * @brief class reservation which contains password, row, seat and note
 * 
 */
class Reservation
{
	///private properties
private:
///password
	MyStr password;
	///note
	MyStr note;
	///row
	unsigned rowNumber;
	///seat
	unsigned seat;
	/**
	 * @brief function that copies one object to other
	 * 
	 * @param other the object that the infromation will be copied from
	 */
	void copy(Reservation const& other);
	//void resize(unsigned newCap);
public:
/**
 * @brief deffault constructor
 * 
 */
	Reservation()=default;
	/**
	 * @brief constructor with parameters
	 * 
	 * @param rowNumber row of the reservation
	 * @param seat seat of the reservation
	 * @param _password password of the reservation
	 * @param _note note of the reservation
	 */
	Reservation(unsigned rowNumber,unsigned seat, MyStr _password , MyStr _note);
	/**
	 * @brief copy constructor
	 * 
	 * @param other the object the information will be copied from
	 */
	Reservation(Reservation const& other);
	/**
	 * @brief operator = tha provides the possibility to  appropriate one reservation to another
	 * 
	 * @param other the reservation that the information will be copied from
	 * @return Reservation& refference to the this
	 */
	Reservation& operator=(Reservation const& other);
	/// get the password of the reservation
	MyStr getPassword() const { return password; }
	/// get the note of the reservation
	MyStr getNote() const { return note; }
	///get the row of the reservation
	unsigned getRowNumber() const { return rowNumber; }
	///get the seat of the reservation
	unsigned getSeat() const { return seat; }
	/**
	 * @brief function that add to the end of the note
	 * 
	 * @param text the text that will be added to the end the note
	 */
	void addToNote(MyStr text);
	/**
	 * @brief function that replaces the note
	 * 
	 * @param newNote the new note that will be placed
	 */
	void replaceNote(MyStr newNote);

	/**
	 * @brief operator that checks if two reservation are equal
	 * 
	 * @param other the second reservation
	 * @return true they are equal
	 * @return false they are not equal
	 */
	bool operator==(Reservation const& other) const;
	/**
	 * @brief operator for input
	 * 
	 * @param in the stream that the input will be taken from
	 * @param reservation the reservation that will store the information
	 * @return std::istream& refference to the stream
	 */
	friend std::istream& operator>>(std::istream& in, Reservation& reservation);
};
/**
 * @brief the operator for output
 * 
 * @param out the stream that will be printed to
 * @param reservation the reservation that the information will be taken from
 * @return std::ostream& refference to the stream
 */
std::ostream& operator<<(std::ostream& out, Reservation const& reservation);
#endif // !_RESERVATION__HPP

