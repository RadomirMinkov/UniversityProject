#ifndef _HALL__HPP
#define _HALL_HPP
#include "Show.h"
class Hall
{
private:
	//�������� �� �����

	//����� �� ������
	unsigned hallNumber;
	//����� �� ����
	unsigned rowNumber;
	//���� ������
	unsigned rows;
	//����� �� ���
	unsigned seatsOnRow;
	//����� ��� ����� ����� � ������
	bool** seats;
	//������ � ������������� � ������
	Show *show;
	//���������� �� �������
	void clear();
public:
	//����������� � ��������� �� ������������
	Hall(unsigned _hallNumber=0, unsigned _rowNumber=0, unsigned _rows=0, unsigned _seatsOnRow=0, bool** seats=nullptr, bool _isReserved=false);
	//���� �����������, ����� �� ����� ������� �����
	Hall(Hall const& other);
	//�������� �� �����������
	Hall& operator=(Hall const& other);
	//����������
	~Hall();

	//������� �� ���������� �������  ������
	unsigned getHallNumber() const { return hallNumber; }
	unsigned getRowNumber() const { return rowNumber; }
	unsigned getRows() const { return rows; }
	unsigned getSeatsOnRows() const { return seatsOnRow; }

};

#endif
