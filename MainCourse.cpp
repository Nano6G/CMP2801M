#include "MainCourse.h"
#include <string>
#include <iomanip>
#include <sstream>


using namespace std;

//Constructor to initialise and assign input variables to data members
MainCourse::MainCourse(string name, float price, int calories)
{
	this->type = 'm';
	this->name = name;
	this->price = price;
	this->calories = calories;
}

//Function to return the string containing the details of the item
string MainCourse::toString()
{
	//Sets the price's precision to remove trailing zeros
	stringstream roundedPrice;
	roundedPrice << fixed << setprecision(2) << price;

	string toReturn;

	//if tree to determine how many tabs the item should have after it's name - This ensures the menu looks presentable
	if (name.size() > 12)
	{
		toReturn = name + ": \t\x9C" + roundedPrice.str() + "   \t" + to_string(calories) + " cal";
	}
	else if (name.size() > 6)
	{
		toReturn = name + ": \t\t\x9C" + roundedPrice.str() + "   \t" + to_string(calories) + " cal";
	}
	else
	{
		toReturn = name + ": \t\t\t\x9C" + roundedPrice.str() + "   \t" + to_string(calories) + " cal";
	}
	
	return toReturn;
}


//Functions to return details of the object i.e. getters
char MainCourse::returnType()
{
	return type;
}

string MainCourse::returnName()
{
	return name;
}


float MainCourse::returnPrice()
{
	return price;
}