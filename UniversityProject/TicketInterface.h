#ifndef _TICKETINTERFACE_HPP
#define _TICKETINTERFACE_HPP

#include "TicketOffice.h"
/// class that control all the commands and the user input
class TicketInterface
{
private:

public:
/**
 * @brief static function which will proccess the user input and perform the needed function
 * 
 * @param office the class that provides the needed functions
 */
	static void work(TicketOffice office);
};

#endif // ! _TICKETINTERFACE_HPP


