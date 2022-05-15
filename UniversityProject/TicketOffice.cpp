#include "TicketOffice.h"

TicketOffice::TicketOffice(unsigned _capacity)
{
	halls = MyVector<Hall>(_capacity);
}

void TicketOffice::addHall(Hall const& hall)
{
	halls.addElement(hall);
}
void TicketOffice::addShow(Show const& show)
{
	Hall* hall = show.getHall();
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		if (halls[i]==*hall)
		{
			halls[i].addNewShow(show);
			std::cin.get();
			return;
		}
	}
}

void TicketOffice::freeSeats(Show const& show)const
{
	Hall* hall = show.getHall();
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		if (halls[i] == *hall)
		{
			halls[i].printEmptySeats(std::cout, show);
			return;
		}
	}
}
void TicketOffice::reserveTicket(Show const& show)
{
	Hall* hall = show.getHall();
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		if (halls[i] == *hall)
		{
			if (halls[i].reserveTicket(show))
			{
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
		if (halls[i]==*hall)
		{
			if (halls[i].cancelShowReservation(std::cin, show))
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
		if (halls[i]==*hall)
		{
				
			if (halls[i].buyTicket(show))
			{
				std::cout << "The purchase was successful,enjoy the show!\n";
			}
			else
			{
				std::cout << "The transaction couldn't be completed! Try again with different seat!\n";
			}
			return;
		}
	}
}
void TicketOffice::reservationList() const
{
	MyStr name;
	MyStr date;
	do
	{
		std::cout << "Enter all or name for the command to proceed:\n";
		std::cin >> name;
		name.toLower();
	} while (name!="name"&& name!="all");
	do
	{
		std::cout << "Enter all or date for the command to proceed:\n";
		std::cin >> date;
		date.toLower();
	} while (date != "date"&& date != "all");
	MyStr currName(name);
	MyStr textFile(currName + "-" + date + ".txt");
	char* newName = new char[textFile.getSize() + 1];
	strcpy(newName, textFile.getString());
	std::ofstream file{ newName };
	if (date=="date" && name=="name")
	{
		Date newDate;
		std::cin >> newDate;
		for (unsigned i = 0; i < halls.getSize(); i++)
		{
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
	std::cout << "Entering begining date:\n";
	std::cin >> beginingDate;
	std::cout << "Entering ending date:\n";
	std::cin>> endingDate;
	std::ofstream file{ "BoughtSeats.txt" };
	do
	{
		std::cout << "Enter all or hall for the command to proceed\n";
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

void TicketOffice::showList() const
{
	MyVector<Show> shows;
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		for (unsigned j = 0; j < halls[i].getShows().getSize(); i++)
		{
			std::cout << halls[i].getShows()[j];
		}
	}
}
void TicketOffice::sortShowsByMostWatched(MyVector<Show>& shows,MyVector<double>& attendance,unsigned start, unsigned finish)const
{
	if (start > finish)
		return;
	unsigned pivot = start;
	for (unsigned i = start; i < finish; i++)
	{
		if (attendance[i] < attendance[finish])
		{
			std::swap(shows[i], shows[finish]);
			
			std::swap(attendance[i], attendance[finish]);
		}
	}
	std::swap(shows[finish], shows[pivot]);
	if (pivot > start)
	{
		sortShowsByMostWatched(shows,attendance,start, pivot - 1);
		sortShowsByMostWatched(shows,attendance,pivot + 1, finish);
	}
}

void TicketOffice::mostWatchedShows()const
{
	MyVector<Show> shows= MyVector<Show>(2);
	MyVector<double> attendance;
	for (unsigned i = 0; i < halls.getSize(); i++)
	{
		for (unsigned j = 0; j < halls[i].getShows().getSize(); i++)
		{
			unsigned count{ 0 };
			while (halls[i].getShows()[j].getName() != shows[count].getName() && count < shows.getSize())
				count++;

			if (count==shows.getSize())
			{
				shows.addElement(halls[i].getShows()[j]);
				attendance.addElement(halls[i].getShows()[j].getAttendance());
			}
			else
			{
				double newAttendance =( attendance[count] + halls[i].getShows()[j].getAttendance()) / 2;
				attendance[count] = newAttendance;
			}
			
		}
	}
	sortShowsByMostWatched(shows, attendance, 0, shows.getSize()-1);
	std::cout << "Enter the number of the top shows you want to see.\n";
	std::cout << "I want to see the top: ";
	unsigned numberOfTopShows{};
	std::cin >> numberOfTopShows;
	if (numberOfTopShows<shows.getSize())
	{
		for (unsigned i = 0; i < numberOfTopShows; i++)
		{
			std::cout << shows[i].getName()<<'\n';
		}
	}
	else
	{
		std::cout << "There are not that many shows! Here are the name of the shows we got sorted by most watched!\n";
		for (unsigned i = 0; i < shows.getSize(); i++)
		{
			std::cout << shows[i].getName() << '\n';
		}
	}
}


void TicketOffice::readFromText(std::ifstream& in)
{
	int size;
	in >> size;
	for (unsigned i = 0; i < size; i++)
	{
		Hall hall;
		hall.readFromText(in);
		halls.addElement(hall);
	}
}
