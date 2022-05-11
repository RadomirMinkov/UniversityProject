#include <iostream>
#include <fstream>
#include <exception>

#include "Show.h"
#include "Hall.h"
#include "Reservation.h"
#include "MyStr.h"
#include "Types.h"

int main()
{
	//Show show("Rado", Reservation"02/10/2002");
	//testShow();
	//std::cout << (char)251;
    //testHall();
	//testReservation();

    Date date5(2, october, 2002);
	Date date1(2, october, 2002);
	Date date2(2, october, 2001);
	Date date3(2, november, 2002);
	Date date4(21, october, 2002);
	std::cout <<std::boolalpha<< (date5 == date1)<<'\n';
	std::cout <<std::boolalpha<< (date5 != date1)<<'\n';
	std::cout <<std::boolalpha<< (date3 <= date1)<<'\n';
	std::cout <<std::boolalpha<< (date3 > date1)<<'\n';
	std::cout <<std::boolalpha<< (date3 >= date1)<<'\n';
	std::cout <<std::boolalpha<< (date3 < date1)<<'\n';



	MyVector<int> arr(5);
	arr.addElement(2);
	arr.addElement(1);
	std::cout << arr[1] << '\n';

	MyStr str;
	str.copy("Rado");
	str.toLower();
	MyStr rad("penka");
	std::cout << str << '\n'<<(rad!=str)<<'\n';


	Reservation reservation(1,1,"radomir","hello");
	Reservation reser(3, 4, "rado", "Az obicham pasta");
	reservation.replaceNote("Milko ");
	reservation.addToNote("Kalaidjiev");
	std::cout << reservation.getNote()<<'\n';

	Date date(2, october, 2002);



	Hall hall(1, 5, 6);
	Show show("Lord of the Rings", date, 2, &hall);
	Show show1("Doctor Strange", date2, 2, &hall);
	show.addReservation(reservation);
	show.addReservation(reser);
	hall.addNewShow(show);
	hall.addNewShow(show1);
	show.buyTicket(2,3);
	std::cout << show << '\n';
	Reservation res = show.getReservation(3, 4);
	show.printSeats(std::cout,5,6);
	hall.buyTicket(show, 2, 3 );
	hall.buyTicket(show1,1, 1 );
	hall.buyTicket(show,2, 3);
	hall.buyTicket(show,3, 4);
	std::cout << "------------------------------------------\n";
	show.printSeats(std::cout, 5, 6);
	std::cout<<'\n'<<'\n';
	hall.showSeats(std::cout,show);
	std::cout << show<<'\n';// << show1;
	hall.reserveTicket(show, 2, 1);
	std::cout << show;
	return 0;
}

