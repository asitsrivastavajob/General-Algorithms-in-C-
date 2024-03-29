// stack.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#define ARRAY_BASED_STACK_OPERATION 0

#if ARRAY_BASED_STACK_OPERATION
#include "stack_array_based.h"
#else
#include "stack_list_based.h"
#endif



int main()
{
#if ARRAY_BASED_STACK_OPERATION
	stack<int> st(5);
	push<int>(&st, 1);
	push<int>(&st, 2);
	push<int>(&st, 3);
	push<int>(&st, 4);

	display<int>(&st);

	std::cout << "Peak = " << peek<int>(&st, 2) << std::endl;
	std::cout << "Peak = " << peek<int>(&st, 4) << std::endl;
	
	std::cout << "pop = " << pop(&st) <<std::endl;
	std::cout << "pop = " << pop(&st) << std::endl;
	std::cout << "pop = " << pop(&st) << std::endl;
	std::cout << "pop = " << pop(&st) << std::endl;
	std::cout << "pop = " << pop(&st) << std::endl;
	std::cout << "pop = " << pop(&st) << std::endl;
#else
	stack<int> stack;
	stack.push(10);
	stack.push(4);
	stack.push(78);
	stack.push(40);
	stack.push(110);

	stack.display();

	cout << endl;
	stack.pop();
	stack.display();

	cout << endl;
	stack.pop();
	stack.display();

	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
#endif

    return 0;
}

