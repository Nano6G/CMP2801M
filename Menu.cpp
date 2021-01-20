#include "Menu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>
#include <string>
#include "MainCourse.h"
#include "Appetiser.h"
#include "Beverage.h"
#include <iomanip>

using namespace std;

//Constructor uses passed string to set the filepath of the menu
Menu::Menu(string filePath)
{
	this->filePath = filePath;
}

void Menu::Load()
{
	//Code to read CSV file at path and create objects of items

	//Opens the menu file at the given path
	ifstream menuFile(filePath);

	string line;

	//Reads each line of the menu file
	while (getline(menuFile, line))
	{

		stringstream ss(line);
		vector<string> variables;

		while (ss.good())
		{
			string substring;
			//Splits the line by commas
			getline(ss, substring, ',');
			if (substring.size() > 0) //Proceeds only if there is a value between the commas
			{
				//Adds the values to the variables vector
				variables.push_back(substring);
			}
		}

		//Determines the type of item and calls the respective function
		if (line[0] == 'a')
		{
			LoadAppetiser(variables);
		}

		if (line[0] == 'm')
		{
			LoadMain(variables);
		}

		if (line[0] == 'b')
		{
			LoadBeverage(variables);
		}
	}

}

/*Set of subroutines which all follow a similar structure, but are tailored to what type of item they are working with
They use the passed in variables to create a pointer to a new object of their respective class and push back the pointer to the items vector*/
void Menu::LoadAppetiser(vector<string> variables)
{
	//Appetiser function converts string to bool, a more appropriate data type
	bool shareable = false;
	if (variables[4] == "y")
	{
		shareable = true;
	}

	bool twoForOne = false;
	if (variables[5] == "y")
	{
		twoForOne = true;
	}

	Appetiser* ptr = new Appetiser(variables[1], stof(variables[2]), stoi(variables[3]), shareable, twoForOne);
	items.push_back(ptr);
}

void Menu::LoadMain(vector<string> variables)
{
	MainCourse* ptr = new MainCourse(variables[1], stof(variables[2]), stoi(variables[3]));
	items.push_back(ptr);
}

void Menu::LoadBeverage(vector<string> variables)
{
	Beverage* ptr = new Beverage(variables[1], stof(variables[2]), stoi(variables[3]), stoi(variables[4]), stof(variables[5]));
	items.push_back(ptr);
}

vector<Item*> Menu::returnItemList()
{
	return items;
}

//Function to return the string containing the details of each item on the menu
string Menu::toString()
{
	string menu;
	int count = 1;

	int totalAppetisers = 0;
	int totalMainCourses = 0;
	int totalBeverages = 0;

	//Iterates over the items vector to add each items details to the string
	for (int i = 0; i < items.size(); i++)
	{
		//if tree to display headers for each type of item
		if (items[i]->returnType() == 'a')
		{
			if (totalAppetisers == 0)
			{
				menu += "\n------------------------------\tAppetisers\t------------------------------";
			}
			totalAppetisers++;
		}
		if (items[i]->returnType() == 'm')
		{
			if (totalMainCourses == 0)
			{
				menu += "\n\n------------------------------\tMain Dishes\t------------------------------";
			}
			totalMainCourses++;
		}
		if (items[i]->returnType() == 'b')
		{
			if (totalBeverages == 0)
			{
				menu += "\n\n------------------------------\tBeverages\t------------------------------";
			}
			totalBeverages++;
		}

		menu += "\n(" + to_string(i+1) + ") ";
		menu += items[i]->toString();
	}

	menu += "\n\n";

	return menu;
}
