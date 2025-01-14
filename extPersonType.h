#pragma once
#include "addressType.h"
#include "dateType.h"
#include "personType.h"

class extPersonType : public personType
{
public:
	void setPhoneNumber(string pnum)
	{
		phoneNumber = pnum; //sets the phone number
	}
	string getPhoneNumber()
	{
		return phoneNumber; //returns the phone number
	}
	void setRelationship(string rship) //sets the relationship if valid
	{
		if (rship == "Family" || rship == "Friend" || rship == "Business")
		{
			relationship = rship;
		}
		else
		{
			relationship = "";
		}
	}
	string getRelationship() //returns the relationship
	{
		return relationship;
	}
	int getBirthMonth() //returns the birth month
	{
		return birthdate.getMonth();
	}
	void print() //prints out the person's info
	{
		cout << endl << getFirstName() << " " << getLastName() << endl;
		birthdate.print();
		address.print();
		cout << getPhoneNumber() << endl;
		cout << getRelationship() << endl;
	}
	extPersonType() //default constructor
	{

	}
	extPersonType( //constructor with parameters
		string fName,
		string lName,
		int bMonth,
		int bDay,
		int bYear,
		string street,
		string city,
		string state,
		int zip,
		string phoneNumber,
		string relationship
	)
	{
		setFirstName(fName);
		setLastName(lName);
		birthdate.setDate(bMonth, bDay, bYear);
		address.setAddress(street);
		address.setCity(city);
		address.setState(state);
		address.setZipcode(zip);
		setPhoneNumber(phoneNumber);
		setRelationship(relationship);
	}

private:
	addressType address;
	dateType birthdate;
	string phoneNumber;
	string relationship;
};

