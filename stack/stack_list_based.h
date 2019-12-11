#pragma once
//Array based stack
#pragma once

#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node* next = NULL;
};

template<class T>
class stack {
public:
	Node<T>* Top = NULL;
public:
	stack()
	{
		Top = NULL;
	}
	void push( T _data);
	T pop();
	T peek( int _pos);
	bool isFull();
	bool isEmpty();
	void display();
};

template<class T>
void stack<T>::push( T _data)
{
	Node<T>* new_node = new Node<T>;
	if (new_node == NULL)
		cout << "Stack is full" << endl;
	new_node->data = _data;
	new_node->next = Top;
	Top = new_node;
}

template<class T>
T stack<T>::pop()
{
	if (Top == NULL)
	{
		cout << "Stack is Empty";
		return 0;
	}
	Node<T> *temp = Top;
	int val = temp->data;
	Top = Top->next;
	delete temp;
	return val;
}

template<class T>
T stack<T>::peek( int _pos)
{
	
}

template<class T>
bool stack<T>::isFull()
{
	Node<T>* new_node = new Node<T>;
	if (new_node == NULL)
	{
		return true;
	}
}

template<class T>
bool stack<T>::isEmpty()
{
	if (Top == NULL)
	{
		return false;
	}
}

template<class T>
void stack<T>::display()
{
	Node<T> *temp = Top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}