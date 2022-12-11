/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/
#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

struct DataNode
{
	int id;
	string filepath;
	int line;
	string nodepath;

	bool operator<(int n)
	{
		if (this->id < n)
			return true;
		return false;
	}
	bool operator<(const DataNode& n)
	{
		if (this->id < n.id)
			return true;
		return false;
	}
	bool operator>(int n)
	{
		if (this->id > n)
			return true;
		return false;
	}
	bool operator>(const DataNode& n)
	{
		if (this->id > n.id)
			return true;
		return false;
	}
	friend ostream& operator<<(ostream& output, const DataNode&);
};

ostream& operator<<(ostream& out, const DataNode& dn)
{
	cout << "__________________________________\n";
	if (dn.id != -1)
		cout << dn.id << " - ";
	if (dn.filepath != "")
		cout << dn.filepath << " - ";
	if (dn.line != -1)
		cout << dn.line << " - ";
	if (dn.nodepath != "")
		cout << dn.nodepath << endl;
	cout << endl; 
	cout << "__________________________________\n";
	return out;
}

struct FileNode
{
	string node_path;
	int line;
	FileNode()
	{
		node_path = "";
		line = -1;
	}
	FileNode(string path, int _line)
	{
		node_path = path;
		line = _line;
	}
	bool operator==(FileNode& fn)
	{
		if (this->line == fn.line && this->node_path == fn.node_path)
			return true;
		return false;
	}
	friend ostream& operator<<(ostream& output, const FileNode&);
	friend istream& operator>>(istream& input, FileNode&);
};

ostream& operator<<(ostream& out, const FileNode& fn)
{
	if (fn.node_path != "")
		out << fn.node_path << endl;
	if (fn.line != -1)
		out << fn.line << endl;
	return out;
}

istream& operator>>(istream& input, FileNode& fn)
{
	input >> fn.node_path;
	input >> fn.line;
	return input;
}
#endif // !HEADER_H