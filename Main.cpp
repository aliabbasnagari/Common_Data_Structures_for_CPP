/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/

#include <iostream>
#include <fstream>
#include <string>
#include "RedBlackTree.h"
#include "LinkedList.h"
using namespace std;

int main() {
	
	// Testing Red Black Tree
	RedBlackTree<int> rbt;

	string val = "";
	// File Handling
	string path = "datafiles/test_data.csv";
	fstream data_file;
	data_file.open(path, ios::in);
	if (data_file.good())
	{
		getline(data_file, val);
		while (!data_file.eof())
		{
			string temp = "";
			int id;
			int year;
			int deaths;
			float death_rate = 0;
			string cause_113 = "";
			string cause = "";
			string state = "";

			getline(data_file, temp, ',');
			id = stoi(temp);
			cout << "< " << id << " >" << endl;

			getline(data_file, temp, ',');
			year = stoi(temp);
			cout << "< " << year << " >" << endl;

			getline(data_file, cause_113, ',');
			temp = cause_113;
			while (temp[0] == '\"') {
				getline(data_file, temp, ',');
				cause_113 += temp;
			}
			cout << "< " << cause_113 << " >" << endl;

			getline(data_file, cause, ',');
			temp = cause;
			while (temp[0] == '\"') {
				getline(data_file, temp, ',');
				cause += temp;
			}
			cout << "< " << cause << " >" << endl;

			getline(data_file, state, ',');
			temp = state;
			while (state[0] == '\"') {
				getline(data_file, temp, ',');
				state += temp;
			}
			cout << "< " << state << " >" << endl;

			getline(data_file, temp, ',');
			deaths = stoi(temp);
			cout << "< " << deaths << " >" << endl;

			getline(data_file, temp);
			death_rate = stof(temp);
			cout << "< " << death_rate << " >" << endl;
			rbt.insert(id);
		}

		rbt.printTree();
	}

	return 0;
}