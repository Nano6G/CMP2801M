#pragma once
#include "ItemList.h"
#include <iostream>
#include "Item.h"

using namespace std;


class Order :
	public ItemList
{
private:
	int total;
public:
	int calculateTotal();
	string printReceipt();
	string toString();
	void add(Item* choice);
	void remove();
};

