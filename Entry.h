#pragma once
#include <iostream>
using namespace std;

class Entry {
public:
	int id;
	int year;
	int deaths;
	float death_rate;
	string cause_name_113;
	string cause_name;
	string state;
public:
	Entry(int, int, string, string, string, int, float);
	void setId(int);
	void setYear(int);
	void setDeaths(int);
	void setDeathRate(float);
	void setCause(string);
	void setCause113(string);
	void setState(string);
	int getId();
	int getYear();
	int getDeaths();
	float getDeathRate();
	string getCause();
	string getCause113();
};

Entry::Entry(int _id = 0, int _yr = 0, string _cn = "", string _cn1 = "", string _st = "", int _dt = 0, float _dr = 0) {
	id = _id;
	year = _yr;
	cause_name_113 = _cn1;
	cause_name = _cn;
	state = _st;
	deaths = _dt;
	death_rate = _dr;
};
