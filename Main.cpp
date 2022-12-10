/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/


#include "AVL.h"
#include "BTree.h"
#include "Utils.h"
#include "RedBlackTree.h"
#include "BinarySearchTree.h"
#include "Header.h"
#include "Utils.h"
#include "Menus.h"
#include "Interface.h"

#include<chrono>
#include<thread>
#include<iostream>
using namespace std;

int main() 
{

	system("color 5F");

	Interface I;
	
	I.MainInterface();
	

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                         *******************************************" << endl;
	cout << "                                         *                                         *" << endl;
	cout << "                                         *        THANK YOU FOR USING DSDB         *" << endl;
	cout << "                                         *                                         *" << endl;
	cout << "                                         *                GOODBYE!		   *" << endl;
	cout << "                                         *                                         *" << endl;
	cout << "                                         *******************************************" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
=======
int main() {
	string path = "datafiles/test2.csv";
	Queue<Entry>* q;
	q= readCSV(path);
	AVLTree<DataNode> avl;
	AVLTree<DataNode> avlname;
	BTree<DataNode> btree(4);
	avl.key = "ID";
	avlname.key = "STATE";
	btree.key = "ID";
	int len = q->Size();
	for (int i = 0; i < len; i++)
	{
		DataNode node;
		node.filepath = path;
		node.id = q->Front().getId();
		node.line = (i + 1);
		btree.insert(node);
		avl.insert(node);
		node.filepath = path;
		node.id = int_of_str(q->Front().state);
		node.line = (i + 1);
		avlname.insert(node);
		q->dequeue();
	}
	cout << endl << endl;
	// avl.LevelOrderTreversal(avl.root);
	cout << "Range Search: \n";
	//avl.getQueryrange("get <year,state,deaths> where # id=15-20");
	cout << "Single Search: \n";
	avl.getQuery("get <state> where # id=18");
	cout << "\nString Search: \n";
	avlname.getQuery("get <id> where # state=Indiana");
	

	//Testing for B-Tree
	cout << endl << "B-Tree: " << endl;
	btree.traverse();


	return 0;
}