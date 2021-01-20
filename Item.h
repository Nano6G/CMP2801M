#pragma once
#include <iostream>
using namespace std;

class Item
{
	//Protected access so that derived objects will inherit the members
protected:
	//Defines the data members the derived classes will use
	char type;
	string name;
	float price;
	int calories;
public:
	//Defines the virtual functions which the derived classes will use
	virtual string toString();
	virtual char returnType();
	virtual string returnName();
	virtual bool returnTwoForOne();
	virtual float returnPrice();
};
