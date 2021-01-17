#pragma once
#include "ItemList.h"
#include <iostream>

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
};

