// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class CMyDate
{
protected:
	int year;
	int month;
	int day;
	int check();
public:
	CMyDate();
	CMyDate(int y, int m, int d);
	int setDate(int y, int m, int d);
	void displayDate();
	int getYear();
	int getMonth();
	int getDay();
};
CMyDate::CMyDate()
{
	
}
CMyDate::CMyDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "�����˴������ڣ���������1" << endl;
	}
}
int CMyDate::setDate(int y, int m, int d)
{
	cout << "�����뿪ʼ �� �� ��" << endl;
	cin >> y;
	cin >> m;
	cin >> d;
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "�����˴������ڣ���������1" << endl;
		return -1;
	}
	return 0;

}
void CMyDate::displayDate()
{
	cout << year << "��" << month << "��" << day << "��" << endl;
}
int CMyDate::check()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
	}
	return 0;
}
int CMyDate::getYear()
{
	return year;
}
int CMyDate::getMonth()
{
	return month;
}
int CMyDate::getDay()
{
	return day;
}
class CBagena:public CMyDate
{
public:
	void CBagena::addOneDay();
};
void CBagena::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}

}
int main()
{

	CBagena od;
	int i;
	int count = 1;
	od.setDate(0,0,0);
	od.displayDate();
	int a, b, c;
	cout << endl;
	cout << "��������� �� �� ��" << endl;
	cin >> a >> b >> c ;
	cout << a << "��" << b << "��" << c << "��" << endl;
	while (!((od.getYear() ==a) && (od.getMonth() == b) && (od.getDay()) == c))
	{
		od.addOneDay();
		count++;
	}
	cout << endl;
	cout <<"��" << count << "��" << endl;
	system("pause");
	return 0;
}