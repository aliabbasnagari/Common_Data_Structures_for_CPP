/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/
#pragma once
#ifndef BTREE_H
#define BTREE_H

#include <iostream>
using namespace std;

template <typename T>
class BTreeNode {
public:
	T* keys;
	int t;
	BTreeNode<T>** C;
	int n;
	bool leaf;

public:
	BTreeNode<T>(int _t, bool _leaf)
	{
		t = _t;
		leaf = _leaf;
		int newSize = (2 * t) - 1;
		cout << "NS = " << newSize << endl;
		keys = new T[newSize];
		C = new BTreeNode * [2 * t];
		n = 0;
	}
	void traverse()
	{
		int i;
		for (i = 0; i < n; i++) {
			if (leaf == false)
				C[i]->traverse();
			cout << " " << keys[i];
		}

		if (leaf == false)
			C[i]->traverse();
	}
	int findKey(int k)
	{
		int idx = 0;
		while (idx < n && keys[idx] < k)
			++idx;
		return idx;
	}
	void insertNonFull(T k)
	{
		int i = n - 1;

		if (leaf == true) {
			while (i >= 0 && keys[i] > k) {
				keys[i + 1] = keys[i];
				i--;
			}

			keys[i + 1] = k;
			n = n + 1;
		} else {
			while (i >= 0 && keys[i] > k)
				i--;

			if (C[i + 1]->n == 2 * t - 1) {
				splitChild(i + 1, C[i + 1]);

				if (keys[i + 1] < k)
					i++;
			}
			C[i + 1]->insertNonFull(k);
		}
	}
	void splitChild(int i, BTreeNode* y)
	{
		BTreeNode* z = new BTreeNode<T>(y->t, y->leaf);
		z->n = t - 1;

		for (int j = 0; j < t - 1; j++)
			z->keys[j] = y->keys[j + t];

		if (y->leaf == false) {
			for (int j = 0; j < t; j++)
				z->C[j] = y->C[j + t];
		}

		y->n = t - 1;

		for (int j = n; j >= i + 1; j--)
			C[j + 1] = C[j];

		C[i + 1] = z;

		for (int j = n - 1; j >= i; j--)
			keys[j + 1] = keys[j];

		keys[i] = y->keys[t - 1];

		n = n + 1;
	}
	void deletion(int k)
	{
		int idx = findKey(k);

		if (idx < n && keys[idx] == k) {
			if (leaf)
				removeFromLeaf(idx);
			else
				removeFromNonLeaf(idx);
		} else {
			if (leaf) {
				cout << "The key " << k << " is does not exist in the tree\n";
				return;
			}

			bool flag = ((idx == n) ? true : false);

			if (C[idx]->n < t)
				fill(idx);

			if (flag && idx > n)
				C[idx - 1]->deletion(k);
			else
				C[idx]->deletion(k);
		}
		return;
	}
	void removeFromLeaf(int idx)
	{
		for (int i = idx + 1; i < n; ++i)
			keys[i - 1] = keys[i];

		n--;

		return;
	}
	void removeFromNonLeaf(int idx)
	{
		int k = keys[idx];

		if (C[idx]->n >= t) {
			int pred = getPredecessor(idx);
			keys[idx] = pred;
			C[idx]->deletion(pred);
		}

		else if (C[idx + 1]->n >= t) {
			int succ = getSuccessor(idx);
			keys[idx] = succ;
			C[idx + 1]->deletion(succ);
		}

		else {
			merge(idx);
			C[idx]->deletion(k);
		}
		return;
	}
	int getPredecessor(int idx)
	{
		BTreeNode* cur = C[idx];
		while (!cur->leaf)
			cur = cur->C[cur->n];

		return cur->keys[cur->n - 1];
	}
	int getSuccessor(int idx)
	{
		BTreeNode* cur = C[idx + 1];
		while (!cur->leaf)
			cur = cur->C[0];

		return cur->keys[0];
	}
	void fill(int idx)
	{
		if (idx != 0 && C[idx - 1]->n >= t)
			borrowFromPrev(idx);

		else if (idx != n && C[idx + 1]->n >= t)
			borrowFromNext(idx);

		else {
			if (idx != n)
				merge(idx);
			else
				merge(idx - 1);
		}
		return;
	}
	void borrowFromPrev(int idx)
	{
		BTreeNode* child = C[idx];
		BTreeNode* sibling = C[idx - 1];

		for (int i = child->n - 1; i >= 0; --i)
			child->keys[i + 1] = child->keys[i];

		if (!child->leaf) {
			for (int i = child->n; i >= 0; --i)
				child->C[i + 1] = child->C[i];
		}

		child->keys[0] = keys[idx - 1];

		if (!child->leaf)
			child->C[0] = sibling->C[sibling->n];

		keys[idx - 1] = sibling->keys[sibling->n - 1];

		child->n += 1;
		sibling->n -= 1;

		return;
	}
	void borrowFromNext(int idx)
	{
		BTreeNode* child = C[idx];
		BTreeNode* sibling = C[idx + 1];

		child->keys[(child->n)] = keys[idx];

		if (!(child->leaf))
			child->C[(child->n) + 1] = sibling->C[0];

		keys[idx] = sibling->keys[0];

		for (int i = 1; i < sibling->n; ++i)
			sibling->keys[i - 1] = sibling->keys[i];

		if (!sibling->leaf) {
			for (int i = 1; i <= sibling->n; ++i)
				sibling->C[i - 1] = sibling->C[i];
		}

		child->n += 1;
		sibling->n -= 1;

		return;
	}
	void merge(int idx)
	{
		BTreeNode* child = C[idx];
		BTreeNode* sibling = C[idx + 1];

		child->keys[t - 1] = keys[idx];

		for (int i = 0; i < sibling->n; ++i)
			child->keys[i + t] = sibling->keys[i];

		if (!child->leaf) {
			for (int i = 0; i <= sibling->n; ++i)
				child->C[i + t] = sibling->C[i];
		}

		for (int i = idx + 1; i < n; ++i)
			keys[i - 1] = keys[i];

		for (int i = idx + 2; i <= n; ++i)
			C[i - 1] = C[i];

		child->n += sibling->n + 1;
		n--;

		delete (sibling);
		return;
	}
};

template <typename T>
class BTree {
public:
	BTreeNode<T>* root;
	int t;
	string key;

public:
	BTree(int _t)
	{
		root = NULL;
		t = _t;
	}

	void traverse()
	{
		if (root != NULL)
			root->traverse();
	}

	void insertion(T k)
	{
		if (root == NULL) {
			root = new BTreeNode<T>(t, true);
			root->keys[0] = k;
			root->n = 1;
		} else {
			if (root->n == 2 * t - 1) {
				BTreeNode<T>* s = new BTreeNode<T>(t, false);

				s->C[0] = root;

				s->splitChild(0, root);

				int i = 0;
				if (s->keys[0] < k)
					i++;
				s->C[i]->insertNonFull(k);

				root = s;
			} else
				root->insertNonFull(k);
		}
	}
	void deletion(int k)
	{
		if (!root) {
			cout << "The tree is empty\n";
			return;
		}

		root->deletion(k);

		if (root->n == 0) {
			BTreeNode* tmp = root;
			if (root->leaf)
				root = NULL;
			else
				root = root->C[0];

			delete tmp;
		}
		return;
	}
};

#endif !BTREE