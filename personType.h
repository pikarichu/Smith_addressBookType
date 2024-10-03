#pragma once
#include "addressType.h"
#include "dateType.h"
#include "personType.h"
//#include "extPersonType.h"

class personType
{
public:
	void setFirstName(string fName)
	{
		firstName = fName; //sets the first name
	}
	string getFirstName()
	{
		return firstName; //returns the first name
	}
	void setLastName(string lName)
	{
		lastName = lName; //sets the last bane
	}
	string getLastName()
	{
		return lastName; //returns the last name
	}
	void print()
	{
		cout << firstName << " " << lastName << endl; //print for personType
	}
	personType( //constructor with parameters
		string fName,
		string lName
	)
	{
		setFirstName(fName);
		setLastName(lName);
	}
	personType() //defualt constructor
	{

	}

private:
	string firstName;
	string lastName;

};

