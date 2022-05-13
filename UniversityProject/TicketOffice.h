#ifndef _TICKETOFFICE_HPP
#define _TICKETOFFICE_HPP

#include "TicketOffice.h"
#include "Hall.h"
#include "MyVector.h"
/**
 * @brief class ticket office that has list of halls and uses all the funtions that the user needs
 * 
 */
class TicketOffice
{
	///private properties
private:
///list of halls
	MyVector<Hall> halls;
public:
/**
 * @brief constructor with deffault parameters
 * 
 * @param _capacity the capacity that the list will have
 */
	TicketOffice(unsigned _capacity = 2);
	/**
	 * @brief deleted copy contructor
	 * 
	 * @param other that object that will be copied
	 */
	TicketOffice(TicketOffice const& other) = delete;
	/**
	 * @brief deleted operator = 
	 * 
	 * @param other the object that will be copied
	 * @return TicketOffice& refference to this
	 */
	TicketOffice& operator=(TicketOffice const& other) = delete;

///get the list of halls
	MyVector<Hall> getHalls() const { return halls; }
	/**
	 * @brief function that add halls to the list 
	 * 
	 * @param hall the hall that will be added
	 */
	void addHall(Hall const& hall);
	/**
	 * @brief function that add new show to a hall
	 * 
	 * @param show the show that will be added
	 */
	void addShow(Show const& show);
	/**
	 * @brief function that prints the seats of a show
	 * 
	 * @param show the show which seats will be printed
	 */
	void freeSeats(Show const& show)const;
	/**
	 * @brief function that reserves a ticket in a show
	 * 
	 * @param show the show in which the reservation will be made
	 */
	void reserveTicket(Show const& show);
	/**
	 * @brief function that cancel reservation in a show
	 * 
	 * @param show the show in which the cancelation wiill be made
	 */
	void cancelReservation(Show const& show);
	/**
	 * @brief function that buys a ticket in a show
	 * 
	 * @param show the show in which the ticket will be bought
	 */
	void buyTicket(Show const& show);
	/**
	 * @brief fucntion that print the reservations
	 * 
	 */
	void reservationList()const;
	/**
	 * @brief function that print the bought tickets
	 * 
	 */
	void boughtTicketRefference()const;
	/**
	 * @brief function that writes to text file
	 * 
	 * @param out 
	 */
	void writeToText(std::ofstream& out)const;
	/**
	 * @brief function that reads from a text file
	 * 
	 * @param in 
	 */
	void readFromText(std::ifstream& in);
};
#endif // !_TICKETOFFICE_HPP


