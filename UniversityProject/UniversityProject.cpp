#include <iostream>
#include <fstream>
#include <exception>

#include "Show.h"
#include "Hall.h"
#include "Reservation.h"
#include "MyStr.h"
#include "Types.h"
#include "TicketOffice.h"
#include "TicketInterface.h"
int main()
{

/*	Date date5(2, october, 2002);
	Date date1(2, october, 2002);
	Date date2(2, october, 2001);
	Date date3(2, november, 2002);
	Date date4(21, october, 2002);
	std::cout << std::boolalpha << (date5 == date1) << '\n';
	std::cout << std::boolalpha << (date5 != date1) << '\n';
	std::cout << std::boolalpha << (date3 <= date1) << '\n';
	std::cout << std::boolalpha << (date3 > date1) << '\n';
	std::cout << std::boolalpha << (date3 >= date1) << '\n';
	std::cout << std::boolalpha << (date3 < date1) << '\n';



	MyVector<int> arr(5);
	arr.addElement(2);
	arr.addElement(1);
	std::cout << arr[1] << '\n';

	MyStr str;
	str.copy("Rado");
	str.toLower();
	MyStr rad("penka");
	std::cout << str << '\n' << (rad != str) << '\n';
	MyStr birth("02/10/2002");
	Date myBirth;
	myBirth=birth.toDate();
	std::cout << birth<<'\n';
	std::cout << myBirth;

	Reservation reservation(1, 1, "radomir", "hello");
	Reservation reser(3, 4, "rado", "Az obicham pasta");
	reservation.replaceNote("Milko ");
	reservation.addToNote("Kalaidjiev");
	std::cout << reservation.getNote() << '\n';

	Date date(2, october, 2002);*/



	/*Hall hall(1, 5, 6);
	Show show("Lord of the Rings", date, 2, &hall);
	Show show1("Doctor Strange", date2, 2, &hall);
	hall.addNewShow(show);
	hall.addNewShow(show1);
	hall.buyTicket(show, 2, 3);
	hall.buyTicket(show1, 1, 1);
	hall.buyTicket(show, 2, 3);
	hall.buyTicket(show, 3, 4);
	std::cout << "------------------------------------------\n";
	std::cout << '\n' << '\n';
	hall.showSeats(std::cout, show);
	std::cout << "------------------------------------------\n";
	std::cout << '\n' << '\n';
	std::cout<<hall.reserveTicket(show)<<'\n';
	std::cout<<hall.reserveTicket(show)<<'\n';
	std::cout<<hall.reserveTicket(show)<<'\n';
	hall.showSeats(std::cout, show);
	hall.buyTicket(show1, 2, 2);
	hall.buyTicket(show1, 1, 3);
	hall.buyTicket(show1, 2, 4);
	hall.buyTicket(show1, 1, 5);
	std::ofstream file("text.txt");
	hall.printBoughtSeats(file, date2, date4);*/
	//hall.showSeats(std::cout, show1);

	TicketOffice office;
	Hall hall(1, 5, 6);
	Date date(2, october, 2002);
	office.addHall(hall);
	Show show("Naruto", date, 2, &hall);
	office.addShow(show);
	office.buyTicket(show);
	office.reserveTicket(show);
	office.buyTicket(show);
	office.freeSeats(show);
	/*office.cancelReservation(show);
	office.reserveTicket(show);
	office.reserveTicket(show);
	office.reserveTicket(show);
	office.reserveTicket(show);*/
	//office.boughtTicketRefference();
	office.reservationList();
	return 0;
}

