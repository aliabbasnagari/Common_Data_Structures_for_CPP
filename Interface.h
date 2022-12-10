#pragma once
#include "Utils.h"
#include "RedBlackTree.h"
#include "BinarySearchTree.h"
#include "Header.h"
#include "Utils.h"
#include "Menus.h"

#include<chrono>
#include<thread>
#include<iostream>
using namespace std;

class Interface
{

public:
	void MainInterface()
	{
		bool outerflag = true, innerflag = true;
		int choice, c;
		Menus m;

		while (outerflag)
		{
			choice = 0; c = 0; outerflag = true; innerflag = true;
			m.displaymainmenu();

			cout << endl;
			cout << "\nEnter your choice: ";
			cin >> choice;


			switch (choice)
			{

			case 1: //Creation

				while (innerflag)
				{

					cout << endl;
					cout << endl;
					cout << "                                                        LOADING...              " << endl;
					cout << endl;
					cout << endl;

					using namespace std::this_thread; // for putting a delay
					using namespace std::chrono;
					sleep_for(seconds(1));

					m.displayCreationmenu();

					cout << endl;
					cout << "\nEnter your choice: ";
					cin >> c;

					cout << endl;
					cout << endl;
					cout << "                                                        LOADING...              " << endl;
					cout << endl;
					cout << endl;

					using namespace std::this_thread; // for putting a delay
					using namespace std::chrono;
					sleep_for(seconds(1));


					if (c == 1) //creation through AVL
					{

						//creation through AVL
						innerflag = false;
					}
					else if (c == 2) //creation through B-TREE
					{
						//creation through B-TREE
						innerflag = false;
					}
					else if (c == 3) //creation through RnB TREE
					{
						//creation through RnB TREE
						innerflag = false;
					}
					else if (c == 4) //Go back to prev menu
					{
						//Go back to prev menu
						break;
						innerflag = false;
					}
					else
					{
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "                           -------------------  WRONG INPUT!  -------------------" << endl;
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}
				break;

			case 2: //Searching
				while (innerflag)
				{

					cout << endl;
					cout << endl;
					cout << "                                                        LOADING...              " << endl;
					cout << endl;
					cout << endl;

					using namespace std::this_thread; // for putting a delay
					using namespace std::chrono;
					sleep_for(seconds(1));

					m.displaySearchingmenu();

					cout << endl;
					cout << "\nEnter your choice: ";
					cin >> c;


					cout << endl;
					cout << endl;
					cout << "                                                        LOADING...              " << endl;
					cout << endl;
					cout << endl;

					using namespace std::this_thread; // for putting a delay
					using namespace std::chrono;
					sleep_for(seconds(1));

					if (c == 1) //Point search
					{
						m.displayPointSearchingmenu();

						cout << endl;
						cout << "\nEnter your choice: ";
						cin >> c;

						cout << endl;
						cout << endl;
						cout << "                                                        LOADING...              " << endl;
						cout << endl;
						cout << endl;

						using namespace std::this_thread; // for putting a delay
						using namespace std::chrono;
						sleep_for(seconds(1));


						if (c == 1) //Search by year of deaths.
						{

							//Search by year of deaths.
							innerflag = false;
						}
						else if (c == 2) //Search by cause of deaths
						{
							//Search by cause of deaths
							innerflag = false;
						}
						else if (c == 3) //Search by State of deaths
						{
							//Search by State of deaths
							innerflag = false;
						}
						else if (c == 4) //Search by number of deaths
						{
							//Search by number of deaths
							innerflag = false;
						}
						else if (c == 5) //Search by death rate
						{

							//Search by death rate
							innerflag = false;
						}
						else if (c == 6) //Go back to previous menu
						{
							innerflag = false;
							break;
						}
						else
						{
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "                           -------------------  WRONG INPUT!  -------------------" << endl;
							cout << endl;
							cout << endl;
							cout << endl;
						}
					}
					else if (c == 2) //Range search
					{
						m.displayRangeSearchingmenu();

						cout << endl;
						cout << "\nEnter your choice: ";
						cin >> c;

						cout << endl;
						cout << endl;
						cout << "                                                        LOADING...              " << endl;
						cout << endl;
						cout << endl;

						using namespace std::this_thread; // for putting a delay
						using namespace std::chrono;
						sleep_for(seconds(1));


						if (c == 1) //Search by year of deaths.
						{

							//Search by year of deaths.
							innerflag = false;
						}
						else if (c == 2) //Search by cause of deaths
						{
							//Search by cause of deaths
							innerflag = false;
						}
						else if (c == 3) //Search by State of deaths
						{
							//Search by State of deaths
							innerflag = false;
						}
						else if (c == 4) //Search by number of deaths
						{
							//Search by number of deaths
							innerflag = false;
						}
						else if (c == 5) //Search by death rate
						{

							//Search by death rate
							innerflag = false;
						}
						else if (c == 6) //Go back to previous menu
						{
							innerflag = false;
							break;
						}
						else
						{
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "                           -------------------  WRONG INPUT!  -------------------" << endl;
							cout << endl;
							cout << endl;
							cout << endl;
						}
					}
					else if (c == 3) //EXIT LOOP
					{
						break;
						innerflag = false;
					}
					else
					{
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "                           -------------------  WRONG INPUT!  -------------------" << endl;
						cout << endl;
						cout << endl;
						cout << endl;
					}

				}
				break;

			case 3: //Updation

				while (innerflag)
				{

					cout << endl;
					cout << endl;
					cout << "                                                        LOADING...              " << endl;
					cout << endl;
					cout << endl;

					using namespace std::this_thread; // for putting a delay
					using namespace std::chrono;
					sleep_for(seconds(1));

					m.displayUpationmenu();

					cout << endl;
					cout << "\nEnter your choice: ";
					cin >> c;


					cout << endl;
					cout << endl;
					cout << "                                                        LOADING...              " << endl;
					cout << endl;
					cout << endl;

					using namespace std::this_thread; // for putting a delay
					using namespace std::chrono;
					sleep_for(seconds(1));

					if (c == 1) //Update existing tuple
					{
						

						//Update existing tuple work here
						innerflag = false;
					}
					else if (c == 2) //Insert new tuple
					{


						//Insert new tuple work here
						innerflag = false;
					}
					else if (c == 3) //Exit
					{


						//Insert new tuple work here
						innerflag = false;
						break;
					}
					else
					{
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "                           -------------------  WRONG INPUT!  -------------------" << endl;
						cout << endl;
						cout << endl;
						cout << endl;
					}
				}
				break;

			case 4: //Deletion


				cout << endl;
				cout << endl;
				cout << "                                                        LOADING...              " << endl;
				cout << endl;
				cout << endl;

				using namespace std::this_thread; // for putting a delay
				using namespace std::chrono;
				sleep_for(seconds(1));

				//deleteion work here
				break;

			case 5:

				cout << endl;
				cout << endl;
				cout << "                                                          EXITTING DSDB...              " << endl;
				cout << endl;
				cout << endl;

				using namespace std::this_thread; // for putting a delay
				using namespace std::chrono;
				sleep_for(seconds(1));

				outerflag = false; //to exit or else it will run infinite
				break;

			default:
				cout << endl;
				cout << endl;
				cout << "                                                        LOADING...              " << endl;
				cout << endl;
				cout << endl;

				using namespace std::this_thread; // for putting a delay
				using namespace std::chrono;
				sleep_for(seconds(1));
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "                            -------------------  WRONG INPUT!  -------------------" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				break;
			}


		}
	}
};
