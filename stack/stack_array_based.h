//Array based stack
#pragma once

#include<iostream>
using namespace std;

template<class T>
class stack {
public:
	stack(int _size)
	{
		s = new T[_size];
		size = _size;
		top = -1;
	}

	T * s = nullptr;
	int size = 0;
	int top = -1;
};

template<class T>
void push(stack<T> *s,T _data)
{
	if (isFull(s))
	{
		std::cout << "Stack is full" << std::endl;
		return;
	}
	s->top++;
	s->s[s->top] = _data;
}

template<class T>
T pop(stack<T> *s)
{
	if (isEmpty(s))
	{
		std::cout << "Stack is Empty" << std::endl;
		return -1;
	}
	T val = s->s[s->top];
	s->s[s->top] = -1;
	s->top--;
	return val;
}

template<class T>
T peek(stack<T> *s,int _pos)
{
	if ( (_pos < 0) && (s->top +1 < _pos) )
	{
		std::cout << "Invalid position" << std::endl;
		return 0;
	}
	return s->s[s->top - _pos + 1];
}

template<class T>
bool isFull(stack<T> *s)
{
	if (s->size == s->top - 1)
		return true;
	else
		return false;
}

template<class T>
bool isEmpty(stack<T> *s)
{
	if (s->top ==  - 1)
		return true;
	else
		return false;
}

template<class T>
void display(stack<T> *s)
{
	for (int i = 0; i<=s->top; i++)
	{
		std::cout << s->s[i] << " ";
	}
}