#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class Stack {
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    Stack() {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    int Size() {
        return size;
    }

    void push(T _value) {
        if (head == NULL) {
            head = new Node<T>(_value, NULL);
            tail = head;
        }
        else {
            Node<T>* add_node = new Node<T>(_value, NULL);
            tail->setNext(add_node);
            tail = add_node;
        }
        size++;
    }

    T pop() {
        T _val;
        if (tail != NULL) {
            if (head == tail) {
                _val = head->getValue();
                delete head;
                head = tail = NULL;
            }
            else {
                Node<T>* current = head;
                while (current->getNext() != tail)
                    current = current->getNext();
                current->setNext(NULL);
                _val = tail->getValue();
                delete tail;
                tail = current;
            }
            size--;
        }
        return _val;
    }

    bool empty() {
        if (head == NULL)
            return true;
        else
            return false;
    }

    bool contain(T _value) {
        Node<T>* current = head;
        while (current != NULL) {
            if (current->getValue() == _value)
                return true;
            else
                current = current->getNext();
        }
        return false;
    }

    void clear() {
        Node<T>* current = head;
        while (current != NULL) {
            Node<T>* to_delete = current;
            current = current->getNext();
            delete[] to_delete;
        }
        delete current;
        head = NULL;
        tail = NULL;
        size = 0;
    }

    Node<T>* Peek() {
        return tail;
    }

    T top() {
        return tail->getValue();
    }

    void display() {
        Node<T>* current = head;
        cout << "[";
        while (current != NULL) {
            cout << current->getValue();
            current = current->getNext();
            if (current != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    ~Stack() {
        Node<T>* current = head;
        while (current != NULL) {
            Node<T>* to_delete = current;
            current = current->getNext();
            delete to_delete;
        }
        delete current;
    }
};

#endif // !STACK_H