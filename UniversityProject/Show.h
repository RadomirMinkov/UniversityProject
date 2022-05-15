#ifndef _SHOW_HPP
#define _SHOW_HPP

#include <cstring>
#include <iostream>
#include <fstream>

#include "Types.h"
#include "MyStr.h"
#include "Date.h"
#include "Hall.h"
#include "MyVector.h"
#include "Reservation.h"

/**
 * @brief enum that provides the different types of seats
 * 
 */
enum Seats
{
	empty = 0,
	reserved = 1,
	bought = 2
};
/**
 * @brief class show which contains information about the date it will be presented,the hall in which it will be, name, list of reservation
 *scheme of the seats in the hall
 * 
 */
class Show
{
	///private properties
private:
///name
	 MyStr name;
	 ///date
	  Date date;
	  ///pointer to hall
	  Hall* hall;
	  ///list of reservations
	  MyVector<Reservation> reservations;
	  ///matrix with the seats
	  Seats** seats;
	  ///sold tickets
	  unsigned soldTickets{ 0 };
	  ///bought tickets
	  unsigned reservedTickets{ 0 };
	  /**
	   * @brief function that copies one object to another
	   * 
	   * @param other the object that will be copied
	   */
	void copy(Show const& other);
	/**
	 * @brief get the seat type in string
	 * 
	 * @param seat seat
	 * @return const char* the type of the returned string
	 */
	const char* getSeatStringType(Seats seat)const;
	/**
	 * @brief funstion that deletes the memory
	 * 
	 */
	void clear();
public:
///default constructor
	Show();
	/**
	 * @brief constructor with parameters
	 * 
	 * @param _name name of the show
	 * @param _date date of the show
	 * @param _capacity capacity of the reservations
	 * @param hall the hall in which the show will be played
	 */
	Show(MyStr _name, Date _date,unsigned _capacity,Hall* hall=nullptr);
	///copy constructor
	Show(Show const& other);
	/**
	 * @brief operator = that provide posibility to apropriate one show to another
	 * 
	 * @param other the show that will be copied
	 * @return Show& refference to this
	 */
	Show& operator=(Show const& other);
	/**
	 * @brief function that destroys the object
	 * 
	 */
	~Show();
	/// get the name of the show
	MyStr getName() const { return name; }
	/// get the date of the show
	Date getDate() const { return  date; }
	///get pointer to the hall of the show
	 Hall* getHall() const { return hall; }
	 ///get seat 
	Seats getSeat(unsigned rowNumber, unsigned seat) const;
	///get sold tickets
	unsigned getSoldTickets() const { return soldTickets; }
	///get reserved tickets
	unsigned getReservedTickets() const { return reservedTickets; }
	///get the attendance in a show
	double getAttendance() const;
	/**
	 * @brief function that changes the name of the show
	 * 
	 * @param _name the new name
	 */
	void setName(MyStr _name);
	/**
	 * @brief function that changes the date of the show
	 * 
	 * @param newDate the new date
	 */
	void setDate(Date newDate);

	/**
	 * @brief fucntion that prints the seats
	 * 
	 * @param out the stream that shows where the information will be printed
	 * @param rows number of wars
	 * @param seatsOnRow numbers of seats on each row
	 */
	void printSeats(std::ostream& out,unsigned rows,unsigned seatsOnRow)const;
	/**
	 * @brief creating the seats matrix
	 * 
	 * @param rows number of rows
	 * @param seatsOnRow numbers of seats on each row
	 */
	void createSeats(unsigned rows,unsigned seatsOnRow);
	/**
	 * @brief fucntion that changes the type of a seat
	 * 
	 * @param rowNumber row number
	 * @param seat seat
	 * @param seatType seat type
	 */
	void updateSeats(unsigned rowNumber, unsigned seat,Seats seatType);
	/**
	 * @brief function that adds reservation to a show
	 * 
	 * @param reservation the reservation that will be added
	 */
	void addReservation(Reservation const& reservation);
	/**
	 * @brief function that cancels reservation in a show
	 * 
	 * @param reservation the reservation that will be canceled
	 * @return true successfull cancelation
	 * @return false couldn't cancel the reservation
	 */
	bool cancelReservation(Reservation reservation);
	/**
	 * @brief function that buys a ticket
	 * 
	 * @param rowNumber row number
	 * @param seat seat
	 */
	void buyTicket(unsigned rowNumber, unsigned seat);
	/**
	 * @brief function that prints all the reservations 
	 * 
	 * @param out the sream that shows where the reservation will be printed
	 */
	void printReservations(std::ostream& out) const ;
	/**
	 * @brief functions that prints the only the seats which are the same as the seat type that is provided
	 * 
	 * @param out the stream that shows where the seats wiil be printed
	 * @param seat seat type
	 */
	void printSeatsType(std::ostream& out,Seats seat)const;
	//void printReservedSeats(std::ofstream& out)const;
	/**
	 * @brief get reservatoin
	 * 
	 * @param row row
	 * @param seat seat
	 * @return Reservation returns the reservation
	 */
	Reservation getReservation(unsigned row, unsigned seat)const;
	/**
	 * @brief operator that checks if two shows are equal
	 * 
	 * @param other the second show
	 * @return true they are equal
	 * @return false they are different
	 */
	bool operator==(Show const& other) const;
	/**
	 * @brief function that returns charachter to provided seat
	 * 
	 * @param seat seat
	 * @return char the charachter that will be returned
	 */
	char place(Seats seat) const;
	/**
	 * @brief opetator for input
	 * 
	 * @param in the stream that shows from where the information will be taken from
	 * @param other the object that will store the information
	 * @return std::istream& refference to the stream
	 */
	friend std::istream& operator>>(std::istream& in, Show& other);
};


/**
 * @brief operator for output
 * 
 * @param out the stream that shows where the information will be printed to
 * @param other the object that will provide the information
 * @return std::ostream& refference to the stream
 */
std::ostream& operator<<(std::ostream&  out, Show const& other);
#endif // !_SHOW_HPP



