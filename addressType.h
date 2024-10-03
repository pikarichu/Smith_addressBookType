
#include <iostream>
using namespace std;
#pragma once
#ifndef H_addressType
#define H_addressType

class addressType
{
public:
	void setAddress(string a) //sets the address
	{
		address = a;
	}

	void setCity(string c) //sets the city
	{
		city = c;
	}

	void setState(string s) //sets the state, defaults to XX
	{
		if (s.length() != 2)
		{
			state = "XX";
		}
		else
		{
			state = s;
		}
	}

	void setZipcode(int z) //sets the zip code between 11111 and 99999, defaults to 10000
	{
		if (z <= 99999 && z >= 11111)
		{
			zipcode = z;
		}
		else
		{
			zipcode = 10000;
		}
	}


	string getAddress() //returns the address value
	{
		return address;
	}

	string getCity() //returns the city value
	{
		return city;
	}

	string getState() //returns the state value
	{
		return state;
	}

	int getZipcode() //returns the zip code
	{
		return zipcode;
	}


	void print() //prints the data out
	{
		cout << this->address << endl << this->city << " " << this->state << ", " << this->zipcode << endl;
	}

	// Default Constructor
	addressType()
	{
		setAddress("");
		setCity("");
		setState("XX");
		setZipcode(10000);
	}

	// Constructor
	addressType(string a, string c, string s, int z)
	{
		setAddress(a);
		setCity(c);
		setState(s);
		setZipcode(z);
	}

private:
	string address;
	string city;
	string state;
	int zipcode;
};

#endif
