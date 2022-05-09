#include <iostream>
#include <fstream>
#include <exception>

#include "Show.h"
#include "Hall.h"
#include "Reservation.h"
#include "MyStr.h"


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
	str.copy("rado");
	std::cout << str << '\n';


	Reservation reservation;
	Reservation reser(3, 4, "rado", "Az obicham pasta");
	reservation.replaceNote("Milko ");
	reservation.addToNote("Kalaidjiev");
	std::cout << reservation.getNote();

	Date date(2, october, 2002);
	Show show(3, "Rado", date,2);
	show.createSeats(3, 4);
	show.printSeats(std::cout,3,4);
	show.buyTicket(2, 3);
	show.buyTicket(3, 4);
	show.printSeats(std::cout, 3, 4);
    show.addReservation(reservation);
	show.addReservation(reser);
	std::cout << show;



	return 0;
}

