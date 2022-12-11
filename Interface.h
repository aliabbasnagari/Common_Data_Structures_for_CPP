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
using namespace std::this_thread; // for putting a delay
using namespace std::chrono;

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
					sleep_for(seconds(1));

					m.displayCreationmenu();

					cout << endl;
					cout << "\nEnter your choice: ";
					cin >> c;

					string key;
					if (c > 0 && c < 4) {
						cin.ignore();
						cout << "\nKeys: " << keys[0] << " , " << keys[1] << " , " << keys[2] << " , " << keys[3] << " , " << keys[4] << " , " << keys[5] << endl;
						cout << "Enter indexing key: ";
						getline(cin, key);

						if (c == 1) //creation through AVL
						{
							//creation through AVL
							createAVL(key, avl_list);
							innerflag = false;
						} else if (c == 2) //creation through B-TREE
						{
							//creation through B-TREE
							int m;
							cout << "Enter order of B-Tree: ";
							cin >> m;
							createBTree(key, m, btree_list);
							innerflag = false;
						} else if (c == 3) //creation through RnB TREE
						{
							//creation through RnB TREE
							cin.ignore();
							createRBTree(key, rbtree_list);
							innerflag = false;
						} else if (c == 4) {
							//Go back to prev menu
							break;
							innerflag = false;
						}
						messageLoading();
					} else {
						messageWrongInput();
					}
					sleep_for(seconds(1));
				}
				break;
			case 2: //Searching
				while (innerflag) {
					messageLoading();
					sleep_for(seconds(1));

					m.displaySearchingmenu();

					cout << endl;
					cout << "\nEnter your choice: ";
					cin >> c;
					messageLoading();
					sleep_for(seconds(1));

					if (c == 1) //Point search
					{
						m.displayPointSearchingmenu();

						cout << endl;
						cout << "\nEnter your choice: ";
						cin >> c;

						messageLoading();
						sleep_for(seconds(1));

						if (c == 1) //Search by year of deaths.
						{
							//Search by year of deaths.
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "YEAR")
									at_ind = i;
							}
							if (at_ind != -1) {
								int year = -1;
								cout << "\nEnter year of deaths: ";
								cin >> year;
								AVLTree<DataNode> tree = avl_list->atIndex(at_ind)->getValue();
								LinkedList<Entry>* list = tree.searchID(year);
								if (list != NULL) {
									list->display();
								}
							}
							cin.ignore();
							pressAnyKey();
							innerflag = false;
						} else if (c == 2) {
							//Search by cause of deaths
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "CAUSE")
									at_ind = i;
							}
							if (at_ind != -1) {
								string cause = "";
								cout << "\nEnter year of deaths: ";
								getline(cin, cause);
								AVLTree<DataNode> tree = avl_list->atIndex(at_ind)->getValue();
								LinkedList<Entry>* list = tree.searchID(int_of_str(cause));
								if (list != NULL) {
									list->display();
								}
							}
							cin.ignore();
							pressAnyKey();
							innerflag = false;
						} else if (c == 3) //Search by State of deaths
						{
							//Search by State of deaths
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "STATE")
									at_ind = i;
							}
							if (at_ind != -1) {
								string state = "";
								cout << "\nEnter State where deaths occured: ";
								getline(cin, state);
								AVLTree<DataNode> tree = avl_list->atIndex(at_ind)->getValue();
								LinkedList<Entry>* list = tree.searchID(int_of_str(state));
								if (list != NULL) {
									list->display();
								}
							}
							cin.ignore();
							pressAnyKey();
							innerflag = false;
						} else if (c == 4) //Search by number of deaths
						{
							//Search by number of deaths
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "YEAR")
									at_ind = i;
							}
							if (at_ind != -1) {
								int number = -1;
								cout << "\nEnter number of deaths: ";
								cin >> number;
								AVLTree<DataNode> tree = avl_list->atIndex(at_ind)->getValue();
								LinkedList<Entry>* list = tree.searchID(number);
								if (list != NULL) {
									list->display();
								}
							}
							cin.ignore();
							pressAnyKey();
							innerflag = false;
						} else if (c == 5) //Search by death rate
						{

							//Search by death rate
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "AGE-ADJUSTED DEATH RATE")
									at_ind = i;
							}
							if (at_ind != -1) {
								float deathrate = -1;
								cout << "\nEnter death rate: ";
								cin >> deathrate;
								AVLTree<DataNode> tree = avl_list->atIndex(at_ind)->getValue();
								LinkedList<Entry>* list = tree.searchID(deathrate);
								if (list != NULL) {
									list->display();
								}
							}
							cin.ignore();
							pressAnyKey();
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
					messageLoading();
					sleep_for(seconds(1));
					m.displayUpationmenu();
					cout << endl;
					cout << "\nEnter your choice: ";
					cin >> c;
					messageLoading();
					sleep_for(seconds(1));

					if (c == 1) //Update existing tuple
					{


						//Update existing tuple work here
						innerflag = false;
					} else if (c == 2) //Insert new tuple
					{
						maxId++;
						//Insert new tuple work here
						Entry newEntry;
						newEntry.id = maxId;
						cout << "Enter death year: ";
						cin >> newEntry.year;
						cin.ignore();
						cout << "Enter 113 Cause Name: ";
						getline(cin, newEntry.cause_name_113);
						cout << "Enter cause name: ";
						getline(cin, newEntry.cause_name);
						cout << "Enter state: ";
						getline(cin, newEntry.state);
						cout << "Enter number of deaths: ";
						cin >> newEntry.deaths;
						cout << "Enter age-adjusted death rate: ";
						cin >> newEntry.death_rate;
						insertToFile(paths[NOPATHS - 1], newEntry);
						updateMaxId(maxId);
						innerflag = false;
					} else if (c == 3) //Exit
					{


						//Insert new tuple work here
						innerflag = false;
						break;
					} else {
						messageWrongInput();
					}
				}
				break;

			case 4: //Deletion
				messageLoading();
				sleep_for(seconds(1));
				//deleteion work here
				break;

			case 5:

				cout << endl;
				cout << endl;
				cout << "                                                          EXITTING DSDB...              " << endl;
				cout << endl;
				cout << endl;
				sleep_for(seconds(1));

				outerflag = false; //to exit or else it will run infinite
				break;

			default:
				messageLoading();
				sleep_for(seconds(1));
				messageWrongInput();
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
	if (temp.key == "DEATH RATE")
		temp.key = "AGE-ADJUSTED DEATH RATE";
	int len = q->Size();
	for (int i = 0; i < len; i++) {
		int indexing = -1;
		float indx = -1;
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
			indx = q->Front().death_rate;
		if (indx != -1)
			indexing = indx;
		if (indexing != -1) {
			DataNode node;
			node.filepath = paths[0];
			node.id = indexing;
			node._id = indx;
			node.line = (i + 1);
			temp.insert(node);
			q->dequeue();
			valid = true;
		}
	}
	if (valid) {
		list->insert(temp);
		updateLog("AVL_" + temp.key);
	}
}

void createBTree(string key, int m, LinkedList<BTree<DataNode>>* list)
{
	//create BTree here
	bool valid = false;
	Queue<Entry>* q;
	q = readCSV(paths[0]);
	BTree<DataNode> temp(m);
	temp.key = toUpper(key);
	if (temp.key == "DEATH RATE")
		temp.key = "AGE-ADJUSTED DEATH RATE";
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
	if (valid) {
		list->insert(temp);
		updateLog("B_" + temp.key + " " + to_string(m));
	}
}

void createRBTree(string key, LinkedList<RedBlackTree<DataNode>>* list)
{
	//create RBTree here
	bool valid = false;
	Queue<Entry>* q;
	q = readCSV(paths[0]);
	RedBlackTree<DataNode> temp;
	temp.key = toUpper(key);
	if (temp.key == "DEATH RATE")
		temp.key = "AGE-ADJUSTED DEATH RATE";
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
		if (valid) {
			list->insert(temp);
			updateLog("RNB_" + temp.key);
		}
	}
}

#endif // !INTERFACE_H