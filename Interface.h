#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

#include<chrono>
#include<thread>
#include<iostream>
#include "Utils.h"
#include "RedBlackTree.h"
#include "BinarySearchTree.h"
#include "Header.h"
#include "Utils.h"
#include "Menus.h"
using namespace std;

void createAVL(string key, LinkedList<AVLTree<DataNode>>* list);
void createBTree(string key, int m, LinkedList<BTree<DataNode>>* list);
void createRBTree(string key, LinkedList<RedBlackTree<DataNode>>* list);

class Interface
{

public:
	LinkedList<AVLTree<DataNode>>* avl_list;
	LinkedList<BTree<DataNode>>* btree_list;
	LinkedList<RedBlackTree<DataNode>>* rbtree_list;
	Interface()
	{
		avl_list = NULL;
		btree_list = NULL;
		rbtree_list = NULL;
	}
	Interface(LinkedList<AVLTree<DataNode>>* avl_list, LinkedList<BTree<DataNode>>* btree_list, LinkedList<RedBlackTree<DataNode>>* rbtree_list)
	{
		this->avl_list = avl_list;
		this->btree_list = btree_list;
		this->rbtree_list = rbtree_list;
	}
	void MainInterface()
	{
		bool outerflag = true, innerflag = true;
		int choice, c;
		Menus m;

		while (outerflag) {
			choice = 0; c = 0; outerflag = true; innerflag = true;
			m.displaymainmenu();

			cout << endl;
			cout << "\nEnter your choice: ";
			cin >> choice;


			switch (choice) {

			case 1: //Creation

				while (innerflag) {

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

					if (c == 1) //creation through AVL
					{
						//creation through AVL
						cin.ignore();
						string key;
						cout << "Keys: " << keys[0] << " , " << keys[1] << " , " << keys[2] << " , " << keys[3] << " , " << keys[4] << " , " << keys[5] << endl;
						cout << "Enter indexing key: ";
						getline(cin, key);
						createAVL(key, avl_list);
						innerflag = false;
					} else if (c == 2) //creation through B-TREE
					{
						//creation through B-TREE
						cin.ignore();
						string key;
						int m;
						cout << "Keys: " << keys[0] << " , " << keys[1] << " , " << keys[2] << " , " << keys[3] << " , " << keys[4] << " , " << keys[5] << endl;
						cout << "Enter indexing key: ";
						getline(cin, key);
						cout << "Enter order of B-Tree: ";
						cin >> m;
						createBTree(key, m, btree_list);
						innerflag = false;
					} else if (c == 3) //creation through RnB TREE
					{
						//creation through RnB TREE
						cin.ignore();
						string key;
						cout << "Keys: " << keys[0] << " , " << keys[1] << " , " << keys[2] << " , " << keys[3] << " , " << keys[4] << " , " << keys[5] << endl;
						cout << "Enter indexing key: ";
						getline(cin, key);
						createRBTree(key, rbtree_list);
						innerflag = false;
					} else if (c == 4) //Go back to prev menu
					{
						//Go back to prev menu
						break;
						innerflag = false;
					} else {
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "                           -------------------  WRONG INPUT!  -------------------" << endl;
						cout << endl;
						cout << endl;
						cout << endl;
					}
					cout << endl;
					cout << endl;
					cout << "                                                        LOADING...              " << endl;
					cout << endl;
					cout << endl;

					using namespace std::this_thread; // for putting a delay
					using namespace std::chrono;
					sleep_for(seconds(1));
				}
				break;

			case 2: //Searching
				while (innerflag) {

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
						} else if (c == 2) //Search by cause of deaths
						{
							//Search by cause of deaths
							innerflag = false;
						} else if (c == 3) //Search by State of deaths
						{
							//Search by State of deaths
							innerflag = false;
						} else if (c == 4) //Search by number of deaths
						{
							//Search by number of deaths
							innerflag = false;
						} else if (c == 5) //Search by death rate
						{

							//Search by death rate
							innerflag = false;
						} else if (c == 6) //Go back to previous menu
						{
							innerflag = false;
							break;
						} else {
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "                           -------------------  WRONG INPUT!  -------------------" << endl;
							cout << endl;
							cout << endl;
							cout << endl;
						}
					} else if (c == 2) //Range search
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
						} else if (c == 2) //Search by cause of deaths
						{
							//Search by cause of deaths
							innerflag = false;
						} else if (c == 3) //Search by State of deaths
						{
							//Search by State of deaths
							innerflag = false;
						} else if (c == 4) //Search by number of deaths
						{
							//Search by number of deaths
							innerflag = false;
						} else if (c == 5) //Search by death rate
						{

							//Search by death rate
							innerflag = false;
						} else if (c == 6) //Go back to previous menu
						{
							innerflag = false;
							break;
						} else {
							cout << endl;
							cout << endl;
							cout << endl;
							cout << "                           -------------------  WRONG INPUT!  -------------------" << endl;
							cout << endl;
							cout << endl;
							cout << endl;
						}
					} else if (c == 3) //EXIT LOOP
					{
						break;
						innerflag = false;
					} else {
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

				while (innerflag) {

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
					} else if (c == 2) //Insert new tuple
					{


						//Insert new tuple work here
						innerflag = false;
					} else if (c == 3) //Exit
					{


						//Insert new tuple work here
						innerflag = false;
						break;
					} else {
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

void createAVL(string key, LinkedList<AVLTree<DataNode>>* list)
{
	//create AVL tree here
	bool valid = false;
	Queue<Entry>* q;
	q = readCSV(paths[0]);
	AVLTree<DataNode> temp;
	temp.key = toUpper(key);
	int len = q->Size();
	for (int i = 0; i < len; i++) {
		int indexing = -1;
		if (temp.key == "ID")
			indexing = q->Front().id;
		else if (temp.key == "CAUSE")
			indexing = int_of_str(q->Front().cause_name);
		else if (temp.key == "STATE")
			indexing = int_of_str(q->Front().state);
		else if (temp.key == "YEAR")
			indexing = q->Front().year;
		else if (temp.key == "DEATHS")
			indexing = q->Front().deaths;
		else if (temp.key == "AGE-ADJUSTED DEATH RATE")
			indexing = q->Front().death_rate;
		if (indexing != -1) {
			DataNode node;
			node.filepath = paths[0];
			node.id = indexing;
			node.line = (i + 1);
			temp.insert(node);
			q->dequeue();
			valid = true;
		}
	}
	if (valid)
		list->insert(temp);
}

void createBTree(string key, int m, LinkedList<BTree<DataNode>>* list)
{
	//create BTree here
	bool valid = false;
	Queue<Entry>* q;
	q = readCSV(paths[0]);
	BTree<DataNode> temp(m);
	temp.key = toUpper(key);
	int len = q->Size();
	for (int i = 0; i < len; i++) {
		int indexing = -1;
		if (temp.key == "ID")
			indexing = q->Front().id;
		else if (temp.key == "CAUSE")
			indexing = int_of_str(q->Front().cause_name);
		else if (temp.key == "STATE")
			indexing = int_of_str(q->Front().state);
		else if (temp.key == "YEAR")
			indexing = q->Front().year;
		else if (temp.key == "DEATHS")
			indexing = q->Front().deaths;
		else if (temp.key == "AGE-ADJUSTED DEATH RATE")
			indexing = q->Front().death_rate;
		if (indexing != -1) {
			DataNode node;
			node.filepath = paths[0];
			node.id = indexing;
			node.line = (i + 1);
			temp.insert(node);
			q->dequeue();
			valid = true;
		}
	}
	if (valid);
	list->insert(temp);
}

void createRBTree(string key, LinkedList<RedBlackTree<DataNode>>* list)
{
	//create RBTree here
	bool valid = false;
	Queue<Entry>* q;
	q = readCSV(paths[0]);
	RedBlackTree<DataNode> temp;
	temp.key = toUpper(key);
	int len = q->Size();
	for (int i = 0; i < len; i++) {
		int indexing = -1;
		if (temp.key == "ID")
			indexing = q->Front().id;
		else if (temp.key == "CAUSE")
			indexing = int_of_str(q->Front().cause_name);
		else if (temp.key == "STATE")
			indexing = int_of_str(q->Front().state);
		else if (temp.key == "YEAR")
			indexing = q->Front().year;
		else if (temp.key == "DEATHS")
			indexing = q->Front().deaths;
		else if (temp.key == "AGE-ADJUSTED DEATH RATE")
			indexing = q->Front().death_rate;
		if (indexing != -1) {
			DataNode node;
			node.filepath = paths[0];
			node.id = indexing;
			node.line = (i + 1);
			temp.insert(node);
			q->dequeue();
			valid = true;
		}
		if (valid)
			list->insert(temp);
	}
}

#endif // !INTERFACE_H