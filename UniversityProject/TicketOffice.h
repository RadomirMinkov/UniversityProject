#ifndef _TICKETOFFICE_HPP
#define _TICKETOFFICE_HPP
#include "Hall.h"
class TicketOffice
{
private:

	Hall* halls;
	unsigned capacity;
	unsigned size;
public:

	void buyTicket();
	void reserveTicket();
	void cancelReservation();
};

#endif // !_TICKETOFFICE_HPP


