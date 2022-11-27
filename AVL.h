#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	T value;
	Node<T>* left;
	Node<T>* right;
	int height;

	Node()
	{
		left = NULL;
		right = NULL;
	}
	Node(T n)
	{
		value = n;
		left = NULL;
		right = NULL;
	}
};

int GetHeight(Node<int>* r)
{
	if (r == NULL)
	{
		return 0;
	}
	else
	{
		return r->height;
	}
}

int max(int l, int r)
{

	if (l > r)
	{
		return l;
	}
	else
	{
		return r;
	}
}

template<typename S>
class AVL
{
public:

	Node<S>* root;

public:

	AVL()
	{
		root = NULL;
	}

	void InsertNode(Node<S> add)
	{
		AVLinsert(add.value, root);
	}

	void DeleteNode(Node<S> del)
	{
		AVLdelete(del.value, root);
	}

	Node<S>* SingleRightRotation(Node<S>*& temp)
	{
		Node<S>* temp1 = temp->left;
		temp->left = temp1->right;

		temp1->right = temp;

		temp->height = max(GetHeight(temp->left), GetHeight(temp->right)) + 1;
		temp1->height = max(GetHeight(temp1->left), temp->height) + 1;

		return temp1;
	}

	Node<S>* SingleLeftRotation(Node<S>*& temp)
	{
		//cout << temp->value << " " << temp->right->value << " " << temp->right->right->value << endl;
		Node<S>* temp1 = temp->right;
		//cout << temp1->value << endl;
		temp->right = temp1->left;

		temp1->left = temp;
		//cout << temp1->left->value << " " << temp1->value << " " << temp1->right->value << endl;

		temp->height = max(GetHeight(temp->left), GetHeight(temp->right)) + 1;
		temp1->height = max(GetHeight(temp1->right), temp->height) + 1;


		return temp1;
	}

	Node<S>* DoubleRightRotation(Node<S>*& temp)
	{
		temp->left = SingleLeftRotation(temp->left);					//rotate left
		return SingleRightRotation(temp);						//rotate right
	}

	Node<S>* DoubleLeftRotation(Node<S>*& temp)
	{
		temp->right = SingleRightRotation(temp->right);				//rotate right
		return SingleLeftRotation(temp);						//rotate left
	}

	Node<S>* SmallestNodeValue(Node<S>*& temp) //reutrn value of smallest node in the given tree
	{
		Node<S>* movernode = temp;

		while (movernode != NULL)
		{
			movernode = movernode->left;
		}

		return movernode;
	}

	int BalanceFactor(Node<S>* temp)
	{
		if (temp == NULL)
			return 0;
		else
			return ((GetHeight(temp->left)) - (GetHeight(temp->right)));
	}

	Node<S>* AVLinsert(S val, Node<S>*& temp)
	{
		if (temp == NULL)  // Create and return a single tree 
		{
			temp = new Node<S>;
			temp->value = val;
			temp->left = temp->right = NULL;
		}
		else if (val < temp->value)
		{
			temp->left = AVLinsert(val, temp->left);
		}
		else if (val > temp->value)
		{
			temp->right = AVLinsert(val, temp->right);
		} // If val is in the tree already; we'll do nothing as we don't create duplicates

		temp->height = max(GetHeight(temp->left), GetHeight(temp->right)) + 1;
		int bf = BalanceFactor(temp); //checking balance factor for rotation if its not between -1 and 1

		if (bf > 1 && val < temp->left->value) //RotateRight
		{
			temp = SingleRightRotation(temp);
		}
		else if (bf < -1 && val > temp->right->value) //RotateLeft
		{
			//cout << "BEFORE ROTATION RIGHT RIGHT RIGHT: " << temp->value << " " << temp->right->value << " " << temp->right->right->value << endl;
			temp = SingleLeftRotation(temp);
			//cout << "AFTER ROTATION LEFT CENTER RIGHT: " <<temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		}
		else if (bf > 1 && val > temp->left->value) //DoubleRotateRight A.K.A RIGHT-LEFT ROTATION FIRST LEFT THEN RIGHT
		{
			temp = DoubleRightRotation(temp);
			//cout << temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		}
		else if (bf < -1 && val < temp->right->value) //DoubleRotateLeft A.K.A LEFT-RIGHT ROTATION FIRST RIGHT THEN LEFT
		{
			temp = DoubleLeftRotation(temp);
			//cout << temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		}

		return temp;
	}

	Node<S>* AVLdelete(S val, Node<S>*& temp)
	{

		if (temp == NULL)  // Base Case 
		{
			return temp;
		}
		else if (val < temp->value) //go left
		{
			temp->left = AVLdelete(val, temp->left);
		}
		else if (val > temp->value) //go right
		{
			temp->right = AVLdelete(val, temp->right);
		} 
		else //value matches so perform deleteion
		{
			if ((temp->left == NULL) && (temp->right == NULL)) //no child
			{
				Node<S>* tempnode = temp;
				temp = temp->right;
				delete tempnode;
			}
			else if ((temp->left == NULL) && (temp->right != NULL)) //one child on right
			{
				Node<S>* tempnode = temp;
				temp = temp->right;
				delete tempnode;
			}
			else if ((temp->right == NULL) && (temp->left != NULL)) //one child on left
			{
				Node<S>* tempnode = temp;
				temp = temp->left;
				delete tempnode;
			}
			else if ((temp->left != NULL) && (temp->right != NULL))//two children
			{
				Node<S>* tempnode = SmallestNodeValue(temp->right);
				temp->value = tempnode->value;
				temp->right = AVLdelete(tempnode->value, temp->right);
			}
		}


		if (temp == NULL) //only one node in whole tree so return
			return temp;

		//Same work as before, balancing tree and performing rotations but this time check the balance factors rather than values

		temp->height = max(GetHeight(temp->left), GetHeight(temp->right)) + 1;
		int bf = BalanceFactor(temp); //checking balance factor for rotation if its not between -1 and 1

		if ((bf > 1) && (BalanceFactor(temp->left) >= 0)) //RotateRight
		{
			temp = SingleRightRotation(temp);
		}
		else if ((bf < -1) && (BalanceFactor(temp->right) <= 0)) //RotateLeft
		{
			temp = SingleLeftRotation(temp);
			//cout << "AFTER ROTATION LEFT CENTER RIGHT: " <<temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		}
		else if ((bf < -1) && (BalanceFactor(temp->right) > 0)) //DoubleRotateRight A.K.A RIGHT-LEFT ROTATION FIRST LEFT THEN RIGHT
		{
			temp = DoubleRightRotation(temp);
			//cout << temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		}
		else if ((bf > 1) && (BalanceFactor(temp->left) < 0)) //DoubleRotateLeft A.K.A LEFT-RIGHT ROTATION FIRST RIGHT THEN LEFT
		{
			temp = DoubleLeftRotation(temp);
			//cout << temp->left->value << " " << temp->value << " " << temp->right->value << endl;
		}

		return temp;
	}

	void Inorder(Node<S>* temproot)
	{
		if (temproot != NULL)
		{
			Inorder(temproot->left);
			cout << temproot->value << " ";
			Inorder(temproot->right);
		}
	}
};