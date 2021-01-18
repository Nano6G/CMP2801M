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

	appetisers.push_back(new Appetiser(variables[1], stof(variables[2]), stoi(variables[3]), shareable, twoForOne));
}

void Menu::LoadMain(vector<string> variables)
{
	mainCourses.push_back(new MainCourse(variables[1], stof(variables[2]), stoi(variables[3])));
}

void Menu::LoadBeverage(vector<string> variables)
{
	beverages.push_back(new Beverage(variables[1], stof(variables[2]), stoi(variables[3]), stoi(variables[4]), stof(variables[5])));
}

string Menu::toString()
{
	string menu;
	int count = 1;
	for (int i = 0; i < appetisers.size(); i++)
	{
		menu += "\n(" + to_string(count) + ") ";
		menu += appetisers[i]->toString();
		count++;
	}

	for (int i = 0; i < mainCourses.size(); i++)
	{
		menu += "\n(" + to_string(count) + ") ";
		menu += mainCourses[i]->toString();
		count++;
	}

	for (int i = 0; i < beverages.size(); i++)
	{
		menu += "\n(" + to_string(count) + ") ";
		menu += beverages[i]->toString();
		count++;
	}

	return menu;
}
