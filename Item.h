#pragma once
#include <iostream>

using namespace std;

class Item
{
private:
	string type;
	string name;
	float price;
	int calories;
public:
	Item(string type, string name, float price, int calories);
	string toString();
};

