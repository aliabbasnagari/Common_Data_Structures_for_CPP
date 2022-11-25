/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/
#pragma once
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <typename T>
class TreeNode {
public:
	T value;
	TreeNode* left;
	TreeNode* right;

	TreeNode(T _v = 0, TreeNode* _l = NULL, TreeNode* _r = NULL) {
		value = _v;
		left = _l;
		right = _r;
	}
};

template <typename T>
class BSTree {
public:
	TreeNode<T>* root;

	BSTree() {
		root = NULL;
	}

	void insert(T _val) {
		TreeNode<T>* temp = new TreeNode<T>(_val);
		if (root == NULL) {
			root = temp;
		}
		else {
			TreeNode<T>* curr = root;
			while (curr != NULL) {
				if (_val > curr->value) {
					if (curr->right != NULL) {
						curr = curr->right;
					}
					else {
						curr->right = temp;
						break;
					}
				}
				else if (_val < curr->value) {
					if (curr->left != NULL) {
						curr = curr->left;
					}
					else {
						curr->left = temp;
						break;
					}
				}
			}
			curr = temp;
		}
	}

	int getHeight(TreeNode<T>* begin)
	{
		if (begin == NULL) {
			return 0;
		}
		else {
			int left = getHeight(begin->left);
			int right = getHeight(begin->right);

			if (right < left) {
				left++;
				return left;
			}
			else {
				right++;
				return right;
			}
		}
	}

	void InOrderTreversal(TreeNode<T>* begin) {
		if (begin != NULL) {
			InOrderTreversal(begin->left);
			cout << begin->value << " ";
			InOrderTreversal(begin->right);
		}
	}

	void PreOrderTreversal(TreeNode<T>* begin) {
		if (begin != NULL) {
			cout << begin->value << " ";
			PreOrderTreversal(begin->left);
			PreOrderTreversal(begin->right);
		}
	}

	void PostOrderTreversal(TreeNode<T>* begin) {
		if (begin != NULL) {
			PostOrderTreversal(begin->left);
			PostOrderTreversal(begin->right);
			cout << begin->value << " ";
		}
	}

	void SingleLevel(TreeNode<T>* root, int _cLevel) {
		if (root == NULL) {
			return;
		}
		if (_cLevel == 1) {
			cout << root->value << " ";
		}
		else if (_cLevel > 1) {
			int newLevel = _cLevel - 1;
			SingleLevel(root->left, newLevel);
			SingleLevel(root->right, newLevel);
		}
	}

	void LevelOrderTreversal(TreeNode<T>* begin) {
		int h = getHeight(begin);
		int i;
		for (i = 1; i <= 5; i++)
			SingleLevel(root, i);
	}

	bool retrive(T _val) {
		TreeNode<T>* start = root;
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

	T getMin(TreeNode<T>* _root) {
		TreeNode<T>* curr = _root;
		while (curr->left != NULL) {
			curr = curr->left;
		}
		return curr->value;
	}

	void Delete(T _val, TreeNode<T>* begin) {
		if (root->value == _val) {
			bool hl = 0, hr = 0;
			if (root->left == NULL)
				hl = true;
			if (root->right == NULL)
				hr = true;
			if (hl && hr) {
				delete root;
				root = NULL;
			}
			else if (hl) {
				cout << "1" << endl;
				TreeNode<T>* swapnode = root->right;
				delete root;
				root = swapnode;
				swapnode = NULL;
			}
			else if (hr) {
				cout << "2" << endl;
				TreeNode<T>* swapnode = root->left;
				delete root;
				root = swapnode;
				swapnode = NULL;
			}
			else {
				root->value = getMin(root->right);
				if (root->right->value == getMin(root->right)) {
					delete root->right;
					root->right = NULL;
				}
				else {
					TreeNode<T>* minnode = root->right;
					while (minnode->left->left != NULL) {
						minnode = minnode->left;
					}
					if (minnode->left->right != NULL) {
						TreeNode<T>* temp = minnode->left->right;
						minnode->left = temp;
						temp = NULL;
					}
					else {
						delete minnode->left;
						minnode->left = NULL;
					}
				}
			}
			return;
		}
		else {
			if (begin->left != NULL && begin->left->value == _val) {
				bool hl = 0, hr = 0;
				if (begin->left->left == NULL)
					hl = true;
				if (begin->left->right == NULL)
					hr = true;
				if (hl && hr) {
					delete begin->left;
					begin->left = NULL;
				}
				else if (hl) {
					TreeNode<T>* swapnode = begin->left->right;
					delete begin->left;
					begin->left = swapnode;
					swapnode = NULL;
				}
				else if (hr) {
					TreeNode<T>* swapnode = begin->left->left;
					delete begin->left;
					begin->left = swapnode;
					swapnode = NULL;
				}
				else {
					begin->left->value = getMin(begin->left->right);
					if (begin->left->right->value == getMin(begin->left->right)) {
						delete begin->left->right;
						begin->left->right = NULL;
					}
					else {
						TreeNode<T>* minnode = begin->left->right;
						while (minnode->left->left != NULL) {
							minnode = minnode->left;
						}
						if (minnode->left->right != NULL) {
							TreeNode<T>* temp = minnode->left->right;
							minnode->left = temp;
							temp = NULL;
						}
						else {
							delete minnode->left;
							minnode->left = NULL;
						}
					}
				}
				return;
			}
			else if (begin->right != NULL && begin->right->value == _val) {
				bool hl = 0, hr = 0;
				if (begin->right->left == NULL)
					hl = true;
				if (begin->right->right == NULL)
					hr = true;
				if (hl && hr) {
					delete begin->right;
					begin->right = NULL;
				}
				else if (hl) {
					TreeNode<T>* swapnode = begin->right->right;
					delete begin->right;
					begin->right = swapnode;
					swapnode = NULL;
				}
				else if (hr) {
					TreeNode<T>* swapnode = begin->right->left;
					delete begin->right;
					begin->right = swapnode;
					swapnode = NULL;
				}
				else {
					begin->right->value = getMin(begin->right->right);
					if (begin->right->right->value == getMin(begin->right->right)) {
						delete begin->right->right;
						begin->right->right = NULL;
					}
					else {
						TreeNode<T>* minnode = begin->right->right;
						while (minnode->left->left != NULL) {
							minnode = minnode->left;
						}
						if (minnode->left->right != NULL) {
							TreeNode<T>* temp = minnode->left->right;
							minnode->left = temp;
							temp = NULL;
						}
						else {
							delete minnode->left;
							minnode->left = NULL;
						}
					}
				}
				return;
			}
			else if (begin->value > _val)
				Delete(_val, begin->left);
			else
				Delete(_val, begin->right);
		}
	}

	~BSTree() {
		delete[] root;
	}
};

#endif !BST_H