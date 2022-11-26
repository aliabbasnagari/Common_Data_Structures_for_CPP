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
	string getState();
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

Entry::setId( int xd) {
	id = xd;
}Entry::setDeaths (int dd) {
	deaths = dd;
}
Entry::setCause(string cause) {
	cause_name = cause;
}
Entry::setCause113(string cause113) {
	cause_name_113 = cause113;

 }
Entry::setDeathRate(float dr) {
	death_rate = dr;
}
Entry::setState(string st) {
	state = st;
}
Entry::setYear(int yer) {
	year = yer;
}
int Entry::getId() {
	return id ;
}
int Entry::getDeaths() {
	return deaths;
}
string Entry::getCause() {
	return cause_name;
}
string Entry::getCause113() {
	return cause_name_113 ;

}
float Entry::getDeathRate() {
	return death_rate ;
}
string Entry::getState() {
	return state ;
}
int Entry::getYear() {
	return year ;
}