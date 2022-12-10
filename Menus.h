#pragma once
#include<iostream>
using namespace std;

class Menus
{

public:
	void displaymainmenu()
	{
		system("CLS");
		system("color 5F");
		cout << endl;
		cout << endl;
		cout << "                                         *******************************************" << endl;
		cout << "                                         *                                         *" << endl;
		cout << "                                         *            WELCOME TO DSDB!             *" << endl;
		cout << "                                         *                                         *" << endl;
		cout << "                                         *******************************************" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				 ________________________ Main Menu ___________________ " << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Creation                                       |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Searching                                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Updation                                       |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    4. Deletion                                       |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    5. Exit DSDB                                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    6. Run Query                                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|______________________________________________________|" << endl;
	}

	void displayCreationmenu()
	{
		system("CLS");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                              ---------------------  CREATION PAGE  ---------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				 _______________________ Creation _____________________ " << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Creation through AVL                           |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Creation through B-Tree                        |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Creation through RnB-Tree                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    4. Go back to previous menu                       |" << endl;
		cout << "				|______________________________________________________|" << endl;
	}

	void displayCreationOptions(int treeType)
	{
		system("CLS");
		if (treeType == 1) {
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "                              ---------------------  AVL-TREE CREATION  ---------------------" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "				 ____________________ Search Menu _____________________ " << endl;
			cout << "				|                                                      |" << endl;
			cout << "				|    1. Point Searching                                |" << endl;
			cout << "				|                                                      |" << endl;
			cout << "				|    2. Range Searching                                |" << endl;
			cout << "				|                                                      |" << endl;
			cout << "				|    3. Go back to previous menu                       |" << endl;
			cout << "				|______________________________________________________|" << endl;
		} else if (treeType == 2) {
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "                              ---------------------  B-TREE CREATION  ---------------------" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "				 ____________________ Search Menu _____________________ " << endl;
			cout << "				|                                                      |" << endl;
			cout << "				|    1. Point Searching                                |" << endl;
			cout << "				|                                                      |" << endl;
			cout << "				|    2. Range Searching                                |" << endl;
			cout << "				|                                                      |" << endl;
			cout << "				|    3. Go back to previous menu                       |" << endl;
			cout << "				|______________________________________________________|" << endl;

		} else if (treeType == 3) {
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "                              ---------------------  RNB-TREE CREATION  ---------------------" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "				 ____________________ Search Menu _____________________ " << endl;
			cout << "				|                                                      |" << endl;
			cout << "				|    1. Point Searching                                |" << endl;
			cout << "				|                                                      |" << endl;
			cout << "				|    2. Range Searching                                |" << endl;
			cout << "				|                                                      |" << endl;
			cout << "				|    3. Go back to previous menu                       |" << endl;
			cout << "				|______________________________________________________|" << endl;
		}

	}

	void displaySearchingmenu()
	{
		system("CLS");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                              ---------------------  SEARCH PAGE  ---------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				 ____________________ Search Menu _____________________ " << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Point Searching                                |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Range Searching                                |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Go back to previous menu                       |" << endl;
		cout << "				|______________________________________________________|" << endl;


	}

	void displayPointSearchingmenu()
	{
		system("CLS");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                              ---------------------  POINT SEARCH PAGE  -------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				 ___________________ Point Search Menu ________________ " << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Search by year of deaths.                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Search by cause of deaths.                     |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Search by State of deaths.                     |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    4. Search by number of deaths.                    |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    5. Search by death rate.         	               |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    6. Go back to previous menu                       |" << endl;
		cout << "				|______________________________________________________|" << endl;
	}

	void displayRangeSearchingmenu()
	{
		system("CLS");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                               ---------------------  RANGE SEARCH PAGE  -------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				 ___________________ Range Search Menu ________________ " << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Search by year of deaths.                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Search by cause of deaths.                     |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Search by State of deaths.                     |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    4. Search by number of deaths.                    |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    5. Search by death rate.       	               |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    6. Go back to previous menu                       |" << endl;
		cout << "				|______________________________________________________|" << endl;
	}

	void displayUpationmenu()
	{
		system("CLS");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                              ---------------------  UPDATION PAGE  -------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				 ____________________ Updation Menu ___________________" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Update existing tuple                          |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Insert new tuple.                              |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Go back to previous menu                       |" << endl;
		cout << "				|______________________________________________________|" << endl;


	}
};