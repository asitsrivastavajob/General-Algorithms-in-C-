#pragma once


class LinkedList {
public:
	T data;
	LinkedList* next = NULL;
public:
	void append(T _data, LinkedList<T>** _Top);
	void display( LinkedList<T>* _Top);
	void insert(int _pos, T _data, LinkedList<T>** _Top);
	void reverse_linked_list( LinkedList<T>** _Top);
	void recursive_reverse_linked_list(LinkedList<T>* p, LinkedList<T>* q, LinkedList<T>** _Top);
};


void Merge(LinkedList<T>** _first, LinkedList<T>** _second, LinkedList<T>** _final)
{
	LinkedList<T>* start = NULL;
	LinkedList<T>* end = NULL;
	LinkedList<T>* first = *_first;
	LinkedList<T>* second = *_second;
	if (first->data < second->data)
	{
		start = first;
		end = first;
		first = first->next;
		end->next = NULL;
	}
	else
	{
		start = second;
		end = second;
		second = second->next;
		end->next = NULL;
	}

	while (first != NULL && second != NULL)
	{
		if (first->data < second->data)
		{
			end->next = first;
			end = end->next;
			first = first->next;
			end->next = NULL;
		}
		else
		{
			end->next = second;
			end = end->next;
			second = second->next;
			end->next = NULL;
		}
	}

	if (first != NULL)
		end->next = first;
	else
		end->next = second;

	*_final = start;
}


void LinkedList<T>::append(T _data, LinkedList<T>** _Top)
{
	LinkedList<T>* new_node = new LinkedList<T>;
	new_node->data = _data;
	new_node->next = NULL;

	if (*_Top == NULL)
		*_Top = new_node;
	else
	{
		LinkedList<int>* ptr = *_Top;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}
	//std::cout << std::endl;
}


void LinkedList<T>::display( LinkedList<T>* _Top)
{
	std::cout << "Display Linked List :: ";
	LinkedList<T> *ptr = _Top;
	while (ptr != NULL)
	{
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}


void LinkedList<T>::insert(int _pos, T _data, LinkedList<T>** _Top)
{
	std::cout << "Insert at " << _pos << ", data = " << _data;
	LinkedList<T>* ptr = *_Top;
	int i = 1;

	while (ptr->next != NULL)
	{
		if (i + 1 == _pos)
			break;

		i++;
		ptr = ptr->next;
	}

	LinkedList<T>* new_node = new LinkedList<T>;
	new_node->data = _data;

	if (_pos == 1)
	{
		new_node->next = *_Top;
		*_Top = new_node;
	}
	else
	{
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
	std::cout << std::endl;
}


void LinkedList<T>::reverse_linked_list( LinkedList<T>** _Top)
{
	std::cout << "Reverse Linked List :: ";
	LinkedList<T> *p = NULL, *q = NULL, *r = NULL;
	p = *_Top;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*_Top = q;
	std::cout << std::endl;
}


void LinkedList<T>::recursive_reverse_linked_list(LinkedList<T>* p, LinkedList<T>* q, LinkedList<T>** _Top)
{
	if (q == NULL)
	{
		*_Top = p;
		return;
	}
	recursive_reverse_linked_list(q, q->next,_Top);
	q->next = p;
}