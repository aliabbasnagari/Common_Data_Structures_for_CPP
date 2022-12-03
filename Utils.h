#pragma once
/* All Utility Functions */
#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "Entry.h"
#include "Header.h"
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
			if (temp != "")
			{
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

void saveNode(string path, string data) {
	string val = "";
	// File Handling
	fstream data_file;
	data_file.open(path, ios::out);
	if (data_file.good())
	{
		data_file << data << endl;
	}
	data_file.close();
}

Entry readLine(string path, int line) {
	string val = "";
	Entry obj;
	// File Handling
	fstream data_file;
	data_file.open(path, ios::in);
	int curr_line = 0;
	if (data_file.good())
	{
		while (!data_file.eof() && curr_line <= line)
		{
			string temp = "";
			int id = 0;
			int year = 0;
			int deaths = 0;
			float death_rate = 0;
			string cause_113 = "";
			string cause = "";
			string state = "";

			getline(data_file, temp, ',');
			if (temp !="ID" && temp != " " && temp != "")
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
	return obj;
}

	string getPath(string path) {
		string val = "";
		fstream data_file;
		data_file.open(path, ios::in);
		if (data_file.good())
		{
			getline(data_file, val);
		}
		return val;
	}

	int getLine(string path) {
		string val = "";
		fstream data_file;
		data_file.open(path, ios::in);
		if (data_file.good())
		{
			getline(data_file, val);
			getline(data_file, val);
		}
		return stoi(val);
	}
	string split(string& str, char sep) {
		int currentIndex = 0, i = 0, j = 0;
		int startIndex = 0, endIndex = 0;
		string subStr = "";
		while (str[i] != sep)
			i++;
		j = i;
		i++;
		while (i < str.length())
		{
			subStr += str[i];
			i++;
		}
		str.erase(j, str.length());
		return subStr;
	}

	// Helping functions
	// Trim extra spaces from starting of a string
	string trim(string text) {
		int begin = 0;
		while (text[begin] == 10 || text[begin] == 9 || text[begin] == ' ')
			begin++;
		text.erase(0, begin);
		return text;
	}

	// Trim extra spaces from both ends of a string
	string fullTrim(string text) {
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

	string toLower(string word) {
		string out = "";
		for (int i = 0; i < word.length(); i++)
		{
			out += tolower(word[i]);
		}
		return out;
	}