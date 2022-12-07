/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/

#include "BTree.h"
#include "AVL.h"
#include "Header.h"
#include "Utils.h"

using namespace std;

int main() {
	string path = "datafiles/test2.csv";
	Queue<Entry>* q;
	q= readCSV(path);
	AVLTree<DataNode> avl;
	int len = q->Size();
	for (int i = 0; i < len; i++)
	{
		DataNode node;
		node.filepath = path;
		node.id = q->Front().getId();
		node.line = (i + 1);
		avl.insert(node);
		q->dequeue();
	}

	avl.LevelOrderTreversal(avl.root);
	avl.getQueryrange("get <year,state,deaths> with # id=15-20");
	avl.getQuery("get <state> with # id=15");

	return 0;
}