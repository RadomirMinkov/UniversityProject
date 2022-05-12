#ifndef _HALL_HPP
#define _HALL_HPP
#include <iostream>
#include <cassert>
#include <fstream>

#include "Types.h"
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
	Reservation enterReservatoin() const;
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
	void printBoughtSeats(std::ofstream& out,Date beginingDate, Date endingDate) const;
	void printReservedSeats(std::ofstream& out,Date date,MyStr name)const;
	void printEmptySeats(std::ostream& out, Show show)const;
	void print(std::ostream& out)const;
	bool cancelShowReservation(std::istream& in,Show const& show);
	bool operator==(Hall const& other)const;
	//�������� ���� ��� ����������� ����
	bool isEmpty();
	friend std::istream& operator>>(std::istream& in, Hall& hall);
};

std::ostream& operator<<(std::ostream& out, Hall const& hall);

#endif
