#include <iostream>
#include <fstream>
#include "Show.h"
#include "Hall.h"


void testShow()
{
	Show show(3, "Rado", "02/10/2002");
	Show show1(show);
	Show show2;
	show2 = show1;
	std::cin >> show;
	std::cout << show<< show2 << show1;
}

void testHall()
{

	Hall hall(3, 10, 12, 2);
	//std::ofstream file( "milka.txt" );
	hall.showSeats(std::cout);
	int arr[]={ 3,4,6 };
	hall.buyTickets(1, arr, 3);
	std::cout << "-------------------------------------\n";
	hall.showSeats(std::cout);
	//file.close();

}

int main()
{
	//Show show("Rado", "02/10/2002");
	//testShow();
	//std::cout << (char)251;
	testHall();
	return 0;
}

