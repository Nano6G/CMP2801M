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
	//Item(string name, float price, int calories);
	string toString();
};

