#include "dateType.h"
#include <iostream>



int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int daysInYear = 365;

bool dateType::isLeapYear()
{
	if ((year % 400 == 0 || year % 100 != 0) && (year % 4 == 0))
		return true;
	else
		return false;

}

int dateType::getDaysInMonth(int month, int year)
{
	if (isLeapYear() == true && month == 2)
	{
		return daysInMonth[month - 1] + 1; //number of days in feb during leap year
	}
	else
	{
		return daysInMonth[month - 1]; //number of days in feb not during leap year
	}
}

void dateType::setDate() //default constructor
{
	dateType::month = 1;
	dateType::day = 1;
	dateType::year = 1900;
}

void dateType::setDate(int month, int day, int year) //constructor with parameters
{
	if (year < 1900)
	{
		setDate(); //sets date to 1-1-1900 if it is out of range
	}
	if (isLeapYear() == true)
	{
		daysInYear = 366;
		daysInMonth[1] = 29;
	}
	else
	{
		daysInYear = 365;
		daysInMonth[1] = 28;
	}
	if (day > daysInMonth[month - 1] || month > 12)
	{
		cout << "Date invalid, setting to 1/1/1900" << endl;
		setDate(); //sets date to 1-1-1900 if it is out of range
	}
	else
	{
		dateType::month = month;
		dateType::day = day;
		dateType::year = year;
	}

}

int dateType::getDay() //returns day
{
	return day;
}

int dateType::getMonth() //returns month
{
	return month;
}

int dateType::getYear() //returns year
{
	cout << year << endl;
	return year;
}

void dateType::print() const
{
	cout << month << "-" << day << "-" << year << endl; //prints out a date in MM-DD-YYYY format
}



dateType::dateType(int day, int month, int year)
{
	setDate(day, month, year);
}