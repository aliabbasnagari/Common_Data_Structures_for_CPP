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
    T t;
    BTreeNode<T>** C;
    T n;
    bool leaf;
public:
    BTreeNode<T>(T _t, bool _leaf);
    void traverse();
    T findKey(T k);
    void insertNonFull(T k);
    void splitChild(T i, BTreeNode* y);
    void deletion(T k);
    void removeFromLeaf(T idx);
    void removeFromNonLeaf(T idx);
    T getPredecessor(T idx);
    T getSuccessor(T idx);
    void fill(T idx);
    void borrowFromPrev(T idx);
    void borrowFromNext(T idx);
    void merge(T idx);
    //friend class BTree;
};

template <typename T>
class BTree {
public:
    BTreeNode<T>* root;
    int t;

public:
    BTree(int _t) {
        root = NULL;
        t = _t;
    }
    void traverse() {
        if (root != NULL)
            root->traverse();
    }
    void insertion(T k);
    void deletion(T k);
};

// B tree node
template <class T> BTreeNode<T>::BTreeNode<T>(T t1, bool leaf1) {
    t = t1;
    leaf = leaf1;
    keys = new T[2 * t - 1];
    C = new BTreeNode * [2 * t];
    n = 0;
}

// Find the key
template <class T> T BTreeNode<T>::findKey(T k) {
    T idx = 0;
    while (idx < n && keys[idx] < k)
        ++idx;
    return idx;
}

// Deletion operation
template <class T>  void BTreeNode<T>::deletion(T k) {
    T idx = findKey(k);

    if (idx < n && keys[idx] == k) {
        if (leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    }
    else {
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

// Remove from the leaf
template <class T> void BTreeNode<T>::removeFromLeaf(T idx) {
    for (T i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];

    n--;

    return;
}

// Delete from non leaf node
template <class T>  void BTreeNode<T>::removeFromNonLeaf(T idx) {
    T k = keys[idx];

    if (C[idx]->n >= t) {
        T pred = getPredecessor(idx);
        keys[idx] = pred;
        C[idx]->deletion(pred);
    }

    else if (C[idx + 1]->n >= t) {
        T succ = getSuccessor(idx);
        keys[idx] = succ;
        C[idx + 1]->deletion(succ);
    }

    else {
        merge(idx);
        C[idx]->deletion(k);
    }
    return;
}

template <class T> T BTreeNode<T>::getPredecessor(T idx) {
    BTreeNode* cur = C[idx];
    while (!cur->leaf)
        cur = cur->C[cur->n];

    return cur->keys[cur->n - 1];
}

template <class T> T BTreeNode<T>::getSuccessor(T idx) {
    BTreeNode* cur = C[idx + 1];
    while (!cur->leaf)
        cur = cur->C[0];

    return cur->keys[0];
}

template <class T> void BTreeNode<T>::fill(T idx) {
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

// Borrow from previous
template <class T> void BTreeNode<T>::borrowFromPrev(T idx) {
    BTreeNode* child = C[idx];
    BTreeNode* sibling = C[idx - 1];

    for (T i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf) {
        for (T i = child->n; i >= 0; --i)
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

// Borrow from the next
template <class T> void BTreeNode<T>::borrowFromNext(T idx) {
    BTreeNode* child = C[idx];
    BTreeNode* sibling = C[idx + 1];

    child->keys[(child->n)] = keys[idx];

    if (!(child->leaf))
        child->C[(child->n) + 1] = sibling->C[0];

    keys[idx] = sibling->keys[0];

    for (T i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (T i = 1; i <= sibling->n; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }

    child->n += 1;
    sibling->n -= 1;

    return;
}

// Merge
template <class T> void BTreeNode<T>::merge(T idx) {
    BTreeNode* child = C[idx];
    BTreeNode* sibling = C[idx + 1];

    child->keys[t - 1] = keys[idx];

    for (T i = 0; i < sibling->n; ++i)
        child->keys[i + t] = sibling->keys[i];

    if (!child->leaf) {
        for (T i = 0; i <= sibling->n; ++i)
            child->C[i + t] = sibling->C[i];
    }

    for (T i = idx + 1; i < n; ++i)
        keys[i - 1] = keys[i];

    for (T i = idx + 2; i <= n; ++i)
        C[i - 1] = C[i];

    child->n += sibling->n + 1;
    n--;

    delete (sibling);
    return;
}

// Insertion operation
template <class T> void BTree<T>::insertion(T k) {
    if (root == NULL) {
        root = new BTreeNode<T>(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            BTreeNode<T>* s = new BTreeNode<T>(t, false);

            s->C[0] = root;

            s->splitChild(0, root);

            T i = 0;
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
template <class T> void BTreeNode<T>::insertNonFull(T k) {
    T i = n - 1;

    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n = n + 1;
    }
    else {
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

// Split child
template <class T> void BTreeNode<T>::splitChild(T i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode<T>(y->t, y->leaf);
    z->n = t - 1;

    for (T j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false) {
        for (T j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (T j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (T j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];

    n = n + 1;
}

// Traverse
template <class T> void BTreeNode<T>::traverse() {
    T i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }

    if (leaf == false)
        C[i]->traverse();
}

// Delete Operation
template <class T> void BTree<T>::deletion(T k) {
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

#endif !BTREE