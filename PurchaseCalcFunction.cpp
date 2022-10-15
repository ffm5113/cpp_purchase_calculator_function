// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++: From control structures through objects. Pearson. 
//
// https://docs.microsoft.com/en-us/troubleshoot/developer/visualstudio/cpp/libraries/stl-sqrt-pow-functions
// https://docs.microsoft.com/en-us/cpp/standard-library/iomanip-functions?view=msvc-170
// https://www.geeksforgeeks.org/stdsetbase-stdsetw-stdsetfill-in-cpp/

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw for output width
#include <string>   // To utilize to_string & length functions
using namespace std;

// Constant Variable Initialization
const string TITLE = "Purchase Calculator Function Program";
const string AUTHOR_LINE = "By Forrest Moulin";
const string TABLE_TITLE = "Forrest Green Shopping Center";

// Function prototypes to notify compiler
double calcPurchPrice(int items, double costPer);
void promptUser();

int main()
{
	// Dynamic Variable Initialization
	int numItems, purchId = 1, sumItems = 0;
	int tableWidth = 0, col1Width = 30, col2Width;
	double pricePerItem, purchaseCost, maxPurchase; 
	double sumPurchases = 0, avgPricePerPurch;
	char continueChar = NULL;
	string tableDivider = "-";

	cout << fixed << setprecision(2) << TITLE << endl
		<< AUTHOR_LINE << endl;

	// Program Logic
	promptUser();
	cin >> numItems >> pricePerItem;
	purchaseCost = calcPurchPrice(numItems, pricePerItem);

	// First purchase will always start as max
	maxPurchase = purchaseCost;
	// Add items to sum var
	sumItems += numItems;
	// Add purch cost to sum var
	sumPurchases += purchaseCost;

	cout << "Purchase # " << purchId << " total: $" << purchaseCost 
		<< endl << endl;

	while (continueChar != 'n'
		|| continueChar != toupper('n'))
	{
		cout << "Would you like to make another purchase?"
			<< endl << "Please enter Y for yes or N for no."
			<< endl << endl;
		cin >> continueChar;
		if (continueChar == 'y'
			|| continueChar == toupper('y'))
		{
			promptUser();
			cin >> numItems >> pricePerItem;
			purchaseCost = calcPurchPrice(numItems, pricePerItem);
			
			if (purchaseCost > maxPurchase)
			{
				// Set new max price
				maxPurchase = purchaseCost;
			}

			sumItems += numItems;
			purchId++;
			cout << "Purchase # " << purchId << " total: $" << purchaseCost
				<< endl << endl;
			sumPurchases += purchaseCost;
		}
		else if (continueChar == 'n'
			|| continueChar == toupper('n'))
		{
			break;
		}
		else
		{
			cout << "Invalid entry. Please enter y for yes or n for no."
				<< endl << endl;
		}
	}

	// Adjust column width to fit calculated value
	col2Width = to_string(sumPurchases).length() - 3;
	tableWidth = col1Width + col2Width + 1;

	int titleW = (tableWidth - TABLE_TITLE.length()) / 2 + TABLE_TITLE.length();
	
	avgPricePerPurch = sumPurchases / purchId;
	cout << endl << right << setw(titleW)
		<< TABLE_TITLE << endl
		// Table divider
		<< setw(tableWidth) << setfill('-') << ""
		// Reset fill to blank space
		<< endl << left << setw(col1Width) << setfill(' ')
		<< "Total number of items:" << sumItems
		<< endl << left << setw(col1Width)
		<< "Total number of purchases:" << purchId 
		<< endl << left << setw(col1Width)
		<< "Total spent on purchases:" << "$" 
		<< right << setw(col2Width) << sumPurchases
		<< endl << left << setw(col1Width)
		<< "Average cost per purchase:" << "$" 
		<< right << setw(col2Width) << avgPricePerPurch
		<< endl << endl << "Thank you for shopping with us!" 
		<< endl << "Until next time :)" << endl;
}

// Function definition with param types/names
double calcPurchPrice(int items, double costPer)
{
	// Calculate and return the product of args
	return items * costPer;
}

// Void function w/o params
void promptUser()
{
	cout << endl << "Please enter the number of items (int)"
		<< endl << "and price per item (double without $),"
		<< endl << "separated by a space." << endl << endl;
}

/*
* CONSOLE OUTPUT
* Purchase Calculator Function Program
* By Forrest Moulin
*
* Please enter the number of items (int)
* and price per item (double without $),
* separated by a space.
*
* 10 2.50
* Purchase # 1 total: $25.00
*
* Would you like to make another purchase?
* Please enter Y for yes or N for no.
*
* y
*
* Please enter the number of items (int)
* and price per item (double without $),
* separated by a space.
*
* 4 6.75
* Purchase # 2 total: $27.00
*
* Would you like to make another purchase?
* Please enter Y for yes or N for no.
*
* y
*
* Please enter the number of items (int)
* and price per item (double without $),
* separated by a space.
*
* 21 33.33
* Purchase # 3 total: $699.93
*
* Would you like to make another purchase?
* Please enter Y for yes or N for no.
*
* n
*
*     Forrest Green Shopping Center
* --------------------------------------
* Total number of items:        35
* Total spent on purchases:     $ 751.93
* Average cost per purchase:    $ 250.64
*
* Thank you for shopping with us!
* Until next time :)
*/
