#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>
class Date
{
private:
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;
public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);

	bool CheckMonth(unsigned int localMonth);
	bool CheckYear(unsigned int localYear);

	void SetDay(unsigned int day);
	void SetMonth(unsigned int month);
	void SetYear(unsigned int year);

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	void Print();
	
	int operator[](int index);
};

