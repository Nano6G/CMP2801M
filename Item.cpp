#include <iostream>
#include <sstream>
#include "Item.h"

using namespace std;

Item::Item(string type, string name, float price, int calories)
{
	this->type = type;
	this->name = name;
	this->price = price;
	this->calories = calories;
	cout << "Item object created" << endl;

}
string Item::toString()
{
	return "Item details:\nType: " + type + "\nName: " + name + "\nPrice: " + to_string(price) + "\nCalories: " + to_string(calories);
}
