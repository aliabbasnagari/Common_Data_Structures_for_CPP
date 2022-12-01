/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/

#include "RedBlackTree.h"
#include "BTree.h"
#include "LinkedList.h"
#include "Utils.h"
using namespace std;

int main() {
	
	Queue<Entry>* q;
	// Testing Red Black Tree
	RedBlackTree<int> rbt;
	BTree<int> btreee(3);
	for (int i = 1; i < 11; i++)
	{
		btreee.insertion(i);
	}
	btreee.traverse();
	cout << endl;
	q = readCSV("datafiles/test_data.csv");
	q->show();
	return 0;
}