#ifndef _HALL_HPP
#define _HALL_HPP
#include <iostream>
#include <cassert>
#include <fstream>

#include "Types.h"
#include "MyVector.h"
#include "Show.h"
#include "Reservation.h"
#include "MyStr.h"

/**
 * @brief That is class Hall which has number, rows, seats on rows and list of shows, controling functions that modify the list and the shows that are in it
 * 
 */
class Hall
{
	/// this are the private properties of the class
private:

	/// the number of the hall
	unsigned hallNumber;
	/// numbers of the rows
	unsigned rows;
	/// numbers of the seats on each row
	unsigned seatsOnRow;
	/// list of shows 
	MyVector<Show> shows;

	///this is private function that copies the information from one hall to another
	void copy(Hall const& other);

	///fucntion that creates reservation,  saves code 
	Reservation enterReservatoin() const;
	///function that returns the number of seats in the hall
	int  getNumberOfSeats() const;
public:
	/**
	 * @brief Constructor with default parameters
	 * 
	 * @param _hallNumber   number of the room
	 * @param _rows  rows in the room
	 * @param _seatsOnRow seats on each row
	 */
	Hall(unsigned _hallNumber=0,unsigned _rows=0, unsigned _seatsOnRow=0);
	/**
	 * @brief copy constructor
	 * 
	 * @param other  this is the hall that we will create the object from
	 */
	Hall(Hall const& other);
	/**
	 * @brief operator = which provide us the posibility to appropriate one hall to other
	 * 
	 * @param other  this is the hall that we will appropriate from
	 * @return Hall& return refference to the object
	 */
	Hall& operator=(Hall const& other);


	 /// returns the number of the hall 
	unsigned getHallNumber() const { return hallNumber; }
	/// returns the number of the rows
	unsigned getRows() const { return rows; }
	/// returns the seats on each row
	unsigned getSeatsOnRows() const { return seatsOnRow; }
	/// returns the list of shows
	MyVector<Show> getShows() const { return shows; }
	/**
	 * @brief checks if there is show on this date
	 * 
	 * @param _date the date we search for
	 * @return true there is show on this date
	 * @return false there isn't show on this date
	 */
	bool isReserved(Date _date);

	/**
	 * @brief adds new show to the list
	 * 
	 * @param show the show that we add
	 * @return true  we added show succesful
	 * @return false we couldn't add this show
	 */
	bool addNewShow(Show const& show);
	/**
	 * @brief buying ticket for show
	 * 
	 * @param show the show the ticket is bought
	 * @return true bought seat succesfully
	 * @return false couldn't buy seat
	 */
	bool buyTicket(Show const& show);

	
	/**
	 * @brief function that prints seats
	 * 
	 * @param out  the stream where the result will be printed
	 * @param show the show which seats are printed
	 */
	void showSeats(std::ostream& out,Show const& show) const;

/**
 * @brief shows how many empty,reserved and bought seats there are
 * 
 * @param show the show the refference is made for
 * @param out  the stream where the result will be printed
 */
	void seatsReference(Show const& show, std::ostream& out=std::cout) const;
	/**
	 * @brief fucniton that reserves ticket
	 * 
	 * @param show the show the ticket will be reserved from
	 * @return true succesfull reservation
	 * @return false unsuccessful reservation
	 */
	bool reserveTicket(Show const& show);
	/**
	 * @brief prints the seats that are bought
	 * 
	 * @param out the stream where the result will be printed
	 * @param beginingDate the date from which the refference is made
	 * @param endingDate the date to which the refference is made
	 */
	void printBoughtSeats(std::ofstream& out,Date const& beginingDate, Date const& endingDate) const;
	/**
	 * @brief  prints the seats that are reserved
	 * 
	 * @param out the stream where the result will be printed
	 * @param date the date which shows which shows we should print
	 * @param name the name of the shows that should be printed
	 */
	void printReservedSeats(std::ofstream& out,Date const& date,MyStr const& name)const;
	/**
	 * @brief prints the seats that are empty
	 * 
	 * @param out the stream where the result will be printed
	 * @param show the show which seats are printed
	 */
	void printEmptySeats(std::ostream& out, Show const& show)const;
	/**
	 * @brief prints the hall
	 * 
	 * @param out the stream where the result will be printed
	 */
	void print(std::ostream& out)const;
	/**
	 * @brief cancel the reservation in a show
	 * 
	 * @param in the stream that provides the information 
	 * @param show the shows in which the operation will be made
	 * @return true the reservation was canceled
	 * @return false couldn't cancel the reservation
	 */
	bool cancelShowReservation(std::istream& in,Show const& show);
	/**
	 * @brief operator that checks if two halls are equal 
	 * 
	 * @param other the second hall
	 * @return true they are equal
	 * @return false they are not equal
	 */
	bool operator==(Hall const& other)const;
	/**
	 * @brief checks if the list is empty
	 * 
	 * @return true it is empty
	 * @return false it is not empty
	 */
	bool isEmpty();
	/**
	 * @brief operator for input from stream
	 * 
	 * @param in stream that provide the information
	 * @param hall the hall in which the information will be stored
	 * @return std::istream& refference to the stream
	 */
	friend std::istream& operator>>(std::istream& in, Hall& hall);
/**
 * @brief read information form text file
 * 
 * @param in the stream that provides information
 */
	void readFromText(std::ifstream& in);
};
/**
 * @brief operator for output
 * 
 * @param out the stream where the result will be printed
 * @param hall that hall which information will be printed
 * @return std::ostream&  refference to the stream
 */
std::ostream& operator<<(std::ostream& out, Hall const& hall);

#endif
