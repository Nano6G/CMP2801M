#include <iostream>
#include <sstream>
#include "Item.h"

using namespace std;

//Virtual function definitions that are required but will not be used
string Item::toString()
{
	return "toReturn";
}

char Item::returnType()
{
	return type;
}

string Item::returnName()
{
	return name;
}

bool Item::returnTwoForOne()
{
	return false;
}

float Item::returnPrice()
{
	return 0;
}
