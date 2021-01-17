#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(string filePath)
{
	this->filePath = filePath;
}

void Menu::Load()
{
	//Code to read CSV file at path and create objects of items
}

string Menu::toString()
{
	return "test";
}
