#pragma once
#include "Item.h"
class Beverage :
	public Item
{
private:
	float abv;
	int volume;
	bool alcoholic;
public:
	Beverage(string name, float price, int calories, int volume, float abv);
	bool isAlcoholic();
	string toString();
};

