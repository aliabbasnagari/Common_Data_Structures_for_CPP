#pragma once
#ifndef AVL_H
#define AVL_H
#include<iostream>
#include <sstream>
#include "Utils.h"
using namespace std;

template<typename T>
class AVLNode
{
public:
	T value;
	AVLNode<T>* left;
	AVLNode<T>* right;
	int height;

	AVLNode()
	{
		left = NULL;
		right = NULL;
		height = 0;
	}
	AVLNode(T n)
	{
		value = n;
		left = NULL;
		right = NULL;
		height = 0;
	}
};

template<typename T>
class AVLTree
{
public:
	AVLNode<T>* root;
	string key;
public:

	AVLTree()
	{
		root = NULL;
	}

	void insert(AVLNode<T> add)
	{
		FileNode node(add.value.filepath, add.value.line);
		string folder = "AVL_" + key;
		string file = "node" + to_string(add.value.id) + ".txt";
		add.value.nodepath = "database/" + folder + "/" + file;
		saveNode(folder, file, node);
		AVLinsert(add.value, root);
	}

	void DeleteNode(AVLNode<T> del)
	{
		AVLdelete(del.value, root);
	}

	AVLNode<T>* SingleRightRotation(AVLNode<T>*& temp)
	{
		AVLNode<T>* temp1 = temp->left;
		temp->left = temp1->right;

		temp1->right = temp;

		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		temp1->height = max(getHeight(temp1->left), temp->height) + 1;

		return temp1;
	}

	AVLNode<T>* SingleLeftRotation(AVLNode<T>*& temp)
	{
		//cout << temp->value << " " << temp->right->value << " " << temp->right->right->value << endl;
		AVLNode<T>* temp1 = temp->right;
		//cout << temp1->value << endl;
		temp->right = temp1->left;

		temp1->left = temp;
		//cout << temp1->left->value << " " << temp1->value << " " << temp1->right->value << endl;

		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		temp1->height = max(getHeight(temp1->right), temp->height) + 1;


		return temp1;
	}

	AVLNode<T>* DoubleRightRotation(AVLNode<T>*& temp)
	{
		temp->left = SingleLeftRotation(temp->left);					//rotate left
		return SingleRightRotation(temp);						//rotate right
	}

	AVLNode<T>* DoubleLeftRotation(AVLNode<T>*& temp)
	{
		temp->right = SingleRightRotation(temp->right);				//rotate right
		return SingleLeftRotation(temp);						//rotate left
	}

	AVLNode<T>* getMinNode(AVLNode<T>*& temp) //reutrn value of smallest node in the given tree
	{
		AVLNode<T>* movernode = temp;
		while (movernode->left != NULL)
			movernode = movernode->left;

		return movernode;
	}

	int BalanceFactor(AVLNode<T>* temp)
	{
		if (temp == NULL)
			return 0;
		else
			return ((getHeight(temp->left)) - (getHeight(temp->right)));
	}

	AVLNode<T>* AVLinsert(T val, AVLNode<T>*& temp)
	{
		if (temp == NULL)  // Create and return a single tree 
		{
			temp = new AVLNode<T>;
			temp->value = val;
			temp->left = temp->right = NULL;
		} else if (val < temp->value) {
			temp->left = AVLinsert(val, temp->left);
		} else if (val > temp->value) {
			temp->right = AVLinsert(val, temp->right);
		} // If val is in the tree already; we'll do nothing as we don't create duplicates

		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		int bf = BalanceFactor(temp); //checking balance factor for rotation if its not between -1 and 1

		if (bf > 1 && val < temp->left->value) //RotateRight
		{
			temp = SingleRightRotation(temp);
		} else if (bf < -1 && val > temp->right->value) //RotateLeft
		{
			//cout << "BEFORE ROTATION RIGHT RIGHT RIGHT: " << temp->value << " " << temp->right->value << " " << temp->right->right->value << endl;
			temp = SingleLeftRotation(temp);
			//cout << "AFTER ROTATION LEFT CENTER RIGHT: " <<temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		} else if (bf > 1 && val > temp->left->value) //DoubleRotateRight A.K.A RIGHT-LEFT ROTATION FIRST LEFT THEN RIGHT
		{
			temp = DoubleRightRotation(temp);
			//cout << temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		} else if (bf < -1 && val < temp->right->value) //DoubleRotateLeft A.K.A LEFT-RIGHT ROTATION FIRST RIGHT THEN LEFT
		{
			temp = DoubleLeftRotation(temp);
			//cout << temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		}

		return temp;
	}

	AVLNode<T>* AVLdelete(T val, AVLNode<T>*& temp)
	{

		if (temp == NULL)  // Base Case 
		{
			return temp;
		} else if (val < temp->value) //go left
		{
			temp->left = AVLdelete(val, temp->left);
		} else if (val > temp->value) //go right
		{
			temp->right = AVLdelete(val, temp->right);
		} else //value matches so perform deleteion
		{
			if ((temp->left == NULL) && (temp->right == NULL)) //no child
			{
				AVLNode<T>* tempnode = temp;
				temp = temp->right;
				delete tempnode;
			} else if ((temp->left == NULL) && (temp->right != NULL)) //one child on right
			{
				AVLNode<T>* tempnode = temp;
				temp = temp->right;
				delete tempnode;
			} else if ((temp->right == NULL) && (temp->left != NULL)) //one child on left
			{
				AVLNode<T>* tempnode = temp;
				temp = temp->left;
				delete tempnode;
			} else if ((temp->left != NULL) && (temp->right != NULL))//two children
			{
				AVLNode<T>* tempnode = getMinNode(temp->right);
				temp->value = tempnode->value;
				temp->right = AVLdelete(tempnode->value, temp->right);
			}
		}


		if (temp == NULL) //only one node in whole tree so return
			return temp;

		//Same work as before, balancing tree and performing rotations but this time check the balance factors rather than values

		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		int bf = BalanceFactor(temp); //checking balance factor for rotation if its not between -1 and 1

		if ((bf > 1) && (BalanceFactor(temp->left) >= 0)) //RotateRight
		{
			temp = SingleRightRotation(temp);
		} else if ((bf < -1) && (BalanceFactor(temp->right) <= 0)) //RotateLeft
		{
			temp = SingleLeftRotation(temp);
			//cout << "AFTER ROTATION LEFT CENTER RIGHT: " <<temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		} else if ((bf < -1) && (BalanceFactor(temp->right) > 0)) //DoubleRotateRight A.K.A RIGHT-LEFT ROTATION FIRST LEFT THEN RIGHT
		{
			temp = DoubleRightRotation(temp);
			//cout << temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		} else if ((bf > 1) && (BalanceFactor(temp->left) < 0)) //DoubleRotateLeft A.K.A LEFT-RIGHT ROTATION FIRST RIGHT THEN LEFT
		{
			temp = DoubleLeftRotation(temp);
			//cout << temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		}

		return temp;
	}

	void Inorder(AVLNode<T>* temproot)
	{
		if (temproot != NULL) {
			Inorder(temproot->left);
			cout << temproot->value << " ";
			Inorder(temproot->right);
		}
	}

	void PreOrder(AVLNode<T>* _node)
	{
		if (_node != NULL) {
			cout << _node->value << " ";
			PreOrder(_node->left);
			PreOrder(_node->right);
		}
	}

	void PostOrder(AVLNode<T>* _node)
	{
		if (_node != NULL) {
			PostOrder(_node->left);
			PostOrder(_node->right);
			cout << _node->value << " ";
		}
	}

	void SingleLevel(AVLNode<T>* root, int _cLevel)
	{
		if (root == NULL) {
			return;
		}
		if (_cLevel == 1) {
			cout << root->value << " ";
		} else if (_cLevel > 1) {
			int newLevel = _cLevel - 1;
			SingleLevel(root->left, newLevel);
			SingleLevel(root->right, newLevel);
		}
	}

	void LevelOrderTreversal(AVLNode<T>* begin)
	{
		int h = getHeight(begin);
		int i;
		for (i = 1; i <= h; i++) {
			SingleLevel(root, i);
			cout << endl;
		}
	}

	bool retrive(T _val)
	{
		AVLNode<T>* start = root;
		while (start != NULL) {
			if (start->value == _val)
				return true;
			else if (start->value > _val)
				start = start->left;
			else
				start = start->right;
		}
		return false;
	}

	int getHeight(AVLNode<T>* _node)
	{
		if (_node == NULL)
			return 0;
		else
			return _node->height;
	}

	int max(int _left, int _right)
	{
		if (_left > _right)
			return _left;
		else
			return _right;
	}

	LinkedList<Entry>* searchID(int id)
	{
		AVLNode<T>* temp = root;
		LinkedList<Entry>* llist = NULL;
		if (root != NULL && id == root->value.id) {
			llist = readFromNode(root->value.nodepath);
			return llist;
		} else if (temp != NULL) {
			while (temp != NULL) {
				if (id == temp->value.id) {
					llist = readFromNode(temp->value.nodepath);
					return llist;
				} else if (id < temp->value.id) {
					temp = temp->left;
				} else if (id > temp->value.id) {
					temp = temp->right;
				}
			}

		}
		cout << "Not Found!" << endl;
		return llist;
	}

	void getQuery(string query)
	{
		string field;
		string key_data;
		int start = query.find("<");
		int end = query.find(">");
		start++;
		field = query.substr(start, (end - start));
		start = query.find('#');
		end = query.length();
		start++;
		key_data = query.substr(start, (end - start));
		key_data = fullTrim(key_data);
		string key_value = split(key_data, '=');
		int sid = 0;
		if (key == "ID")
			sid = stoi(key_value);
		else
			sid = int_of_str(key_value);

		LinkedList<Entry>* ent = searchID(sid);

		stringstream fields(field);
		while (!fields.eof()) {
			getline(fields, field, ',');
			if (toLower(field) == "id")
				cout << "Id = " << ent.id << endl;
			else if (toLower(field) == "year")
				cout << "Year = " << ent.year << endl;
			if (toLower(field) == "cause")
				cout << "Cause = " << ent.cause_name << endl;
			else if (toLower(field) == "state")
				cout << "State = " << ent.state << endl;
			else if (toLower(field) == "deaths")
				cout << "Deaths = " << ent.deaths << endl;
			else if (toLower(field) == "age-adjusted death rate")
				cout << "Age-adjusted Death Rate = " << ent.death_rate << endl;
		}
	}

	void getQueryrange(string query)
	{
		string field;
		string data;
		int start = query.find("<");
		int end = query.find(">");
		start++;
		field = query.substr(start, (end - start));
		start = query.find('#');
		end = query.length();
		start++;
		data = query.substr(start, (end - start));
		data = fullTrim(data);
		string dat = split(data, '=');
		string ranger = split(dat, '-'); // I added this line
		searchIDrange(stoi(dat), stoi(ranger), field); //I modified this line
		// I added this line

	}

	void searchIDrange(int id, int id2, string field)
	{
		string newField = field;
		Entry ent;
		for (int i = id; i <= id2; i++) {
			ent = searchID(i);
			stringstream fields(field);
			while (!fields.eof()) {
				getline(fields, newField, ',');
				if (toLower(newField) == "id")
					cout << "Id = " << ent.id << endl;
				else if (toLower(newField) == "year")
					cout << "Year = " << ent.year << endl;
				if (toLower(newField) == "cause")
					cout << "Cause = " << ent.cause_name << endl;
				else if (toLower(newField) == "state")
					cout << "State = " << ent.state << endl;
				else if (toLower(newField) == "deaths")
					cout << "Deaths = " << ent.deaths << endl;
				else if (toLower(newField) == "age-adjusted death rate")
					cout << "Age-adjusted Death Rate = " << ent.death_rate << endl;
			}
			cout << endl;
		}
	}
};
#endif // !AVL_H