#ifndef _HALL__HPP
#define _HALL_HPP
#include <iostream>
#include <cassert>

#include "Show.h"
#include "Reservation.h"
class Hall
{
private:
	//�������� �� �����

	//����� �� ������
	unsigned hallNumber;
	//���� ������
	unsigned rows;
	//���� �������������
	size_t showSize;
	//�������� �� ������ �� �������������
	unsigned showCapacity;
	//����� �� ���
	unsigned seatsOnRow;
	//������ � ������������� � ������
	Show *shows;

	//���������� �� �������
	void clear();
	//����������� �� ������� �� �������������
	void resize(unsigned newCapacity);
	//������� �� �������� �� ������������ �� ���� ���� � ����
	void copy(Hall const& other);
	//���� ���������� �� �������
	char place(Seats seat) const;
	//����� ����� ����� ��� � ������
	int  getNumberOfSeats() const;
public:
	//����������� � ��������� �� ������������
	Hall(unsigned _hallNumber=0,unsigned _rows=0, unsigned _seatsOnRow=0, unsigned _showCapacity=2);
	//���� �����������, ����� �� ����� ������� �����
	Hall(Hall const& other);
	//�������� �� �����������
	Hall& operator=(Hall const& other);
	//����������
	~Hall();

	//������� �� ���������� �������  ������
	unsigned getHallNumber() const { return hallNumber; }
	unsigned getRows() const { return rows; }
	unsigned getSeatsOnRows() const { return seatsOnRow; }
	unsigned getShowCapacity() const { return showCapacity; }
	unsigned getShowSize() const { return showSize; }

	//�������� ���� ������ � ����������� �� ������ ����
	bool isReserved(Date _date);

	//�������� �� ���� �������������
	bool addNewShow(Show const& show);
	//�������� �� �����
	void buyTickets(unsigned _hallNumber, int* seats, unsigned numberOfSeats);

	//������� ������ � ������� � ������
	void showSeats(std::ostream& out,Show const& show) const;
	void seatsReference(Show const& show, std::ostream& out=std::cout) const;
	//����������� �� ������
	Reservation reserveTickets(unsigned _hallNumber, int* seats, unsigned numberOfSeats);
	//��������� �� ���������� �� ������
	void print() const;
	//�������� ���� ��� ����������� ����
	bool isEmpty();
};

#endif
