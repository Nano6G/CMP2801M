#include "Beverage.h"
#include <string>
#include <iomanip>
#include <sstream>

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
	stringstream roundedPrice;
	roundedPrice << fixed << setprecision(2) << price;

	stringstream roundedABV;
	roundedABV << fixed << setprecision(1) << abv;

	string toReturn;
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