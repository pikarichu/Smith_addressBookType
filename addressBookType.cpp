// addressBookType.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "addressBookType.h"
#include "addressType.h"
#include "dateType.h"
#include "personType.h"
#include "extPersonType.h"



string prompt = "Enter a number";

void getInput(addressBookType book)
{
    string person;
    int month = 0;
    //Capture Keystroke as int a
    int a = 0;



    do {
        cout << endl
            << "1: Print all entries" << endl
            << "2: Find person by last name" << endl
            << "3: Show entries by birth month" << endl
            << "4: Show entries by relationship" << endl
            << "5: Enter a new record" << endl
            << "6: Delete a record" << endl
            << "7: Quit" << endl;

            extPersonType temp;
            cin >> a;

            switch (a)
            {
                //Case
            case 1: //Print everybody
                book.print();
                //case 2
                break;
            case 2: //Print by last name
                cout << "Enter the last name: ";
                cin >> person;
                book.findPerson(person);
                break;
            case 3: //Print by birth month
                cout << "Enter the birth month: ";
                cin >> month;
                book.findBirthdays(month);
                break;
            case 4: //Print by relationship
                cout << "Enter the relationship: ";
                cin >> person;
                book.findRelations(person);
                break;
            case 5: //Print by relationship
                cout << "Enter the new address book record: ";
                book.getEntryFromInput();
                //temp = book.getEntryFromInput();
                //book.addEntry(temp);
                //book.addEntry(book.getEntryFromInput());
                break;
            case 6: //Print by relationship
                cout << "Enter the full name of the address book record to DELETE: ";
                //book.getEntryFromInput();
                break;
            case 7: //Quit
                break;
            default: //Any non-valid choice
                cout << "Invalid Choice";
            }
        } while (a != 7); //while quit is not selected
}


int main()
{
    addressBookType mainAddressBook;
    mainAddressBook.initEntry("AddressBookData.txt");  //Initialize the address book
    

    getInput(mainAddressBook); //Runs the client program

}