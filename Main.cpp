/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main() {

	// File Handling
	string path = "datafiles/test_data.csv";
	fstream data_file;
	data_file.open(path, ios::in);
	if (data_file.good())
	{
		while (!data_file.eof())
		{
			string val;
			getline(data_file, val, ',');
			cout << val << endl;
		}
	}
	// Testing Linked List
	LinkedList<int> list;
	list.insert(1);
	list.insert(9);
	list.insert(8);
	list.print();

	return 0;
}