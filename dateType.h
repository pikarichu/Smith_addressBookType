#pragma once
#include <string>

using namespace std;


class dateType
{
public:
	//Precondition: Year
	//Postcondition: Sets isLeapYear true or false
	bool isLeapYear();

	void setDate();
	//Precondition: integer of month, day, and year
	//Postcondition: sets dateType month, day and year
	//sets daysInYear and daysInMonth based on the result of isLeapYear
	void setDate(int month, int day, int year);

	//Precondition: valid dateType
	//Postcondition: prints the date
	void print() const;

	//Postcondition - returns value of day
	int getDay();

	//Postcondition - returns value of month
	int getMonth();

	//Postcondition - returns value of year
	int getYear();

	//Postcondition - returns days in month
	int getDaysInMonth(int month, int year);

	//Constructor
	dateType(int day = 1, int month = 1, int year = 1900);
private:
	int day, month, year;
};



