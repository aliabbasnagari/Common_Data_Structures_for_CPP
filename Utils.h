#pragma once
/* All Utility Functions */
#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "Entry.h"
using namespace std;

struct KeyVal
{
	int id;
	string path;
	int line;
	KeyVal* left;
	KeyVal* right;
};

Queue<Entry>* readCSV(string path) {
	Entry obj;
	Queue<Entry>* q = new Queue<Entry>;
	string val = "";
	// File Handling
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
			//cout << "< " << id << " >" << endl;

			getline(data_file, temp, ',');
			year = stoi(temp);
			//cout << "< " << year << " >" << endl;

			getline(data_file, cause_113, ',');
			temp = cause_113;
			while (temp[0] == '\"') {
				getline(data_file, temp, ',');
				cause_113 += temp;
			}
			//cout << "< " << cause_113 << " >" << endl;

			getline(data_file, cause, ',');
			temp = cause;
			while (temp[0] == '\"') {
				getline(data_file, temp, ',');
				cause += temp;
			}
			//cout << "< " << cause << " >" << endl;

			getline(data_file, state, ',');
			temp = state;
			while (state[0] == '\"') {
				getline(data_file, temp, ',');
				state += temp;
			}
			//cout << "< " << state << " >" << endl;

			getline(data_file, temp, ',');
			deaths = stoi(temp);
			//cout << "< " << deaths << " >" << endl;

			getline(data_file, temp);
			death_rate = stof(temp);
			//cout << "< " << death_rate << " >" << endl;

			obj.cause_name_113 = cause_113;
			obj.cause_name = cause;
			obj.deaths = deaths;
			obj.death_rate = death_rate;
			obj.id = id;
			obj.state = state;
			obj.year = year;
			q->enqueue(obj);
		}
	}
	
	return q;
}

