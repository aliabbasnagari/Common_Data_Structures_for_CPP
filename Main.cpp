/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/


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

	//C:/user/4star/source/repos/Data_Structures/
	/*BTree<int> bree;
		bree.traverse();*/
	//cout << endl;
	//q = readCSV("../Data_Structures/datafiles/test2.csv"); //only for me changed
	//q->show();

	avl.LevelOrderTreversal(avl.root);
	avl.getQueryrange("get <cause> with # id=15-20");

	return 0;
}