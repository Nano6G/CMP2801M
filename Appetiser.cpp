#include "Appetiser.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//Constructor to initialise and assign input variables to data members
Appetiser::Appetiser(string name, float price, int calories, char shareable, char twoForOne)
{
	this->type = 'a';
	this->name = name;
	this->price = price;
	this->calories = calories;
	this->shareable = shareable;
	this->twoForOne = twoForOne;
}

//Function to return the string containing the details of the item
string Appetiser::toString()
{
	//Sets the price's precision to remove trailing zeros
	stringstream roundedPrice;
	roundedPrice << fixed << setprecision(2) << price;

	string toReturn;

	//if tree to determine how many tabs the item should have after it's name - This ensures the menu looks presentable
	if (name.size() > 12)
	{
		toReturn = name + ": \t\t\x9C" + roundedPrice.str() + "   \t" + to_string(calories) + " cal";
	}
	else if (name.size() > 6)
	{
		toReturn = name + ": \t\t\x9C" + roundedPrice.str() + "   \t" + to_string(calories) + " cal";
	}
	else
	{
		toReturn = name + ": \t\t\t\x9C" + roundedPrice.str() + "   \t" + to_string(calories) + " cal";
	}

	//Adds shareable and/or 2-4-1 if the object is either
	if (shareable)
	{
		toReturn += "\t (shareable)";
	}
	if (twoForOne)
	{
		toReturn += "\t (2 for 1)";
	}

	return toReturn;
}

//Functions to return details of the object i.e. getters
char Appetiser::returnType()
{
	return type;
}

string Appetiser::returnName()
{
	return name;
}

bool Appetiser::returnTwoForOne()
{
	return twoForOne;
}

float Appetiser::returnPrice()
{
	return price;
}
