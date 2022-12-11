#pragma once
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
using namespace std;

template <class T>
struct RBNode {
	T data;
	RBNode<T>* parent;
	RBNode<T>* left;
	RBNode<T>* right;
	bool color; // 0 for red, 1 for black
};

template <typename T>
class RedBlackTree {
private:
	RBNode<T>* root;
	RBNode<T>* null_node;
public:
	string key;
	RedBlackTree()
	{
		null_node = new RBNode<T>;
		null_node->color = 0;
		null_node->left = NULL;
		null_node->right = NULL;
		root = null_node;
	}

	void preOrder(RBNode<T>* node)
	{
		if (node != null_node) {
			cout << node->data << " , ";
			preOrderRecursion(node->left);
			preOrderRecursion(node->right);
		}
	}

	void inOrder(RBNode<T>* node)
	{
		if (node != null_node) {
			inOrderRecursion(node->left);
			cout << node->data << " , ";
			inOrderRecursion(node->right);
		}
	}

	void postOrder(RBNode<T>* node)
	{
		if (node != null_node) {
			postOrderRecursion(node->left);
			postOrderRecursion(node->right);
			cout << node->data << " , ";
		}
	}

	RBNode<T>* searchTree(int k)
	{
		return searchTreeHelper(this->root, k);
	}

	RBNode<T>* getMin(RBNode<T>* node)
	{
		while (node->left != null_node) {
			node = node->left;
		}
		return node;
	}

	RBNode<T>* getMax(RBNode<T>* node)
	{
		while (node->right != null_node) {
			node = node->right;
		}
		return node;
	}

	RBNode<T>* successor(RBNode<T>* x)
	{
		if (x->right != null_node) {
			return getMin(x->right);
		}

		RBNode<T>* y = x->parent;
		while (y != null_node && x == y->right) {
			x = y;
			y = y->parent;
		}
		return y;
	}

	RBNode<T>* predecessor(RBNode<T>* x)
	{
		if (x->left != null_node) {
			return getMax(x->left);
		}

		RBNode<T>* y = x->parent;
		while (y != null_node && x == y->left) {
			x = y;
			y = y->parent;
		}

		return y;
	}

	void leftRotate(RBNode<T>* x)
	{
		RBNode<T>* y = x->right;
		x->right = y->left;
		if (y->left != null_node) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	void rightRotate(RBNode<T>* x)
	{
		RBNode<T>* y = x->left;
		x->left = y->right;
		if (y->right != null_node) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	void insert(T _val)
	{

		FileNode fnode(_val.filepath, _val.line);
		string folder = "RNB_" + key;
		string file = "node" + to_string(_val.id) + ".txt";
		_val.nodepath = "database/" + folder + "/" + file;
		saveNode(folder, file, fnode);

		RBNode<T>* node = new RBNode<T>;
		node->parent = nullptr;
		node->data = _val;
		node->left = null_node;
		node->right = null_node;
		node->color = 1;

		RBNode<T>* y = nullptr;
		RBNode<T>* x = this->root;

		while (x != null_node) {
			y = x;
			if (node->data < x->data) {
				x = x->left;
			} else {
				x = x->right;
			}
		}

		node->parent = y;
		if (y == nullptr) {
			root = node;
		} else if (node->data < y->data) {
			y->left = node;
		} else {
			y->right = node;
		}

		if (node->parent == nullptr) {
			node->color = 0;
			return;
		}

		if (node->parent->parent == nullptr) {
			return;
		}

		insertFix(node);
	}

	RBNode<T>* getRoot()
	{
		return this->root;
	}

	void deleteNode(T data)
	{
		deleteNodeHelper(this->root, data);
	}

	void printTree()
	{
		if (root) {
			printHelper(this->root, "", true);
		}
	}

	void emptyNode(RBNode<T>* node, RBNode<T>* parent)
	{
		node->data = 0;
		node->color = 0;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
	}

	RBNode<T>* searchTreeHelper(RBNode<T>* node, int key)
	{
		if (node == null_node || key == node->data)
			return node;
		if (key < node->data)
			return searchTreeHelper(node->left, key);
		return searchTreeHelper(node->right, key);
	}

	void balanceDeletion(RBNode<T>* _node)
	{
		RBNode<T>* temp;
		while (_node != root && _node->color == 0) {
			if (_node == _node->parent->left) {
				temp = _node->parent->right;
				if (temp->color == 1) {
					temp->color = 0;
					_node->parent->color = 1;
					leftRotate(_node->parent);
					temp = _node->parent->right;
				}

				if (temp->left->color == 0 && temp->right->color == 0) {
					temp->color = 1;
					_node = _node->parent;
				} else {
					if (temp->right->color == 0) {
						temp->left->color = 0;
						temp->color = 1;
						rightRotate(temp);
						temp = _node->parent->right;
					}

					temp->color = _node->parent->color;
					_node->parent->color = 0;
					temp->right->color = 0;
					leftRotate(_node->parent);
					_node = root;
				}
			} else {
				temp = _node->parent->left;
				if (temp->color == 1) {
					temp->color = 0;
					_node->parent->color = 1;
					rightRotate(_node->parent);
					temp = _node->parent->left;
				}

				if (temp->right->color == 0 && temp->right->color == 0) {
					temp->color = 1;
					_node = _node->parent;
				} else {
					if (temp->left->color == 0) {
						temp->right->color = 0;
						temp->color = 1;
						leftRotate(temp);
						temp = _node->parent->left;
					}

					temp->color = _node->parent->color;
					_node->parent->color = 0;
					temp->left->color = 0;
					rightRotate(_node->parent);
					_node = root;
				}
			}
		}
		_node->color = 0;
	}

	void rbTransplant(RBNode<T>* u, RBNode<T>* v)
	{
		if (u->parent == nullptr) {
			root = v;
		} else if (u == u->parent->left) {
			u->parent->left = v;
		} else {
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void deleteNodeHelper(RBNode<T>* node, int key)
	{
		RBNode<T>* temp = null_node;
		RBNode<T>* tmp_node1, tmp_node2;
		while (node != null_node) {
			if (node->data == key) {
				temp = node;
			}

			if (node->data <= key) {
				node = node->right;
			} else {
				node = node->left;
			}
		}

		if (temp == null_node) {
			cout << "Key not found in the tree" << endl;
			return;
		}

		tmp_node2 = temp;
		int y_original_color = tmp_node2->color;
		if (temp->left == null_node) {
			tmp_node1 = temp->right;
			rbTransplant(temp, temp->right);
		} else if (temp->right == null_node) {
			tmp_node1 = temp->left;
			rbTransplant(temp, temp->left);
		} else {
			tmp_node2 = getMin(temp->right);
			y_original_color = tmp_node2->color;
			tmp_node1 = tmp_node2->right;
			if (tmp_node2->parent == temp) {
				tmp_node1->parent = tmp_node2;
			} else {
				rbTransplant(tmp_node2, tmp_node2->right);
				tmp_node2->right = temp->right;
				tmp_node2->right->parent = tmp_node2;
			}

			rbTransplant(temp, tmp_node2);
			tmp_node2->left = temp->left;
			tmp_node2->left->parent = tmp_node2;
			tmp_node2->color = temp->color;
		}
		delete temp;
		if (y_original_color == 0) {
			balanceDeletion(tmp_node1);
		}
	}

	void insertFix(RBNode<T>* _node)
	{
		RBNode<T>* temp;
		while (_node->parent->color == 1) {
			if (_node->parent == _node->parent->parent->right) {
				temp = _node->parent->parent->left;
				if (temp->color == 1) {
					temp->color = 0;
					_node->parent->color = 0;
					_node->parent->parent->color = 1;
					_node = _node->parent->parent;
				} else {
					if (_node == _node->parent->left) {
						_node = _node->parent;
						rightRotate(_node);
					}
					_node->parent->color = 0;
					_node->parent->parent->color = 1;
					leftRotate(_node->parent->parent);
				}
			} else {
				temp = _node->parent->parent->right;
				if (temp->color == 1) {
					temp->color = 0;
					_node->parent->color = 0;
					_node->parent->parent->color = 1;
					_node = _node->parent->parent;
				} else {
					if (_node == _node->parent->right) {
						_node = _node->parent;
						leftRotate(_node);
					}
					_node->parent->color = 0;
					_node->parent->parent->color = 1;
					rightRotate(_node->parent->parent);
				}
			}
			if (_node == root)
				break;
		}
		root->color = 0;
	}

	void printHelper(RBNode<T>* root, string indent, bool last)
	{
		if (root != null_node) {
			cout << indent;
			if (last) {
				cout << "R----";
				indent += "   ";
			} else {
				cout << "L----";
				indent += "|  ";
			}

			string sColor = root->color ? "RED" : "BLACK";
			cout << root->data << "(" << sColor << ")" << endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}
};

#endif // !REDBLACKTREE_H