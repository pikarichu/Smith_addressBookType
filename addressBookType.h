#pragma once
#include <iostream>
#include <fstream>
#include "extPersonType.h"
#include "personType.h"
#include "addressType.h"
#include "dateType.h"

using namespace std;

class addressBookType
{
public:
	void initEntry(string addressList) //creates the address book
	{
		int lineNumber = 0;
		
		string line;
		string fullName;
		string bDate;
		string address;
		string city;
		string state;
		string zip;
		string phone;
		string relationship;
		string delimiter;
		string fname;
		string lname;
		string month;
		string day;
		string year;



		ifstream addressBookFile(addressList); //reads in the file

		while (getline(addressBookFile, line))
		{
			switch (lineNumber)
			{
			case 0: //gets the first name per entry
				fullName = line;
				delimiter = " ";
				fname = fullName.substr(0, fullName.find(delimiter));
				lname = fullName.substr(fullName.find(delimiter) + 1, '\n');
				break;

			case 1: //gets the last name per entry
				bDate = line;
				delimiter = " ";
				month = bDate.substr(0, bDate.find(delimiter));
				day = bDate.substr(bDate.find(delimiter) + 1, bDate.find(delimiter));
				year = bDate.substr(bDate.find_last_of(delimiter)+1 , '\n');
				break;

			case 2: //gets the address per entry
				address = line;
				break;

			case 3: //gets the city per entry
				city = line;
				break;

			case 4: //gets the state per entry
				state = line;
				break;

			case 5: //gets the zipcode per entry
				zip = line;
				break;

			case 6: //gets the phone number per entry
				phone = line;
				break;

			case 7: //gets the relationship per entry
				relationship = line;
				extPersonType record(fname, lname, stoi(month), stoi(day), stoi(year), address, city, state, stoi(zip), phone, relationship);
				addEntry(record);
				lineNumber = -1;
				break;
			}
				
			lineNumber++;

		}

	}


	void addEntry(extPersonType person) //adds an entry to the address bool
	{
		addressList[length] = person;
		length++;


	}
	void findPerson(string lName) //finds an entry by last name
	{
		for (int i = 0; i <= length; i++) 
		{
			if (addressList[i].getLastName() == lName)
			{
				addressList[i].extPersonType::print();
			}
		}
	}
	void findBirthdays(int bMonth) //finds an entry by birth month
	{
		for (int i = 0; i <= length; i++)
		{
			if (addressList[i].getBirthMonth() == bMonth)
			{
				cout << addressList[i].getFirstName() << " " << addressList[i].getLastName() << endl;
			}
		}
	}
	void findRelations(string relationship) //finds an entry by relationship
	{
		for (int i = 0; i <= length; i++)
		{
			if (addressList[i].getRelationship() == relationship)
			{
				cout << addressList[i].getFirstName() << " " << addressList[i].getLastName() << endl;
			}
		}
	}
	void print() //prints out the address book
	{
		for (int i = 0; i < length; i++)
		{
			addressList[i].print();
		}
	}
	void sortEntries() //sorts the entries by last name 
	{
		int current = 1;
		int index = 0;
		bool placeFound;
		extPersonType temp;
		while (current < length)

		{
			index = current;
			placeFound = false;
			while (index > 0 && !placeFound)
			{
				if (addressList[index].getLastName() < addressList[index - 1].getLastName())
				{
					temp = addressList[index];
					addressList[index] = addressList[index - 1];
					addressList[index - 1] = temp;
					index = index - 1;
				}
				else
				{
					placeFound = true;
				}
			}
			current = current + 1;
		}
		
	}

	addressBookType() //default constructor
	{
		length = 0;
		maxLength = 500;
	}

private:
	extPersonType addressList[500];
	int length;
	int maxLength;
};

