#pragma once
#include "Item.h"
#include <vector>

using namespace std;

class ItemList
{
protected:
	//Instaces of Item class stored by reference as a vector of pointers
	vector<Item*> itemsSelected;
public:
};

