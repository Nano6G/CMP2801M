#include "Order.h"
#include <iostream>
#include "Item.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;


void Order::calculateTotal()
{
	//Initialises values to 0 so that if the user views the checkout multiple times, they don't keep increasing
	int twoForOnes = 0;
	total = 0;
	savings = 0;

	//Loop to iterate over selected items and add each items price to the total
	for (int i = 0; i < itemsSelected.size(); i++)
	{
		float priceOfItem = itemsSelected[i]->returnPrice();
		//Determines whether two for one offer should be applied and applies it if so
		if (itemsSelected[i]->returnTwoForOne())
		{
			twoForOnes++;
			if (twoForOnes % 2 == 0)
			{
				//Applies the discount and adds the discount to savings variable
				total -= priceOfItem;
				savings += priceOfItem;
			}
		}
		total += priceOfItem;
	}
}

void Order::printReceipt()
{
	//Loads the text file
	ofstream receiptFile("receipt.txt");
	//Writes the order details to the text file using the toString subroutine
	receiptFile << toString();
	receiptFile.close();

	//Informs the user of the receipt being saved
	cout << "\nReceipt saved as receipt.txt\n" << endl;
}

void Order::add(Item* choice)
{
	//Adds the selected item to the vector using the passed item pointer
	itemsSelected.push_back(choice);
}

void Order::remove(int indexToRemove)
{
	//Removes the selected item from the vector using the passed index
	itemsSelected.erase(itemsSelected.begin() + indexToRemove);
}

string Order::toString()
{
	calculateTotal();
	//Sets the savings and totals precision to remove trailing zeros
	stringstream roundedSavings;
	stringstream roundedTotal;
	roundedSavings << fixed << setprecision(2) << savings;
	roundedTotal << fixed << setprecision(2) << total;

	string order;

	//Adds the order details to the string to be returned
	order += "------------------------------\tOrder\t--------------------------------------\n";

	//Iterates over the selected items vector and adds each item's details to the string
	for (int i = 0; i < itemsSelected.size(); i++)
	{
		order += "(" + to_string(i + 1) + ") ";
		order += itemsSelected[i]->toString();
		order += "\n";
	}

	order += "------------------------------------------------------------------------------\n";
	
	//Displays the users' savings if there is any
	if (savings > 0)
	{
		order += "\nTwo for one discount applied.";
		order += "\nSavings: \x9C" + roundedSavings.str() + "\n";
	}

	//Displays the rounded total to the user
	order += "Total: \x9C" + roundedTotal.str() + "\n";

	return order;
}

//Subroutine to return the items the user has selected
vector<Item*> Order::returnItemsSelected()
{
	return itemsSelected;
}
