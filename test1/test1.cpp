// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
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
		cout << "设置了错误日期，月日已置1" << endl;
	}
}
int CMyDate::setDate(int y, int m, int d)
{
	cout << "请输入开始 年 月 日" << endl;
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
		cout << "设置了错误日期，月日已置1" << endl;
		return -1;
	}
	return 0;

}
void CMyDate::displayDate()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
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
	cout << "请输入结束 年 月 日" << endl;
	cin >> a >> b >> c ;
	cout << a << "年" << b << "月" << c << "日" << endl;
	while (!((od.getYear() ==a) && (od.getMonth() == b) && (od.getDay()) == c))
	{
		od.addOneDay();
		count++;
	}
	cout << endl;
	cout <<"有" << count << "天" << endl;
	system("pause");
	return 0;
}