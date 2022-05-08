#ifndef _TICKETOFFICE_HPP
#define _TICKETOFFICE_HPP
#include "Hall.h"
#include "MyVector.h"
class TicketOffice
{
private:

	MyVector<Hall> halls;
public:

	TicketOffice(unsigned _capacity = 2);
	TicketOffice(TicketOffice const& other) = delete;
	TicketOffice();
	TicketOffice& operator=(TicketOffice const& other) = delete;


	void createShow();
	void buyTicket();
	void reserveTicket();
	void cancelReservation();
};
#endif // !_TICKETOFFICE_HPP


