#pragma once
#include <iostream>

using namespace std;

class Item
{
protected:
	string name;
	float price;
	int calories;
public:
	virtual string toString();
};

