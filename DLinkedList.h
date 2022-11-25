/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/
#pragma once
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class DNode {
private:
	T value;
	DNode<T>* next;
	DNode<T>* prev;
public:
	DNode(T _data) {
		value = _data;
		next = NULL;
	}
	DNode(T _data, DNode<T>* _next) {
		value = _data;
		next = _next;
	}
	void setValue(T _data) {
		value = _data;
	}
	void setNext(DNode<T>* _next) {
		next = _next;
	}
	void setPrev(DNode<T>* _prev) {
		prev = _prev;
	}
	T getValue() {
		return value;
	}
	DNode<T>* getNext() {
		return next;
	}
	DNode<T>* getPrev() {
		return prev;
	}
};

template <class T>
class DLinkedList {
public:
	int size;
	DNode<T>* head;
	DNode<T>* tail;
public:
	DLinkedList() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	int Size() {
		return size;
	}

	void AddToHead(T _value) {
		if (head == NULL) {
			head = new DNode<T>(_value, NULL, NULL);
			tail = head;
		}
		else {
			DNode<T>* add_node = new DNode<T>(_value, NULL, head);
			head->setPrev(add_node);
			head = add_node;
			add_node = NULL;
		}
		size++;
	}

	void AddToTail(T _value) {
		if (head == NULL) {
			head = new DNode<T>(_value, NULL, NULL);
			tail = head;
		}
		else {
			DNode<T>* add_node = new DNode<T>(_value, tail, NULL);
			tail->setNext(add_node);
			tail = add_node;
		}
		size++;
	}

	void RemoveFromHead() {
		if (head != NULL)
		{
			DNode<T>* new_head = NULL;
			if (head->getNext() != NULL)
				new_head = head->getNext();
			delete head;
			head = new_head;
			head->setPrev(NULL);
			size--;
		}
	}

	void RemoveFromTail() {
		if (tail != NULL) {
			if (head == tail)
			{
				delete head;
				head = tail = NULL;
			}
			else {
				DNode<T>* new_tail = tail->getPrev();
				delete tail;
				tail = new_tail;
				tail->setNext(nullptr);
				new_tail = NULL;
			}
			size--;
		}
	}

	bool isEmpty() {
		if (head == NULL)
			return true;
		else
			return false;
	}

	bool contain(T _value) {
		DNode<T>* current = head;
		while (current != NULL)
		{
			if (current->getValue() == _value)
				return true;
			else
				current = current->getNextDNode();
		}
		return false;
	}

	void clear() {
		DNode<T>* current = head;
		while (current != NULL)
		{
			DNode<T>* to_delete = current;
			current = current->next_node;
			delete[] to_delete;
		}
		delete current;
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void display() {
		DNode<T>* current = head;
		cout << "[";
		while (current != NULL)
		{
			cout << current->getValue();
			current = current->getNext();
			if (current != NULL)
				cout << ", ";
		}
		cout << "]" << endl;
	}

	~DLinkedList() {
		DNode<T>* current = head;
		while (current != NULL)
		{
			DNode<T>* to_delete = current;
			current = current->getNext();
			delete[] to_delete;
		}
		delete current;
	}
};

#endif // !DLINKEDLIST_H