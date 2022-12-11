#pragma once
#ifndef UTILS_H
#define UTILS_H

/* All Utility Functions */
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include "Queue.h"
#include "LinkedList.h"
#include "Entry.h"
#include "Header.h"
using namespace std;

int getMaxId()
{
	int max = 0;

	fstream data_file;

	data_file.open("database/Indexing.txt", ios::in);

	if (data_file.good()) {
		int temp = -1;
		while (!data_file.eof()) {
			data_file >> temp;
			if (temp != -1) {
				data_file.close();
				return temp;
			}

		}
		data_file.close();
		return 0;
	}

	data_file.close();

	return max;
}
void updateMaxId(int ind)
{
	fstream data_file;
	data_file.open("database/Indexing.txt", ios::out);
	if (data_file.good()) {
		data_file << ind;
		data_file.close();
		return;
	}
	data_file.close();
	return;
}

const int NOPATHS = 1;
string paths[NOPATHS] = { "datafiles/test2.csv" };
int maxId = getMaxId();

string keys[6] = { "Id", "Year", "Cause", "State", "Deaths", "Age-adjusted death rate" };

int int_of_str(string val)
{
	int int_rep = 0;
	for (int i = 0; i < val.length(); i++)
		int_rep += (val[i] * i);

	return int_rep;
}

Queue<Entry>* readCSV(string path)
{
	Entry obj;
	Queue<Entry>* q = new Queue<Entry>;
	string val = "";
	// File Handling
	fstream data_file;
	data_file.open(path, ios::in);
	if (data_file.good()) {
		getline(data_file, val);
		while (!data_file.eof()) {
			string temp = "";
			int id;
			int year;
			int deaths;
			float death_rate = 0;
			string cause_113 = "";
			string cause = "";
			string state = "";

			getline(data_file, temp, ',');
			if (temp != "") {
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
	}
	data_file.close();
	return q;
}

void saveNode(string folder, string file, FileNode data)
{
	bool found = false;
	string val = "";
	string root = "database/";
	// File Handling
	fstream data_file;
	data_file.open(root + folder + "/" + file, ios::in);
	if (data_file.good()) {
		FileNode f_node;
		while (!data_file.eof()) {
			data_file >> f_node;
			if (f_node == data) {
				found = true;
				break;
			}
		}
		data_file.close();
	}
	if (!found) {
		data_file.open(root + folder + "/" + file, ios::app);
		if (data_file.good()) {
			data_file << data.node_path << endl;
			data_file << data.line << endl;
		} else {
			int dir = _mkdir((root + folder).c_str());
			data_file.open(root + folder + "/" + file, ios::app);
			if (data_file.good()) {
				data_file << data.node_path << endl;
				data_file << data.line << endl;
			}
		}
	}
	data_file.close();
}

Entry readLine(string path, int line)
{
	string val = "";
	Entry obj;
	// File Handling
	fstream data_file;
	data_file.open(path, ios::in);
	int curr_line = 0;
	if (data_file.good()) {
		while (!data_file.eof() && curr_line <= line) {
			string temp = "";
			int id = 0;
			int year = 0;
			int deaths = 0;
			float death_rate = 0;
			string cause_113 = "";
			string cause = "";
			string state = "";

			getline(data_file, temp, ',');
			if (temp != "ID" && temp != " " && temp != "")
				id = stoi(temp);
			getline(data_file, temp, ',');
			if (temp != "Year" && temp != " " && temp != "")
				year = stoi(temp);
			getline(data_file, cause_113, ',');
			temp = cause_113;
			while (temp[0] == '\"') {
				getline(data_file, temp, ',');
				cause_113 += temp;
			}
			getline(data_file, cause, ',');
			temp = cause;
			while (temp[0] == '\"') {
				getline(data_file, temp, ',');
				cause += temp;
			}
			getline(data_file, state, ',');
			temp = state;
			while (state[0] == '\"') {
				getline(data_file, temp, ',');
				state += temp;
			}
			getline(data_file, temp, ',');
			if (temp != "Deaths" && temp != " " && temp != "")
				deaths = stoi(temp);
			getline(data_file, temp);
			if (temp != "Age-adjusted Death Rate" && temp != " " && temp != "")
				death_rate = stof(temp);
			obj.cause_name_113 = cause_113;
			obj.cause_name = cause;
			obj.deaths = deaths;
			obj.death_rate = death_rate;
			obj.id = id;
			obj.state = state;
			obj.year = year;
			curr_line++;
		}
	}
	data_file.close();
	return obj;
}

string getPath(string path)
{
	string val = "";
	fstream data_file;
	data_file.open(path, ios::in);
	if (data_file.good())
		getline(data_file, val);
	data_file.close();
	return val;
}

int getLine(string path)
{
	string val = "";
	fstream data_file;
	data_file.open(path, ios::in);
	if (data_file.good()) {
		getline(data_file, val);
		getline(data_file, val);
	}
	data_file.close();
	return stoi(val);
}

string split(string& str, char sep)
{
	int currentIndex = 0, i = 0, j = 0;
	int startIndex = 0, endIndex = 0;
	string subStr = "";
	while (str[i] != sep)
		i++;
	j = i;
	i++;
	while (i < str.length()) {
		subStr += str[i];
		i++;
	}
	str.erase(j, str.length());
	return subStr;
}

// Helping functions
// Trim extra spaces from starting of a string
string trim(string text)
{
	int begin = 0;
	while (text[begin] == 10 || text[begin] == 9 || text[begin] == ' ')
		begin++;
	text.erase(0, begin);
	return text;
}

// Trim extra spaces from both ends of a string
string fullTrim(string text)
{
	int begin = 0;
	while (text[begin] == 9 || text[begin] == ' ')
		begin++;
	text.erase(0, begin);
	begin = text.length() - 1;
	while (text[begin] == 9 || text[begin] == ' ')
		begin--;
	text.erase(begin + 1, text.length() - 1);
	return text;
}

string toLower(string word)
{
	string out = "";
	for (int i = 0; i < word.length(); i++) {
		out += tolower(word[i]);
	}
	return out;
}

string toUpper(string word)
{
	string out = "";
	for (int i = 0; i < word.length(); i++) {
		out += toupper(word[i]);
	}
	return out;
}

bool insertToFile(string path, Entry ent)
{
	fstream data_file;
	data_file.open(path, ios::app);
	if (data_file.good()) {
		data_file << ent;
		data_file.close();
		return true;
	}
	data_file.close();
	return false;
}

LinkedList<Entry>* readFromNode(string path)
{
	LinkedList<Entry>* list = new LinkedList<Entry>;
	string val = "";
	Entry obj;
	fstream node_file;
	node_file.open(path, ios::in);
	if (node_file.good()) {
		while (!node_file.eof()) {
			string line_path = "";
			string lno = "";
			int line_no = -1;
			getline(node_file, line_path);
			getline(node_file, lno);
			if (line_path != "" && lno != "" && line_path != " " && lno != " ") {
				line_no = stoi(lno);
				obj = readLine(line_path, line_no);
				list->insert(obj);
			}
		}
	}
	node_file.close();
	return list;
}

void updateLog(string tree)
{
	bool found = false;
	string val = "";
	int m;
	string root = "database/";
	// File Handling
	fstream data_file;
	data_file.open(root + "logs.txt", ios::in);
	if (data_file.good()) {
		while (!data_file.eof()) {
			val = "";
			data_file >> val;
			if (val == "B_ID" || val == "B_NAME" || val == "B_YEAR" || val == "B_CAUSE" || val == "B_STATE" || val == "B_DEATHS" || val == "B_AGE-ADJUSTED") {
				if (val == "B_AGE-ADJUSTED") {
					data_file >> val >> val;
					data_file >> m;
					if (("B_AGE-ADJUSTED DEATH RATE " + to_string(m)) == tree) {
						found = true;
						break;
					}
				} else {
					data_file >> m;
					if ((val + " " + to_string(m)) == tree) {
						found = true;
						break;
					}
				}
			} else if (val == "AVL_AGE-ADJUSTED" || val == "RNB_AGE-ADJUSTED") {
				data_file >> val >> val;
				if ("AVL_AGE-ADJUSTED DEATH RATE" == tree || "RNB_AGE-ADJUSTED DEATH RATE" == tree) {
					found = true;
					break;
				}
			} else if (val == tree) {
				found = true;
				break;
			}
		}
		data_file.close();
	}
	if (!found) {
		data_file.open(root + "logs.txt", ios::app);
		if (data_file.good()) {
			data_file << tree << endl;
		}
	}
	data_file.close();
}

#endif // !UTILS_H