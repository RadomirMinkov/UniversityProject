#ifndef _HALL__HPP
#define _HALL_HPP
#include "Show.h"
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
	//����� ��� ����� ����� � ������
	bool** seats;
	//������ � ������������� � ������
	Show *show;

	//���������� �� �������
	void clear();
	//����������� �� ������� �� �������������
	void resize(unsigned newCapacity);
	//������� �� �������� �� ������������ �� ���� ���� � ����
	void copy(Hall const& other);
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

	//������� ������ � ������� � ������
	void showSeats(std::ostream& out) const;
	//�������� ���� ������ � ����������� �� ������ ����
	bool isReserved(const char* date);

	void print() const;
	//�������� ���� ��� ����������� ����
	bool isEmpty();
};

#endif
