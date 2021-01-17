#pragma once
#include <iostream>
#include "Item.h"

class Appetiser :
	public Item
{
private:
	bool shareable;
	bool twoForOne;
};

