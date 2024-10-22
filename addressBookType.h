#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "personType.h"
#include "extPersonType.h"
#include "addressType.h"
#include "dateType.h"
#include "linkedList.h"
#include "orderedLinkedList.h"


using namespace std;

class addressBookType: public orderedLinkedList<extPersonType>
{
public:
	//addressBookType* myAddressBook;


	void initEntry(string addressList) //creates the address book
	{
		cout << "In initEntry(string addressList), in addressBookType.h, line 20"
			<< endl;
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
			cout << "In getline(addressList), addressBookType.h, line 44" << endl;
			switch (lineNumber)
			{
			case 0: //gets the first name per entry
				fullName = line;
				cout << fullName << endl;
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

	void getEntryFromInput()
	{
		//string a;
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
		string month;
		string day;
		string year;
		//cin.clear();
		cout << "Enter the first name: ";
		string fname;

		cin >> fname;
		getline(cin, fname);
		//cin.clear();
		cout << "Enter the last name: ";
		string lname;
		cin >> lname;
		getline(cin, lname);
		
		cout << "Enter the birth month: ";
		//cin >> month;
		getline(cin, month);
		cout << "Enter the day of birth: ";
		//cin >> day;
		getline(cin, day);
		cout << "Enter the year of birth: ";
		//cin >> year;
		getline(cin, year);
		cout << "Enter the street address: ";
		//cin >> address;
		getline(cin, address);
		cout << "Enter the city: ";
		//cin >> city;
		getline(cin, city);
		cout << "Enter the state: ";
		//cin >> state;
		getline(cin, state);
		cout << "Enter the zip: ";
		//cin >> zip;
		getline(cin, zip);
		cout << "Enter the phone: ";
		//cin >> phone;
		getline(cin, phone);
		cout << "Enter the relationship: ";
		//cin >> relationship;
		getline(cin, relationship);
		extPersonType record(fname, lname, stoi(month), stoi(day), stoi(year), address, city, state, stoi(zip), phone, relationship);
		addEntry(record);
		//return record;
	}

	void addEntry(extPersonType person) //adds an entry to the address bool
	{
		//cout << person.getLastName() << endl;
		this->insert(person);
		cout << "In addEntry (extPersonType person), in adressBookType.h, line 101"
			<< endl;

	}
	void findPerson(string lName) //finds an entry by last name
	{
		bool found = false;
		nodeType<extPersonType>* current; //pointer to traverse the list

		current = this->first;  //start the search at the first node
		//cout << current->info.getKey() << endl;
		while (current != nullptr && !found)
			if (current->info.getLastName() == lName)

			{
				found = true;
				current->info.print();
			}
			else
				current = current->link;

	}
	void findBirthdays(int bMonth) //finds an entry by birth month
	{
		nodeType<extPersonType>* current; //pointer to traverse the list

		current = this->first;  //start the search at the first node

		while (current != nullptr)
			if (current->info.getBirthMonth() == bMonth)
			{
				current->info.print();
				current = current->link;

			}
			else
				current = current->link;

		//return found;
	}
	void findRelations(string relationship) //finds an entry by relationship
	{
		nodeType<extPersonType>* current; //pointer to traverse the list

		current = this->first;  //start the search at the first node

		while (current != nullptr)
			if (current->info.getRelationship() == relationship)
			{
				current->info.print();
				current = current->link;

			}
			else
				current = current->link;

		//return found;
	}
	void print() //prints out the address book
	{
		nodeType<extPersonType>* current; //pointer to traverse the list
		//cout << first->info.getFirstName() << endl;
		current = first;    //set current so that it points to 
		//the first node
		//current = myAddressBook.begin();
		while (current != nullptr) //while more data to print
		{
			current->info.print();
			current = current->link;
		}
		cout << endl;
	}
	/*void sortEntries() //sorts the entries by last name 
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
		
	}*/

	//addressBookType() //default constructor
	//{
	//}

private:

/*	extPersonType addressList[500];
	int length;
	int maxLength; */
};

