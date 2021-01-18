#pragma once
#include "Item.h"
class MainCourse :
	public Item
{
public:
	MainCourse(string name, float price, int calories);
	virtual string toString();
};

