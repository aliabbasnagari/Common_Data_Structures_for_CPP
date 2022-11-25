#pragma once
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
	T value;
	Node<T>* next;
public:
	Node(T _data) {
		value = _data;
		next = NULL;
	}
	Node(T _data, Node<T>* _next) {
		value = _data;
		next = _next;
	}
	void setValue(T _data) {
		value = _data;
	}
	void setNext(Node<T>* _next) {
		next = _next;
	}
	T getValue() {
		return value;
	}
	Node<T>* getNext() {
		return next;
	}
};

#endif // !NODE_H
