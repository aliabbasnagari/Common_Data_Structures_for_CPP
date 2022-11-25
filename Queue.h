/*
Ali Abbas - 21I-2503
Adnan Hayat
Muhammad Wissam - 21I-0709
*/
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class Queue {
private:
	int size;
	Node<T>* front;
	Node<T>* rear;
public:
	Queue() {
		size = 0;
		front = NULL;
		rear = NULL;
	}

	int Size() {
		return size;
	}

	void enqueue(T _value) {
		if (isEmpty()) {
			front = new Node<T>(_value, NULL);
			rear = front;
		}
		else {
			Node<T>* add_node = new Node<T>(_value, NULL);
			rear->setNext(add_node);
			rear = add_node;
		}
		size++;
	}

	void dequeue() {
		if (front != NULL)
		{
			Node<T>* new_front = NULL;
			if (front->getNext() != NULL)
				new_front = front->getNext();
			delete front;
			front = new_front;
			size--;
		}
	}

	bool isEmpty() {
		if (front == NULL)
			return true;
		else
			return false;
	}

	T Front() {
		if (!isEmpty())
			return front->getValue();
		else
			return 0;
	}

	void show() {
		Node<T>* current = front;
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

	void addToQueue(Queue* q) {
		this->rear->setNext(q->front);
		this->rear = q->rear;
		this->size += q->size;
	}

	~Queue() {
		Node<T>* current = front;
		while (current != NULL)
		{
			Node<T>* to_delete = current;
			current = current->getNext();
			delete[] to_delete;
		}
		delete current;
	}
};

template<typename T>
void roundRobin(Queue<T>* q, T quantum) {
	while (!q->isEmpty())
	{
		cout << endl;
		q->show();

		cout << "Execution time: " << q->Front() << endl;
		T rem = q->Front() - quantum;
		cout << "Remaining time: " << rem << endl;
		if (rem > 0)
		{
			cout << "Task is not comleted, it is being rescheduled!" << endl;
			q->enqueue(rem);
			q->dequeue();
		}
		else {
			cout << "Task is comleted, and it is removed from queue!" << endl;
			q->dequeue();
		}
	}
}

#endif // !QUEUE_H