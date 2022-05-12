#include "TicketOffice.h"

TicketOffice::TicketOffice(unsigned _capacity)
{
	halls = MyVector<Hall>(_capacity);
}


void TicketOffice::addShow(Show const& show)
{
	Hall* hall = show.getHall();
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		if (&halls[i]==hall)
		{
			halls[i].addNewShow(show);
			return;
		}
	}
}

void TicketOffice::freeSeats(Show const& show)const
{
	Hall* hall = show.getHall();
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		if (&halls[i] == hall)
		{
			hall[i].printEmptySeats(std::cout, show);
			return;
		}
	}
}

void TicketOffice::reserveTicket(Show const& show)
{
	Hall* hall = show.getHall();
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		if (&halls[i] == hall)
		{
			bool isSuccessful = halls[i].reserveTicket(show);
			if (isSuccessful)
			{
				hall[i].reserveTicket(show);
				std::cout << "You reserved the ticket successfully! Don't forget your password!\n";
			}
			else
			{
				std::cout << "The ticket wasn't reserverd succesfully!\n";
			}
			return;
		}
	}
}

void TicketOffice::cancelReservation(Show const& show)
{
	Hall* hall = show.getHall();
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		if (&halls[i]==hall)
		{
			bool isSuccessful= halls[i].cancelShowReservation(std::cin,show);
			halls[i].cancelShowReservation(std::cin, show);
			if (isSuccessful) 
			{
				std::cout << "You successfully canceled your reservation!\n";
			}
			else
			{
				std::cout << "The cancelation was not successful\n";
			}
			return;
		}
	}
}

void TicketOffice::buyTicket(Show const& show)
{
	Hall* hall = show.getHall();
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		if (&halls[i]==hall)
		{
			unsigned rowNumber;
			unsigned seat;
			std::cout << "Enter row: ";
			std::cin >> rowNumber;
			std::cout << "Enter seat: ";
			std::cin >> seat;
			bool isSuccessful = halls[i].buyTicket(show, rowNumber, seat);
			halls[i].buyTicket(show, rowNumber, seat);
			if (isSuccessful)
			{
				std::cout << "The purchase was successful,enjoy the show!\n";
			}
			else
			{
				std::cout << "The transaction couldn't be completed! Try again with different seat!\n";
			}
		}
	}
}
void TicketOffice::reservationList() const
{
	MyStr name;
	MyStr date;
	do
	{
		std::cout << "Enter all or name for the command to proceed:";
		std::cin >> name;
		name.toLower();
	} while (name!="name"&& name!="all");
	do
	{
		std::cout << "Enter all or date for the command to proceed:";
		std::cin >> date;
		date.toLower();
	} while (date != "date"&& date != "all");

	MyStr textFile(name + "-" + date + ".txt");
	char* newName = new char[textFile.getSize() + 1];
	strcpy(newName, textFile.getString());
	std::ofstream file{ newName };
	if (date=="date" && name=="name")
	{
		for (unsigned i = 0; i < halls.getSize(); i++)
		{
			Date newDate;
			std::cin >> newDate;
			halls[i].printReservedSeats(file, newDate, name);
		}
	}
	else if(date=="date" && name=="all")
	{
		for (unsigned i = 0; i < halls.getSize(); i++)
		{
			Date newDate;
			std::cin >> newDate;
			halls[i].printReservedSeats(file, newDate, name);
		}
	}
	else if (date=="all" && name=="name")
	{
		for (unsigned i = 0; i < halls.getSize(); i++)
		{
			for (unsigned j = 0; j < halls[i].getShows().getSize(); j++)
			{
				if (name == halls[i].getShows()[j].getName())
				{
					file << halls[i].getShows()[j];
					file << "For this show " <<halls[i].getShows()[j].getReservedTickets() << " are reserved!\n";
					halls[i].getShows()[j].printSeatsType(file, reserved);
					halls[i].getShows()[j].printSeats(file, halls[i].getRows(), halls[i].getSeatsOnRows());
				}
			}
		}
	}
	else if (date == "all" && name == "all")
	{
		for (unsigned i = 0; i < halls.getSize(); i++)
		{
			for (unsigned j = 0; j < halls[i].getShows().getSize(); j++)
			{
					file << halls[i].getShows()[j];
					file << "For this show " << halls[i].getShows()[j].getReservedTickets() << " are reserved!\n";
					halls[i].getShows()[j].printSeatsType(file, reserved);
					halls[i].getShows()[j].printSeats(file, halls[i].getRows(), halls[i].getSeatsOnRows());
			}
		}
	}

}
void TicketOffice::boughtTicketRefference()const
{
	MyStr str;
	Date beginingDate;
	Date endingDate;
	std::cin >> beginingDate >> endingDate;
	std::ofstream file{ "BoughtSeats.txt" };
	do
	{
		std::cout << "Enter all or hall";
		std::cin >> str;
		str.toLower();
	} while (str!="all"&& str!="hall");
	if (str=="all")
	{
		for (unsigned i = 0; i < halls.getSize(); i++)
		{
			halls[i].printBoughtSeats(file, beginingDate, endingDate);
		}
	}
	else if (str=="hall")
	{
		unsigned hallNumber;
		std::cout << "Enter number of the hall for the command to proceed: ";
		std::cin >> hallNumber;
		for (unsigned i = 0; i < halls.getSize(); i++)
		{
			if (hallNumber==halls[i].getHallNumber())
			{
				halls[i].printBoughtSeats(file, beginingDate, endingDate);
			}
		}
	}
}