/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/
#pragma once
#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class LinkedList {
public:
	int size;
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList()
	{
		size = 0;
		head = tail = NULL;
	}

	void insertAtHead(T _val)
	{
		Node<T>* tempNode = new Node<T>(_val, head);
		if (tail == NULL)
			head = tail = tempNode;
		else
			head = tempNode;
		size++;
		tempNode = NULL;
		delete tempNode;
	}

	void insert(T _val)
	{
		Node<T>* tempNode = new Node<T>(_val, NULL);
		if (tail == NULL)
			head = tail = tempNode;
		else
			tail->setNext(tempNode);
		tail = tempNode;
		size++;
		tempNode = NULL;
		delete tempNode;
	}

	void InsertAtIndex(T _val, int _index)
	{
		if (_index <= size) {
			if (_index == 0) {
				insertAtHead(_val);
			} else if (_index == size) {
				insert(_val);
			} else {
				Node<T>* at = head;
				for (int i = 0; i < _index - 1; i++)
					at = at->getNext();
				Node<T>* tempNode = new Node<T>(_val, at->getNext());
				at->setNext(tempNode);
				tempNode = NULL;
				delete tempNode;
				size++;
			}
		}
	}

	void insertAfter(T _after, T _val)
	{
		int index = search(_after);
		if (index + 1 != 0 && index + 1 <= size + 1)
			insertAt(index + 1, _val);
	}

	void insertBefore(T _before, T _val)
	{
		int index = search(_before);
		if (index >= 0)
			insertAt(index, _val);
	}

	void removeHead()
	{
		Node<T>* tempNode = head;
		head = head->getNext();
		size--;
		delete tempNode;
	}

	void removeTail()
	{
		Node<T>* tempNode = head;
		while (tempNode->getNext()->getNext() != NULL) {
			tempNode = tempNode->getNext();
		}
		delete tempNode->getNext();
		size--;
		tempNode->setNext(NULL);
	}

	void removeAt(int _index)
	{
		if (_index < size) {
			if (_index == 0) {
				removeHead();
			} else if (_index == size - 1) {
				removeTail();
			} else {
				Node<T>* at = head;
				Node<T>* toRemove;
				for (int i = 0; i < _index - 1; i++)
					at = at->getNext();
				toRemove = at->getNext();
				at->setNext(toRemove->getNext());
				delete toRemove;
				toRemove = NULL;
				size--;
			}
		}
	}

	void remove(T _val)
	{
		int index = search(_val);
		if (index != -1) {
			if (index == 0) {
				removeHead();
			} else if (index == (size - 1)) {
				removeTail();
			} else {
				Node<T>* at = head;
				Node<T>* toRemove;
				for (int i = 0; i < index - 1; i++)
					at = at->getNext();
				toRemove = at->getNext();
				at->setNext(toRemove->getNext());
				delete toRemove;
				toRemove = NULL;
				size--;
			}
		}
	}

	void update(T to, T val)
	{
		Node<T>* curr = head;
		while (curr->getNext() != NULL) {
			if (curr->getValue() == to) {
				curr->value = val;
			}
			curr = curr->getNext();
		}
	}

	int search(T _val)
	{
		int index = 0;
		Node<T>* curr = head;
		while (curr->getNext() != NULL) {
			if (curr->getValue() == _val)
				return index;
			curr = curr->getNext();
			index++;
		}
		if (curr->getValue() == _val)
			return index;
		return -1;
	}

	Node<T>* searchByVal(T _val)
	{
		Node<T>* curr = head;
		while (curr->getNext() != NULL) {
			if (curr->getValue() == _val)
				return curr;
			curr = curr->getNext();
		}
		if (curr->getValue() == _val)
			return curr;
		return NULL;
	}

	Node<T>* atIndex(int _val)
	{
		int index = 0;
		Node<T>* curr = head;
		while (index != _val) {
			curr = curr->getNext();
			index++;
		}
		return curr;
	}

	bool contain(T _val)
	{
		if (search(_val) == -1)
			return false;
		else
			return true;
	}

	int Size()
	{
		return size;
	}

	void mergeLists(LinkedList list)
	{
		this->tail = list.head;
		Node<T>* temp = head;
		while (this->tail->next != NULL) {
			temp = head;
			while (temp->next != NULL) {
				if (temp->value > this->tail->value) {
					T swapData;
					swapData = temp->value;
					temp->value = this->tail->value;
					this->tail->value = swapData;
				}
				temp = temp->next;
			}
			this->tail = this->tail->next;
		}
	}

	bool isEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}

	void print()
	{
		cout << "[ ";
		Node<T>* curr = head;
		while (curr->getNext() != NULL) {
			cout << curr->getValue() << " , ";
			curr = curr->getNext();
		}
		cout << curr->getValue();
		cout << " ]";
	}

	void display()
	{
		if (head == NULL)
			return;
		Node<T>* curr = head;
		while (curr->getNext() != NULL) {
			curr->getValue().display();
			curr = curr->getNext();
		}
		curr->getValue().display();
	}

	~LinkedList()
	{
		Node<T>* curr = head;
		while (curr->getNext() != NULL) {
			Node<T>* to_delete = curr;
			curr = curr->getNext();
			delete[] to_delete;
		}
	}
};

#endif // !LinkedList_H