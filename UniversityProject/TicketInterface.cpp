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
		//std::cout << office.getHalls()[i];
	}
	unsigned commandNumber;
	do
	{
		for (unsigned i = 0; i < size; i++)
		{
			std::cout << office.getHalls()[i];
		}
		for (unsigned i = 1; i <= COMMANDS; i++)
		{
			std::cout << i << ": " << commandsArray[i - 1] << '\n';
		}
		std::cout << "Enter the number of the command that you want to proceed: ";
		std::cin >> commandNumber;
		if (commandNumber == 6)
		{
			office.reservationList();
			system("CLS");
		}
		else if (commandNumber == 7)
		{
			office.boughtTicketRefference();
			system("CLS");
		}
		else if (commandNumber == 8)
		{
			std::cout << "Thank you!Have a good day!";
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
				std::cin.get();
				break;
			case 2:
				office.freeSeats(show);
				std::cin.get();
				break;
			case 3:
				office.reserveTicket(show);
				break;
			case 4:
				office.cancelReservation(show);
				break;
			case 5:
				office.buyTicket(show);
				std::cin.get();
				break;
			default:
				break;
			}
			std::cin.get();
			system("CLS");
		}
	} while (commandNumber >= 1 && commandNumber <= COMMANDS);
}