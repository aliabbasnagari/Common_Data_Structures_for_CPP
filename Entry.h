#pragma once
#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <iomanip>
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
	bool operator==(Entry&);
	operator string() const;
	void display();
	friend ostream& operator<<(ostream& output, const Entry&);
	void setValues(string);
};

Entry::Entry(int _id = 0, int _yr = 0, string _cn = "", string _cn1 = "", string _st = "", int _dt = 0, float _dr = 0)
{
	id = _id;
	year = _yr;
	cause_name_113 = _cn1;
	cause_name = _cn;
	state = _st;
	deaths = _dt;
	death_rate = _dr;
};
void Entry::display()
{
	cout << id << " , " << year << " , " << cause_name_113 << " , " << cause_name << " , " << state << " , " << deaths << " , " << death_rate << endl;
}

bool Entry::operator==(Entry& ent)
{
	return (id == ent.id && year == ent.year && cause_name_113 == ent.cause_name_113 && cause_name == ent.cause_name && state == ent.state && deaths == ent.deaths && death_rate == ent.death_rate);
}

void Entry::setId(int xd)
{
	id = xd;
}
void Entry::setDeaths(int dd)
{
	deaths = dd;
}
void Entry::setCause(string cause)
{
	cause_name = cause;
}
void Entry::setCause113(string cause113)
{
	cause_name_113 = cause113;

}
void Entry::setDeathRate(float dr)
{
	death_rate = dr;
}
void Entry::setState(string st)
{
	state = st;
}
void Entry::setYear(int yer)
{
	year = yer;
}
int Entry::getId()
{
	return id;
}
int Entry::getDeaths()
{
	return deaths;
}
string Entry::getCause()
{
	return cause_name;
}
string Entry::getCause113()
{
	return cause_name_113;

}
float Entry::getDeathRate()
{
	return death_rate;
}
string Entry::getState()
{
	return state;
}
int Entry::getYear()
{
	return year;
}

void Entry::setValues(string val)
{
	string cause;
	string temp;
	stringstream sstream(val);
	bool found = false;
	getline(sstream, temp, ',');
	id = stoi(temp);
	getline(sstream, temp, ',');
	year = stoi(temp);
	getline(sstream, temp, ',');
	if (temp[0] == '\"')
		found = true;
	while (found) {
		cause += temp;
		getline(sstream, temp, ',');
		if (temp.find('\"') != -1)
			found = false;
		else
			temp += ',';
	}
	cause += temp;
	cause += temp;
	cause_name_113 = cause;
	getline(sstream, temp, ',');
	cause_name = temp;
	getline(sstream, temp, ',');
	state = temp;
	getline(sstream, temp, ',');
	deaths = stoi(temp);
	getline(sstream, temp, ',');
	death_rate = stof(temp);
}

Entry::operator string() const
{
	string rate = to_string(death_rate);
	if (rate.find('.') != -1)
		rate = rate.substr(0, rate.find(".") + 2);
	return to_string(id) + "," + to_string(year) + "," + cause_name_113 + "," + cause_name + "," + state + "," + to_string(deaths) + "," + rate + (char)10;
}

ostream& operator<<(ostream& out, const Entry& ent)
{
	out << ent.id << "," << ent.year << "," << ent.cause_name_113 << "," << ent.cause_name << "," << ent.state << "," << ent.deaths << "," << ent.death_rate << endl;
	return out;
}
#endif // !ENTRY_H

