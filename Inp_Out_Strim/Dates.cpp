#include "Header.h"

Dates::Dates(const int& y, const int& m, const int& d)
{
    _message = 0;
    SetYear(y);
    SetMonth(m);
    SetDay(d);
}

int Dates::CountDayMonth(const int& y, const int& m)
{
    int countDay;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 ||
        m == 10 || m == 12)
    {
        countDay = 31;
    }
    else
    {
        if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            countDay = 30;
        }
        else
        {
            if (m == 2 &&
                ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))))
            {
                countDay = 29;
            }
            else
            {
                countDay = 28;
            }
        }
    }
    return countDay;
}

void Dates::SetYear(const int& y)
{
    if ((y < 1900 || y > 2022))
    {
        _message = -3;
    }
    else
    {
        _year = y;
    }
}

void Dates::SetMonth(const int& m)
{
    if (_month < 1 || _month > 12)
    {
        _message = -2;
    }
    else
    {
        _month = m;
    }
}

void Dates::SetDay(const int& d)
{
    int countDay = CountDayMonth(_year, _month);
    if (_day < 1 || _day > countDay)
    {
        _message = -1;
    }
    else
    {
        _day = d;
    }
}

int Dates::GetDay() const
{
	return _day;
}

int Dates::GetMonth() const
{
	return _month;
}

int Dates::GetYear() const
{
	return _year;
}

int Dates::GetMessage() const
{
	return _message;
}

void Dates::PrintDates() const
{
    cout << setfill('0') << setw(2) << _day << "." << setw(2) << _month << "." << setw(2) << _year << endl;
}


