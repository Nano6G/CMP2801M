#include <iostream>
#include <sstream>
#include "Item.h"

using namespace std;

/*Item::Item(string name, float price, int calories)
{
	this->name = name;
	this->price = price;
	this->calories = calories;
	cout << "Item object created" << endl;
}
*/
string Item::toString()
{
	return "Item details:\nName: " + name + "\nPrice: " + to_string(price) + "\nCalories: " + to_string(calories);
}
