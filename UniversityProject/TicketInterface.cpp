#include "TicketInterface.h"
#include "Constants.h"

void TicketInterface::work()
{
	TicketOffice office;
	std::ifstream file{ "halls.txt" };
	size_t size;
	file >> size;

	for (unsigned i = 0; i < size; i++)
	{
		Hall hall;
		file >> hall;
		office.addHall(hall);
		std::cout << office.getHalls()[i];
	}
	for (unsigned i = 1; i <= COMMANDS; i++)
	{
		std::cout << i <<": "<< commandsArray[i - 1]<<'\n';
	}
	unsigned commandNumber;
	do
	{
		std::cout << "Enter the number of the command that you want to proceed: ";
		std::cin >> commandNumber;
		if (commandNumber==6)
		{
			office.reservationList();
		}
		else if (commandNumber==7)
		{
			office.boughtTicketRefference();
		}
		else if (commandNumber==8)
		{
			return;
		}
		else
		{
			Show show;
			std::cin >> show;
			switch (commandNumber)
			{
			case 1:
				office.addShow(show);
				break;
			case 2:
				office.freeSeats(show);
				break;
			case 3:
				office.reserveTicket(show);
				break;
			case 4:
				office.cancelReservation(show);
				break;
			case 5:
				office.buyTicket(show);
				break;
			default:
				break;
			}
		}
	} while (commandNumber>=1 && commandNumber<=COMMANDS);
}