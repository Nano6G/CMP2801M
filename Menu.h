#pragma once
#include "ItemList.h"
#include <iostream>
#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
#include <vector>

using namespace std;

class Menu :
	public ItemList
{
private:
	string filePath;
	vector<Item*> items;
	
public:
	Menu(string filePath);
	void Load();
	string toString();
	void LoadAppetiser(vector<string> variables);
	void LoadMain(vector<string> variables);
	void LoadBeverage(vector<string> variables);
	vector<Item*> returnItemList();
};

