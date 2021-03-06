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
	virtual char returnType();
	virtual string returnName();
	virtual bool returnTwoForOne();
	virtual float returnPrice();
};

