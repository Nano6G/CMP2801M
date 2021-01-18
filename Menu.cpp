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

Menu::Menu(string filePath)
{
	this->filePath = filePath;
}

void Menu::Load()
{
	//Code to read CSV file at path and create objects of items

	ifstream menuFile(filePath);

	string line;
	string CSvariables;

	while (getline(menuFile, line))
	{
		CSvariables = line.substr(2);

		stringstream ss(line);
		vector<string> variables;

		while (ss.good())
		{
			string substring;
			getline(ss, substring, ',');
			if (substring.size() > 0)
			{
				variables.push_back(substring);
			}
		}

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

void Menu::LoadAppetiser(vector<string> variables)
{
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

	items.push_back(new Appetiser(variables[1], stof(variables[2]), stoi(variables[3]), shareable, twoForOne));
}

void Menu::LoadMain(vector<string> variables)
{
	items.push_back(new MainCourse(variables[1], stof(variables[2]), stoi(variables[3])));
}

void Menu::LoadBeverage(vector<string> variables)
{
	//Beverage* ptr;
	//ptr = &Beverage(variables[1], stof(variables[2]), stoi(variables[3]), stoi(variables[4]), stof(variables[5]));
	//items.push_back(ptr);
	items.push_back(new Beverage(variables[1], stof(variables[2]), stoi(variables[3]), stoi(variables[4]), stof(variables[5])));
}

string Menu::toString()
{
	string menu;
	int count = 1;

	int totalAppetisers = 0;
	int totalMainCourses = 0;
	int totalBeverages = 0;


	for (int i = 0; i < items.size(); i++)
	{
		menu += "\n(" + to_string(i+1) + ") ";
		menu += items[i]->toString();
	}

	/*
	menu += "\n------------------------------\tAppetisers\t------------------------------";
	for (int i = 0; i < appetisers.size(); i++)
	{
		menu += "\n(" + to_string(count) + ") ";
		menu += appetisers[i]->toString();
		count++;
	}

	menu += "\n\n------------------------------\tMain Dishes\t------------------------------";
	for (int i = 0; i < mainCourses.size(); i++)
	{
		menu += "\n(" + to_string(count) + ") ";
		menu += mainCourses[i]->toString();
		count++;
	}

	menu += "\n\n------------------------------\tBeverages\t------------------------------";
	for (int i = 0; i < beverages.size(); i++)
	{
		menu += "\n(" + to_string(count) + ") ";
		menu += beverages[i]->toString();
		count++;
	}
	*/

	menu += "\n\n";

	return menu;
}
