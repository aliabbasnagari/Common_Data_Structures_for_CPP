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
};

#endif !BST_H