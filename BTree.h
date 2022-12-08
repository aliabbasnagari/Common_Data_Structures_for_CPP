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
    int minDegree; //the minimum degree of a tree
    BTreeNode<T>** C;
    int no_entires;//no of entries
    bool leaf;
public:
    BTreeNode<T>(int _tmd, bool _leaf);
    void traverse();
    T findKey(T k);
    void insertNonFull(T k);
    void splitChild(int i, BTreeNode* y);
    void remove(T k);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    T getPredecessor(int idx);
    T getSuccessor(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
    
    //friend class BTree;
};

template <typename T>
class BTree {
public:
    BTreeNode<T>* root;
    int minDegree;

public:
    BTree(int _tmd=0) {
        root = NULL;
        minDegree = _tmd;
    }
    void traverse() {
        if (root != NULL)
            root->traverse();
    }
    void insert(T k);
    void remove(T k);
};

// B tree node
template <class T> BTreeNode<T>::BTreeNode<T>(int tmd1, bool leaf1) {
    minDegree = tmd1;
    leaf = leaf1;
    keys = new T[2 * minDegree - 1];
    C = new BTreeNode * [2 * minDegree];
    no_entires = 0;
}

// Find the key
template <class T> T BTreeNode<T>::findKey(T k) {
    int idx = 0;
    while (idx < no_entires && keys[idx] < k)
        ++idx;
    return idx;
}

// Deletion operation
template <class T>  void BTreeNode<T>::remove(T k) {
    int idx = findKey(k);

    if (idx < no_entires && keys[idx] == k) {
        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    }
    else {
        if (leaf) {
            cout << "Key <" << k << "> not found !" << endl;
            return;
        }

        bool flag = ((idx == no_entires) ? true : false);

        if (C[idx]->no_entires < minDegree)
            fill(idx);

        if (flag && idx > no_entires)
            C[idx - 1]->remove(k);
        else
            C[idx]->remove(k);
    }
    return;
}

// Remove from the leaf
template <class T> void BTreeNode<T>::removeFromLeaf(int idx) {
    for (int i = idx + 1; i < no_entires; ++i)
        keys[i - 1] = keys[i];

    no_entires--;

    return;
}

// Delete from non leaf node
template <class T>  void BTreeNode<T>::removeFromNonLeaf(int idx) {
    T k = keys[idx];

    if (C[idx]->no_entires >= minDegree) {
        T pred = getPredecessor(idx);
        keys[idx] = pred;
        C[idx]->remove(pred);
    }

    else if (C[idx + 1]->no_entires >= minDegree) {
        T succ = getSuccessor(idx);
        keys[idx] = succ;
        C[idx + 1]->remove(succ);
    }

    else {
        merge(idx);
        C[idx]->remove(k);
    }
    return;
}

template <class T> T BTreeNode<T>::getPredecessor(int idx) {
    BTreeNode* cur = C[idx];
    while (!cur->leaf)
        cur = cur->C[cur->no_entires];

    return cur->keys[cur->no_entires - 1];
}

template <class T> T BTreeNode<T>::getSuccessor(int idx) {
    BTreeNode* cur = C[idx + 1];
    while (!cur->leaf)
        cur = cur->C[0];

    return cur->keys[0];
}

template <class T> void BTreeNode<T>::fill(int idx) {
    if (idx != 0 && C[idx - 1]->no_entires >= minDegree)
        borrowFromPrev(idx);

    else if (idx != no_entires && C[idx + 1]->no_entires >= minDegree)
        borrowFromNext(idx);

    else {
        if (idx != no_entires)
            merge(idx);
        else
            merge(idx - 1);
    }
    return;
}

// Borrow from previous
template <class T> void BTreeNode<T>::borrowFromPrev(int idx) {
    BTreeNode* child = C[idx];
    BTreeNode* sibling = C[idx - 1];

    for (int i = child->no_entires - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf) {
        for (int i = child->no_entires; i >= 0; --i)
            child->C[i + 1] = child->C[i];
    }

    child->keys[0] = keys[idx - 1];

    if (!child->leaf)
        child->C[0] = sibling->C[sibling->no_entires];

    keys[idx - 1] = sibling->keys[sibling->no_entires - 1];

    child->no_entires += 1;
    sibling->no_entires -= 1;

    return;
}

// Borrow from the next
template <class T> void BTreeNode<T>::borrowFromNext(int idx) {
    BTreeNode* child = C[idx];
    BTreeNode* sibling = C[idx + 1];

    child->keys[(child->no_entires)] = keys[idx];

    if (!(child->leaf))
        child->C[(child->no_entires) + 1] = sibling->C[0];

    keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->no_entires; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->no_entires; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }

    child->no_entires += 1;
    sibling->no_entires -= 1;

    return;
}

// Merge
template <class T> void BTreeNode<T>::merge(int idx) {
    BTreeNode* child = C[idx];
    BTreeNode* sibling = C[idx + 1];

    child->keys[minDegree - 1] = keys[idx];

    for (int i = 0; i < sibling->no_entires; ++i)
        child->keys[i + minDegree] = sibling->keys[i];

    if (!child->leaf) {
        for (int i = 0; i <= sibling->no_entires; ++i)
            child->C[i + minDegree] = sibling->C[i];
    }

    for (int i = idx + 1; i < no_entires; ++i)
        keys[i - 1] = keys[i];

    for (int i = idx + 2; i <= no_entires; ++i)
        C[i - 1] = C[i];

    child->no_entires += sibling->no_entires + 1;
    no_entires--;

    delete (sibling);
    return;
}

// Insertion operation
template <class T>
void BTree<T>::insert(T k) {
    if (root == NULL) {
        root = new BTreeNode<T>(minDegree, true);
        root->keys[0] = k;
        root->no_entires = 1;
    }
    else {
        if (root->no_entires == 2 * minDegree - 1) {
            BTreeNode<T>* s = new BTreeNode<T>(minDegree, false);

            s->C[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

// Insertion non full
template <class T>
void BTreeNode<T>::insertNonFull(T k) {
    int i = no_entires - 1;

    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        no_entires = no_entires + 1;
    }
    else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->no_entires == 2 * minDegree - 1) {
            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

// Split child
template <class T> 
void BTreeNode<T>::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode<T>(y->minDegree, y->leaf);
    z->no_entires = minDegree - 1;

    for (int j = 0; j < minDegree - 1; j++)
        z->keys[j] = y->keys[j + minDegree];

    if (y->leaf == false) {
        for (int j = 0; j < minDegree; j++)
            z->C[j] = y->C[j + minDegree];
    }

    y->no_entires = minDegree - 1;

    for (int j = no_entires; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = no_entires - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[minDegree - 1];

    no_entires = no_entires + 1;
}

// Traverse
template <class T> void BTreeNode<T>::traverse() {
    int i;
    for (i = 0; i < no_entires; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << " , " << keys[i] << " , ";
    }

    if (leaf == false)
        C[i]->traverse();
}

// Delete Operation
template <class T> void BTree<T>::remove(T k) {
    if (!root) {
        cout << "The tree is empty" << endl;
        return;
    }

    root->remove(k);

    if (root->no_entires == 0) {
        BTreeNode* tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];

        delete tmp;
    }
    return;
}
#endif !BTREE