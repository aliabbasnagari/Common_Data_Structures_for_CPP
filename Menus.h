#pragma once
#include<iostream>
using namespace std;

class Menus
{

public:
	void displaymainmenu()
	{
		system("color 5F");
		cout << endl;
		cout << endl;
		cout << "                                         *******************************************" << endl;
		cout << "                                         *                                         *" << endl;
		cout << "                                         *            WELCOME TO DSDB!		   *" << endl;
		cout << "                                         *                                         *" << endl;
		cout << "                                         *******************************************" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				________________________ Main Menu ____________________ " << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Creation                                       |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Searching                                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Updation                                       |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    4. Deletion	                               |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    5. Exit DSDB                                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|______________________________________________________|" << endl;
	}

	void displayCreationmenu()
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                              ---------------------  CREATION PAGE  ---------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				________________________ Creation ______________________ " << endl;
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

	void displaySearchingmenu()
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                              ---------------------  SEARCH PAGE  ---------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				_____________________ Search Menu ______________________ " << endl;
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
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                              ---------------------  POINT SEARCH PAGE  -------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				____________________ Point Search Menu _________________ " << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Search by year of deaths.                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Search by cause of deaths.                     |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Search by State of deaths.                     |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    4. Search by number of deaths.                    |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    5. Search by death rate.		               |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    6. Go back to previous menu                       |" << endl;
		cout << "				|______________________________________________________|" << endl;
	}

	void displayRangeSearchingmenu()
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                               ---------------------  RANGE SEARCH PAGE  -------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				____________________ Range Search Menu _________________ " << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Search by year of deaths.                      |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Search by cause of deaths.                     |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Search by State of deaths.                     |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    4. Search by number of deaths.                    |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    5. Search by death rate.		               |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    6. Go back to previous menu                       |" << endl;
		cout << "				|______________________________________________________|" << endl;
	}

	void displayUpationmenu()
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                              ---------------------  UPDATION PAGE  -------------------" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "				_____________________ Updation Menu ____________________ " << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    1. Update existing tuple                          |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    2. Insert new tuple.                              |" << endl;
		cout << "				|                                                      |" << endl;
		cout << "				|    3. Go back to previous menu                       |" << endl;
		cout << "				|______________________________________________________|" << endl;


	}
};