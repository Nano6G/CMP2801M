/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");
	menu.Load();

	// Create an order object
	Order order = Order();
	
	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			//Uses the menu's toString function to display it to the user
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			//Cuts the users' input down to just the number they wish to add to the order
			string numberOfItem = userCommand.substr(4);

			//Gets the vector of items on the menu using the self explainatory menu function
			vector<Item*> listOfItems = menu.returnItemList();

			//Exception handling in case the user tries to add multiple products
			if (numberOfItem.size() > 2)
			{
				cout << "Only one item can be added at a time, please try again.\n";
			}
			else
			{
				//Exception handling to ensure the number the user enters is part of the menu
				try
				{
					//Changes the user input into the index of the item in the vector
					int correctedIndex = stoi(numberOfItem) - 1;

					//Checks there is an item at the index (for exception handling)
					listOfItems.at(correctedIndex);

					//Retrives the pointer to the item of the users' choice
					Item* choice = listOfItems[correctedIndex];

					//Calls the add function in the order class to add the item to the order
					order.add(choice);

					//Informs the user of the addition to the order
					cout << choice->returnName() << " added to order.\n";
				}
				catch(const out_of_range & oor)
				{
					//Informs the user the number they entered is invalid
					cout << "Please enter a valid number from the menu.\n";
				}
			}
		}
		else if (command.compare("remove") == 0)
		{
			//Remove function uses similar code base to add function
			string numberOfItem = userCommand.substr(7);

			vector<Item*> listOfItems = order.returnItemsSelected();
			if (numberOfItem.size() > 8)
			{
				cout << "Only one item can be removed at a time, please try again.\n";
			}
			else
			{
				try
				{
					int correctedIndex = stoi(numberOfItem) - 1;
					listOfItems.at(correctedIndex);
					//Passes the index of the item rather than a pointer to the item itself
					order.remove(correctedIndex);
					cout << "Item removed from order.\n";
				}
				catch (const out_of_range & oor)
				{
					cout << "Please enter a valid number from the current order.\n";
				}
			}
		}
		else if (command.compare("checkout") == 0)
		{
			if (order.returnItemsSelected().size() > 0)
			{
				//Prints the order to the user
				cout << order.toString();

				//Asks for confirmation on whether to make the order
				cout << "\nDo you want to place your order?\n('y' to confirm/'n' to go back and modify order)\n";
				string confirmation;


				while (confirmation != "y" & confirmation != "n")
				{
					//Gets the users' input
					istream& s = getline(cin, confirmation);

					if (confirmation == "y")
					{
						//Prints the receipt and pauses the program until the user is ready to exit
						order.printReceipt();
						system("pause");
						return 0;
					}
					else if (confirmation == "n")
					{
						cout << "Continue using commands to amend your order until ready to checkout" << endl;
					}
					//Exception handling in case the user doesn't enter y or n
					else
					{
						cout << "Please enter 'y' to confirm your order or 'n' to amend it" << endl;
					}
				}
			}
			//Exception handling in case the user tries to proceed to checkout with no items selected
			else
			{
				cout << "Please add items to your order before progressing to the checkout" << endl;
			}
		}
		else if (command.compare("help") == 0)
		{
			//Prints the commands to the user
			cout << "\nThe following commands can be used:" << endl;
			cout << "menu \t\t Displays the menu" << endl;
			cout << "add [number] \t Adds the specified item to the order" << endl;
			cout << "remove [number]  Removes the specified item from the order" << endl;
			cout << "checkout \t Displays the current order and allows the confirmation of it" << endl;
			cout << "help \t\t Displays this menu of commands" << endl;
			cout << "exit \t\t Exits the program\n" << endl;
		}

		parameters.clear();

	}
	
	cout << "Press any key to quit...";
	std::getchar();

}