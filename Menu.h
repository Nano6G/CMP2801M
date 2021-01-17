#pragma once
#include "ItemList.h"
#include <iostream>

using namespace std;

class Menu :
	public ItemList
{
private:
	string filePath;
public:
	Menu(string filePath);
	void Load();
	string toString();
};

