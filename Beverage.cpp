#include "Beverage.h"
#include <string>

using namespace std;


Beverage::Beverage(string name, float price, int calories, int volume, float abv)
{
	this->name = name;
	this->price = price;
	this->calories = calories;
	this->volume = volume;
	this->abv = abv;
}

bool Beverage::isAlcoholic()
{
	return alcoholic;
}

string Beverage::toString()
{
	string toReturn;
	if (name.size() > 12)
	{
		toReturn = name + ": \t\x9C" + to_string(price) + "   \t" + to_string(calories) + " cal\t(" + to_string(volume) + "ml, " + to_string(abv) + "% abv)";
	}
	else if (name.size() > 8)
	{
		toReturn = name + ": \t\t\x9C" + to_string(price) + "   \t" + to_string(calories) + " cal\t(" + to_string(volume) + "ml, " + to_string(abv) + "% abv)";
	}
	else
	{
		toReturn = name + ": \t\t\t\x9C" + to_string(price) + "   \t" + to_string(calories) + " cal\t(" + to_string(volume) + "ml, " + to_string(abv) + "% abv)";
	}

	return toReturn;
}