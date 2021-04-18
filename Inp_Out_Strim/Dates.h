#pragma once
#include "Header.h"

class Dates
{
private:

	int _day = 1;
	int _month = 1;
	int _year = 2000;
	int _message = 0;

public:
	Dates() = default;
	Dates(const int& y, const int& m, const int& d);

	static int CountDayMonth(const int& y, const int& m);
	void SetYear(const int& y);
	void SetMonth(const int& m);
	void SetDay(const int& d);
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	int GetMessage() const;
	void PrintDates() const;
};
