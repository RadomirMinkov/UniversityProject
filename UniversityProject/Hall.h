#ifndef _HALL_HPP
#define _HALL_HPP
#include <iostream>
#include <cassert>

//#include "Types.h"
#include "MyVector.h"
#include "Show.h"
#include "Reservation.h"
#include "MyStr.h"

const int MAX_ANSWER_BUFFER = 3;
class Hall
{
private:
	//�������� �� �����

	//����� �� ������
	unsigned hallNumber;
	//���� ������
	unsigned rows;
	//����� �� ���
	unsigned seatsOnRow;
	//������ � ������������� � ������
	MyVector<Show> shows;

	//������� �� �������� �� ������������ �� ���� ���� � ����
	void copy(Hall const& other);
	
	Show& getShow(Show const& show)const;
	//����� ����� ����� ��� � ������
	int  getNumberOfSeats() const;
public:
	//����������� � ��������� �� ������������
	Hall(unsigned _hallNumber=0,unsigned _rows=0, unsigned _seatsOnRow=0);
	//���� �����������, ����� �� ����� ������� �����
	Hall(Hall const& other);
	//�������� �� �����������
	Hall& operator=(Hall const& other);

	//������� �� ���������� �������  ������
	unsigned getHallNumber() const { return hallNumber; }
	unsigned getRows() const { return rows; }
	unsigned getSeatsOnRows() const { return seatsOnRow; }
	MyVector<Show> getShows() const { return shows; }
	//�������� ���� ������ � ����������� �� ������ ����
	bool isReserved(Date _date);

	//�������� �� ���� �������������
	bool addNewShow(Show const& show);
	//�������� �� �����
	bool buyTicket(Show show,unsigned _rowNumber,unsigned _seat);

	//void sortShowsByDate();
	//������� ������ � ������� � ������
	void showSeats(std::ostream& out,Show const& show) const;
	void seatsReference(Show const& show, std::ostream& out=std::cout) const;
	//����������� �� ������
	bool reserveTicket(Show show);
	//��������� �� ���������� �� ������
	void print(std::ostream& out=std::cout) const;
	//�������� ���� ��� ����������� ����
	bool isEmpty();
	friend std::istream& operator>>(std::istream& in, Hall& hall);
};

std::ostream& operator<<(std::ostream& out, Hall const& hall);

#endif
