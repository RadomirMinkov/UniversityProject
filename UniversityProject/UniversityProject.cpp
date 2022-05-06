#include <iostream>
#include <fstream>
#include <exception>

#include "Show.h"
#include "Hall.h"
#include "Reservation.h"

void testShow()
{
	Date birth(2, october, 2002);
	std::cout << birth;
	Show show(birth,3, "Rado",2);
	Show show1(show);
	Show show2;
	show2 = show1;
	std::cin >> show;
	std::cout << show << show2 << show1;
}

/*void testHall()
{

	Hall hall(3, 10, 12, 2);
	//std::ofstream file( "milka.txt" );
	//hall.showSeats(std::cout);
	int arr[] = { 3,4,6 };
	hall.buyTickets(1, arr, 3);
	std::cout << "-------------------------------------\n";
	hall.showSeats(std::cout);
	//file.close();

}*/

void testReservation()
{
	Reservation reserv("rado", "az sym tuk",3,4);
	const char* name = "pesho";
	reserv.addToNote(name);
	std::cout << reserv.getNote();
}
int main()
{
	//Show show("Rado", Reservation"02/10/2002");
	//testShow();
	//std::cout << (char)251;
    //testHall();
	testReservation();
	return 0;
}

