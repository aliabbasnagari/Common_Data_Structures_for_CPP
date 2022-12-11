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

			string _tkey;
			string _tvalue;

			switch (choice) {
			case 1: //Creation
				while (innerflag) {
					messageLoading();
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
							TreeType = 1;
							innerflag = false;
						} else if (c == 2) //creation through B-TREE
						{
							//creation through B-TREE
							int m;
							cout << "Enter order of B-Tree: ";
							cin >> m;
							createBTree(key, m, btree_list);
							TreeType = 2;
							innerflag = false;
						} else if (c == 3) {
							//creation through RnB TREE
							cin.ignore();
							createRBTree(key, rbtree_list);
							TreeType = 3;
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
							} else {
								cout << "Key not found!" << endl;
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
						} else if (c == 4) {
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
						} else if (c == 5) {
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
						} else if (c == 6) {
							//Search by id of deaths
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "ID")
									at_ind = i;
							}
							if (at_ind != -1) {
								int number = -1;
								cout << "\nEnter Id of deaths: ";
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
						} else if (c == 7) //Go back to previous menu
						{
							innerflag = false;
							break;
						} else {
							messageWrongInput();
							break;
						}
					} else if (c == 2) //Range search
					{
						m.displayRangeSearchingmenu();

						cout << endl;
						cout << "\nEnter your choice: ";
						cin >> c;

						messageLoading();
						sleep_for(seconds(1));


						if (c == 1) {
							//Search by year of deaths.
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "YEAR")
									at_ind = i;
							}
							if (at_ind != -1) {
								int syear = -1, eyear = -1;
								cout << "\nEnter starting year of deaths: ";
								cin >> syear;
								cout << "Enter ending year of deaths: ";
								cin >> eyear;
								AVLTree<DataNode> tree = avl_list->atIndex(at_ind)->getValue();
								tree.searchIDRange(syear, eyear);
							} else {
								cout << "Key not found!" << endl;
							}
							cin.ignore();
							pressAnyKey();
							innerflag = false;
						} else if (c == 2) {
							//Search by number of deaths
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "DEATHS")
									at_ind = i;
							}
							if (at_ind != -1) {
								int syear = -1, eyear = -1;
								cout << "\nEnter starting number of deaths: ";
								cin >> syear;
								cout << "Enter ending number of deaths: ";
								cin >> eyear;
								cout << endl;
								AVLTree<DataNode> tree = avl_list->atIndex(at_ind)->getValue();
								tree.searchIDRange(syear, eyear);
							} else {
								cout << "Key not found!" << endl;
							}
							cin.ignore();
							pressAnyKey();
							innerflag = false;
						} else if (c == 3) {
							//Search by of deaths rate
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "AGE-ADJUSTED DEATH RATE")
									at_ind = i;
							}
							if (at_ind != -1) {
								float syear = -1, eyear = -1;
								cout << "\nEnter starting death rate: ";
								cin >> syear;
								cout << "Enter ending death rate: ";
								cin >> eyear;
								cout << endl;
								AVLTree<DataNode> tree = avl_list->atIndex(at_ind)->getValue();
								tree.searchIDRange(syear, eyear);
							} else {
								cout << "Key not found!" << endl;
							}
							cin.ignore();
							innerflag = false;
						} else if (c == 4) {
							//Search by id of deaths
							int at_ind = -1;
							for (int i = 0; i < avl_list->Size(); i++) {
								if (toUpper(avl_list->atIndex(i)->getValue().key) == "ID")
									at_ind = i;
							}
							if (at_ind != -1) {
								int syear = -1, eyear = -1;
								cout << "\nEnter starting id: ";
								cin >> syear;
								cout << "Enter ending id: ";
								cin >> eyear;
								cout << endl;
								AVLTree<DataNode> tree = avl_list->atIndex(at_ind)->getValue();
								tree.searchIDRange(syear, eyear);
							} else {
								cout << "Key not found!" << endl;
							}
							cin.ignore();
							pressAnyKey();
							innerflag = false;
						} else {
							messageWrongInput();
						}
					} else if (c == 3) //EXIT LOOP
					{
						break;
						innerflag = false;
					} else {
						messageWrongInput();
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
						cin.ignore();
						int ind = -1;
						int ent_i = -1;
						int fieldt = 0;
						int occurence = 0;
						string keyval;
						string field;
						string newValue;
						string oldValue;
						//Update existing tuple work here
						cout << "\nKeys: " << keys[0] << " , " << keys[1] << " , " << keys[2] << " , " << keys[3] << " , " << keys[4] << " , " << keys[5] << endl;
						cout << "select key:";
						getline(cin, _tkey);
						for (int i = 0; i < avl_list->Size(); i++) {
							if (toUpper(_tkey) == avl_list->atIndex(i)->getValue().key) {
								ind = i;
							}
						}
						cout << ind << endl;
						if (ind != -1) {
							LinkedList<Entry>* entries;
							cout << "Enter key value:";
							getline(cin, keyval);
							if (toUpper(_tkey) == "ID" || toUpper(_tkey) == "DEATHS" || toUpper(_tkey) == "AGE-ADUSTED DEATH RATE" || toUpper(_tkey) == "YEAR")
								entries = avl_list->atIndex(ind)->getValue().searchID(stoi(keyval));
							else
								entries = avl_list->atIndex(ind)->getValue().searchID(int_of_str(keyval));
							
							entries->display();
							cout << "Select field to update: ";
							getline(cin, field);
							cout << "Enter old value: ";
							getline(cin, oldValue);
							cout << "Enter new value: ";
							getline(cin, newValue);
							for (int i = 0; i < entries->Size(); i++) {
								if (toUpper(field) == "ID" || toUpper(field) == "YEAR" || toUpper(field) == "DEATHS" || toUpper(field) == "AGE-ADUSTED DEATH RATE") {
									if (entries->atIndex(i)->getValue().id == stoi(oldValue)) {
										occurence++;
										fieldt = 1;
										ent_i = i;
									} else if (entries->atIndex(i)->getValue().year == stoi(oldValue)) {
										occurence++;
										fieldt = 2;
										ent_i = i;
									} else if (entries->atIndex(i)->getValue().deaths == stoi(oldValue)) {
										occurence++;
										fieldt = 3;
										ent_i = i;
									} else if (entries->atIndex(i)->getValue().death_rate == stof(oldValue)) {
										occurence++;
										fieldt = 4;
										ent_i = i;
									}
								} else {
									if (entries->atIndex(i)->getValue().cause_name == oldValue) {
										occurence++;
										fieldt = 5;
										ent_i = i;
									} else if (entries->atIndex(i)->getValue().state == oldValue) {
										occurence++;
										fieldt = 6;
										ent_i = i;
									}
								}
							}
							cout << occurence << " " << "FIELD: " << fieldt << endl;
							sleep_for(seconds(1));
							if (occurence == 1) {
								int oldID = entries->atIndex(ent_i)->getValue().id;
								string filePath = avl_list->atIndex(ent_i)->getValue().root->value.filepath;
								if (fieldt == 1) {
									entries->atIndex(ent_i)->getValue().setId(stoi(newValue));
								} else if (fieldt == 2) {
									entries->atIndex(ent_i)->getValue().setYear(stoi(newValue));
								} else if (fieldt == 3) {
									entries->atIndex(ent_i)->getValue().setDeaths(stoi(newValue));
								} else if (fieldt == 4) {
									entries->atIndex(ent_i)->getValue().setDeathRate(stof(newValue));
								} else if (fieldt == 5) {
									entries->atIndex(ent_i)->getValue().setCause(newValue);
								} else if (fieldt == 6) {
									entries->atIndex(ent_i)->getValue().state = (newValue);
								}
								cout << "Path: " << filePath << endl << "ID: " << oldID << endl;
								cout << entries->atIndex(ent_i)->getValue() << endl;
								sleep_for(seconds(5));
								updateFile(filePath, entries->atIndex(ent_i)->getValue(), oldID);
							} else {
								cout << "Failed! Multiple Occurences or Invalid" << endl;
							}
						} else {
							cout << "Key not found!" << endl;
						}
						sleep_for(seconds(1));
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

			case 4:

				messageLoading();
				sleep_for(seconds(1));
				cin.ignore();
				cout << "\nKeys: " << keys[0] << " , " << keys[1] << " , " << keys[2] << " , " << keys[3] << " , " << keys[4] << " , " << keys[5] << endl;
				cout << "Select key: ";
				getline(cin, _tkey);
				cout << "Enter key value to delete the node: ";
				getline(cin, _tvalue);
				break;
			case 5:
				messageLoading();
				sleep_for(seconds(1));
				cin.ignore();
				cout << "\nKeys: " << keys[0] << " , " << keys[1] << " , " << keys[2] << " , " << keys[3] << " , " << keys[4] << " , " << keys[5] << endl;
				cout << "Select key: ";
				getline(cin, _tkey);
				for (int i = 0; i < avl_list->Size(); i++) {
					if (toUpper(avl_list->atIndex(i)->getValue().key) == toUpper(_tkey)) {
						cout << "Sample Query: get <cause> where #id=10-15\n";
						cout << "Range or single: ";
						getline(cin, _tkey);
						cout << "Enter query: ";
						getline(cin, _tvalue);
						if (toUpper(_tkey) == "RANGE") {
							avl_list->atIndex(i)->getValue().getQueryrange(_tvalue);
						} else {
							avl_list->atIndex(i)->getValue().getQuery(_tvalue);
						}
						getline(cin, _tvalue);
						break;
					}
				}
				break;
			case 6:

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
	AVLTree<DataNode> temp;
	temp.key = toUpper(key);
	for (int p = 0; p < NOPATHS; p++) {
		Queue<Entry>* q;
		q = readCSV(paths[p]);
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
				node.filepath = paths[p];
				node.id = indexing;
				node._id = indx;
				node.line = (i + 1);
				temp.insert(node);
				q->dequeue();
				valid = true;
			}
		}
	}
	if (valid) {
		list->insert(temp);
		updateLog("AVL_" + temp.key);
	}
}

void createBTree(string key, int m, LinkedList<BTree<DataNode>>* list)
{
	BTree<DataNode> temp(m);
	bool valid = false;
	//create BTree here
	for (int p = 0; p < NOPATHS; p++) {
		Queue<Entry>* q;
		q = readCSV(paths[p]);
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
				node.filepath = paths[p];
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
}

void createRBTree(string key, LinkedList<RedBlackTree<DataNode>>* list)
{
	//create RBTree here
	for (int p = 0; p < NOPATHS; p++) {
		bool valid = false;
		Queue<Entry>* q;
		q = readCSV(paths[p]);
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
				node.filepath = paths[p];
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
}

#endif // !INTERFACE_H