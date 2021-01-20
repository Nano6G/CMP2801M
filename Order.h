#pragma once
#include "ItemList.h"
#include <iostream>
#include "Item.h"
#include "Menu.h"

using namespace std;


class Order :
	public ItemList
{
private:
	float total;
	float savings;
public:
	void calculateTotal();
	void printReceipt();
	string toString();
	void add(Item* choice);
	void remove(int indexToRemove);
	vector<Item*> returnItemsSelected();
};

