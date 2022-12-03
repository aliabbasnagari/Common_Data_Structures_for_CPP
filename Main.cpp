/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/

#include "../Data_structures/AVL.h"
#include "../Data_structures/BTree.h"

#include "../Data_structures/Utils.h"
#include "../Data_structures/RedBlackTree.h"
//#include "../Data_structures/BinarySearchTree.h"
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
	//C:/user/4star/source/repos/Data_Structures/
	btreee.traverse();
	cout << endl;
	q = readCSV("datafiles/test_data.csv");
	q->show();
	return 0;
}