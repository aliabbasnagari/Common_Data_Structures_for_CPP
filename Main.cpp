/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/

#include<chrono>
#include<thread>
#include<iostream>
#include "AVL.h"
#include "BTree.h"
#include "Header.h"
#include "Utils.h"
#include "Menus.h"
#include "Interface.h"
using namespace std;

void readLogs(LinkedList<AVLTree<DataNode>>* avl, LinkedList<BTree<DataNode>>* btree, LinkedList<RedBlackTree<DataNode>>* rnbtree)
{
	string val = "";
	string root = "database/";
	// File Handling
	fstream data_file;
	data_file.open(root + "logs.txt", ios::in);
	if (data_file.good()) {
		while (!data_file.eof()) {
			val = "";
			data_file >> val;
			if (val != "") {
				if (val == "AVL_ID") {
					createAVL("ID", avl);
				} else if (val == "AVL_CAUSE") {
					createAVL("CAUSE", avl);
				} else if (val == "AVL_STATE") {
					createAVL("STATE", avl);
				} else if (val == "AVL_YEAR") {
					createAVL("YEAR", avl);
				} else if (val == "AVL_DEATHS") {
					createAVL("DEATHS", avl);
				} else if (val == "AVL_AGE-ADJUSTED") {
					data_file >> val >> val;
					createAVL("AGE-ADJUSTED DEATH RATE", avl);
				} else if (val == "B_ID") {
					int m;
					data_file >> m;
					createBTree("ID", m, btree);
				} else if (val == "B_CAUSE") {
					int m;
					data_file >> m;
					createBTree("CAUSE", m, btree);
				} else if (val == "B_STATE") {
					int m;
					data_file >> m;
					createBTree("STATE", m, btree);
				} else if (val == "B_YEAR") {
					int m;
					data_file >> m;
					createBTree("YEAR", m, btree);
				} else if (val == "B_DEATHS") {
					int m;
					data_file >> m;
					createBTree("DEATHS", m, btree);
				} else if (val == "B_AGE-ADJUSTED") {
					data_file >> val >> val;
					int m;
					data_file >> m;
					cout << val << " AND " << m << endl;
					cout << "M = " << m << endl;
					createBTree("AGE-ADJUSTED DEATH RATE", m, btree);
				} else if (val == "RNB_ID") {
					createRBTree("ID", rnbtree);
				} else if (val == "RNB_CAUSE") {
					createRBTree("CAUSE", rnbtree);
				} else if (val == "RNB_STATE") {
					createRBTree("STATE", rnbtree);
				} else if (val == "RNB_YEAR") {
					createRBTree("YEAR", rnbtree);
				} else if (val == "RNB_DEATHS") {
					createRBTree("DEATHS", rnbtree);
				} else if (val == "RNB_AGE-ADJUSTED") {
					data_file >> val >> val;
					createRBTree("AGE-ADJUSTED DEATH RATE", rnbtree);
				}
			}
		}
	}
}

int main() 
{
	LinkedList<AVLTree<DataNode>>* avl_list = new LinkedList<AVLTree<DataNode>>;
	LinkedList<BTree<DataNode>>* btree_list = new LinkedList<BTree<DataNode>>;
	LinkedList<RedBlackTree<DataNode>>* rbtree_list = new LinkedList<RedBlackTree<DataNode>>;

	readLogs(avl_list, btree_list, rbtree_list);

	system("color 5F");

	Interface I(avl_list, btree_list, rbtree_list);

	I.MainInterface();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                         *******************************************" << endl;
	cout << "                                         *                                         *" << endl;
	cout << "                                         *        THANK YOU FOR USING DSDB         *" << endl;
	cout << "                                         *                                         *" << endl;
	cout << "                                         *                GOODBYE!                 *" << endl;
	cout << "                                         *                                         *" << endl;
	cout << "                                         *******************************************" << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "\n\nFOR DEBUG PURPOSES ONLY: " << endl;

	cout << "AVL" << endl;
	for (int i = 0; i < avl_list->Size(); i++) {
		avl_list->atIndex(i)->getValue().LevelOrderTreversal(avl_list->atIndex(i)->getValue().root);
	}

	cout << "BTREE" << endl;
	for (int i = 0; i < btree_list->Size(); i++) {
		btree_list->atIndex(i)->getValue().traverse();
	}

	cout << "RED BLACK" << endl;
	for (int i = 0; i < rbtree_list->Size(); i++) {
		rbtree_list->atIndex(i)->getValue().printTree();
	}

	cin.get();
	
	return 0;
}
