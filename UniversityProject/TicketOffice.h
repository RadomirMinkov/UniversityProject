#ifndef _TICKETOFFICE_HPP
#define _TICKETOFFICE_HPP

#include "TicketOffice.h"
#include "Hall.h"
#include "MyVector.h"
class TicketOffice
{
private:

	MyVector<Hall> halls;
public:

	TicketOffice(unsigned _capacity = 2);
	TicketOffice(TicketOffice const& other) = delete;
	TicketOffice& operator=(TicketOffice const& other) = delete;


	void addShow(Show const& show);
	void freeSeats(Show const& show)const;
	void reserveTicket(Show const& show);
	void cancelReservation(Show const& show);
	void buyTicket(Show const& show);
	void reservationList()const;
	void boughtTicketRefference()const;
};
#endif // !_TICKETOFFICE_HPP


