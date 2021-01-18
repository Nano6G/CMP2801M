#pragma once
#include <iostream>
#include "Item.h"

class Appetiser :
	public Item
{
private:
	bool shareable;
	bool twoForOne;
public:
	Appetiser(string name, float price, int calories, char shareable, char twoForOne);
	virtual string toString();
};

