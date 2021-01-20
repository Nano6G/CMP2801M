#include "Beverage.h"
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

//Constructor to initialise and assign input variables to data members
Beverage::Beverage(string name, float price, int calories, int volume, float abv)
{
	this->type = 'b';
	this->name = name;
	this->price = price;
	this->calories = calories;
	this->volume = volume;
	this->abv = abv;
}

//Function to return the string containing the details of the item
string Beverage::toString()
{
	//Sets the price's precision to remove trailing zeros
	stringstream roundedPrice;
	roundedPrice << fixed << setprecision(2) << price;

	//Sets the abv's precision to remove trailing zeros
	stringstream roundedABV;
	roundedABV << fixed << setprecision(1) << abv;

	string toReturn;

	//if tree to determine how many tabs the item should have after it's name - This ensures the menu looks presentable
	if (name.size() > 12)
	{
		toReturn = name + ": \t\x9C" + roundedPrice.str() + "   \t" + to_string(calories) + " cal\t (" + to_string(volume) + "ml";
	}
	else if (name.size() > 8)
	{
		toReturn = name + ": \t\t\x9C" + roundedPrice.str() + "   \t" + to_string(calories) + " cal\t (" + to_string(volume) + "ml";
	}
	else
	{
		toReturn = name + ": \t\t\t\x9C" + roundedPrice.str() + "   \t" + to_string(calories) + " cal\t (" + to_string(volume) + "ml";
	}

	//Adds the abv if the drink is alcoholic
	if (abv > 0)
	{
		toReturn += ", " + roundedABV.str() + "% abv)";
	}
	else
	{
		toReturn += ")";
	}

	return toReturn;
}

//Functions to return details of the object i.e. getters
bool Beverage::isAlcoholic()
{
	return alcoholic;
}

char Beverage::returnType()
{
	return type;
}

string Beverage::returnName()
{
	return name;
}

float Beverage::returnPrice()
{
	return price;
}