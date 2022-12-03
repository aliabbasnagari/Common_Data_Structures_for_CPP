/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/
#pragma once
#include <iostream>
using namespace std;

struct DataNode
{
	int id;
	string filepath;
	int line;
	string nodepath;

	bool operator<(int n) {
		if (this->id < n)
			return true;
		return false;
	}
	bool operator<(const DataNode& n) {
		if (this->id < n.id)
			return true;
		return false;
	}
	bool operator>(int n) {
		if (this->id > n)
			return true;
		return false;
	}
	bool operator>(const DataNode& n) {
		if (this->id > n.id)
			return true;
		return false;
	}
	friend ostream& operator<<(ostream& output, const DataNode&);
};

ostream& operator<<(ostream& out, const DataNode& dn)
{
	if (dn.id != -1)
		cout << dn.id << " - ";
	if (dn.filepath != "")
		cout << dn.filepath << " - ";
	if (dn.line != -1)
		cout << dn.line << " - ";
	if (dn.nodepath != "")
		cout << dn.nodepath << endl;
	return out;
}
