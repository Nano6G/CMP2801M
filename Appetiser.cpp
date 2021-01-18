#include "Appetiser.h"
#include <string>

using namespace std;


Appetiser::Appetiser(string name, float price, int calories, char shareable, char twoForOne)
{
	this->name = name;
	this->price = price;
	this->calories = calories;

	//fix
	this->shareable = shareable;
	this->twoForOne = twoForOne;
}

string Appetiser::toString()
{
	//cout << shareable << endl;
	//cout << twoForOne << endl;

	string toReturn;
	if (name.size() > 12)
	{
		toReturn = name + ": \t\t\x9C" + to_string(price) + "   \t" + to_string(calories) + " cal";
	}
	else if (name.size() > 6)
	{
		toReturn = name + ": \t\t\x9C" + to_string(price) + "   \t" + to_string(calories) + " cal";
	}
	else
	{
		toReturn = name + ": \t\t\t\x9C" + to_string(price) + "   \t" + to_string(calories) + " cal";
	}

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
