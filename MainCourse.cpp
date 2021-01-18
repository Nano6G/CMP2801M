#include "MainCourse.h"
#include <string>


using namespace std;

MainCourse::MainCourse(string name, float price, int calories)
{
	this->name = name;
	this->price = price;
	this->calories = calories;
}

string MainCourse::toString()
{
	string toReturn;
	if (name.size() > 12)
	{
		toReturn = name + ": \t\x9C" + to_string(price) + "   \t" + to_string(calories) + " cal";
	}
	else if (name.size() > 6)
	{
		toReturn = name + ": \t\t\x9C" + to_string(price) + "   \t" + to_string(calories) + " cal";
	}
	else
	{
		toReturn = name + ": \t\t\t\x9C" + to_string(price) + "   \t" + to_string(calories) + " cal";
	}
	
	return toReturn;
}