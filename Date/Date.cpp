#include "Date.h"
using namespace std;
Date::Date()
{
	SYSTEMTIME tm;
	GetSystemTime(&tm);
	Day = tm.wDay;
	Month = tm.wMonth;
	Year = tm.wYear;
}
Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	SetDay(day);
	SetMonth(month);
	SetYear(year);
}
bool Date::CheckMonth(unsigned int localMonth)
{
	if (localMonth == 1 || localMonth == 3 || localMonth == 5 || localMonth == 7 || localMonth == 8 || localMonth == 10 || localMonth == 12)
	{
		return true;
	}
	else if (localMonth == 4 || localMonth == 6 || localMonth == 9 || localMonth == 12)
	{
		return false;
	}
}

bool Date::CheckYear(unsigned int localYear)
{
	if (localYear % 4 == 0 || localYear % 100 == 0 && localYear % 400 == 0)
	{
		return false;
	}
	return true;
}
void Date::SetDay(unsigned int day)
{
	if (CheckMonth(Month))
	{
		if (day >= 1 && day <= 31)
		{
			Day = day;
		}
	}
}
void Date::SetMonth(unsigned int month)
{
	if (CheckYear(Year))
	{
		if (month >= 1 && month <= 12)
		{
			Month = month;
		}
	}
}
void Date::SetYear(unsigned int year)
{
	if (year >= 1)
		Year = year;
	else
		Year = 2022;
}

int Date::GetDay() const
{
	return Day;
}

int Date::GetMonth() const
{
	return Month;
}

int Date::GetYear() const
{
	return Year;
}

void Date::Print()
{
	cout << GetDay() << "\n";
	cout << GetMonth() << "\n";
	cout << GetYear() << "\n";
}

int Date::operator[](int index)
{
	if (index == 0)
		return Day;
	else if (index == 1)
		return Month;
	else if (index == 2)
		return Year;
	else if (index == 3)
		throw "incorrect index!!!";
}
