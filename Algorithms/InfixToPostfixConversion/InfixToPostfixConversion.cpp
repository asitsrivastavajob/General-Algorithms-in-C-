// InfixToPostfixConversion.cpp : Defines the entry point for the console application.
//

//Infix to postfix conversion of a statement where operators can have different associativity , i.e from right 
//to left associativity and left to right associativity.

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <map>
using namespace std;

class associ_table
{
public:
	char symbol;
	int out_stack_precedence;
	int in_stack_precedence;

	int get_out_stack_precedence(char _symbol);
	int get_in_stack_precedence(char _symbol);
};
 
int isOPerator(char s)
{
	if (s == '+' || s == '-' || s == '/' || s == '*' || s == '!' || s == '^' || s == '(' || s == ')')
		return true;
	else
		return false;
}

void fill_associativity_table(map<char, associ_table>& _assoc_table)
{
	_assoc_table['+'].symbol = '+';
	_assoc_table['+'].in_stack_precedence = 2;
	_assoc_table['+'].out_stack_precedence = 1;

	_assoc_table['-'].symbol = '-';
	_assoc_table['-'].in_stack_precedence = 2;
	_assoc_table['-'].out_stack_precedence = 1;

	_assoc_table['*'].symbol = '*';
	_assoc_table['*'].in_stack_precedence = 4;
	_assoc_table['*'].out_stack_precedence = 3;

	_assoc_table['/'].symbol = '/';
	_assoc_table['/'].in_stack_precedence = 4;
	_assoc_table['/'].out_stack_precedence = 3;

	_assoc_table['^'].symbol = '^';
	_assoc_table['^'].in_stack_precedence = 5;
	_assoc_table['^'].out_stack_precedence = 6;

	_assoc_table['('].symbol = '(';
	_assoc_table['('].in_stack_precedence = 0;
	_assoc_table['('].out_stack_precedence = 7;

	_assoc_table[')'].symbol = ')';
	_assoc_table[')'].in_stack_precedence = 0;
	_assoc_table[')'].out_stack_precedence = 0;
}

int main()
{
	map<char, associ_table> g_assoc_table;
	fill_associativity_table(g_assoc_table);

	char infix_string[] = {'(','(' ,'a','+','b',')','*','c',')','-','d','^','e','^','f','\0' };
	char postfix_string[25] = { {'#'} };

	stack<char> symbol_stack;

	char *str = infix_string;
	int i = 0;
	while (*str != '\0')
	{
		if (!isOPerator(*str))
		{
			postfix_string[i++] = *str++;
		}
		else
		{
			if (symbol_stack.empty())
			{
				symbol_stack.push(*str);
				str++;
			}
			else if (g_assoc_table[*str].out_stack_precedence > g_assoc_table[symbol_stack.top()].in_stack_precedence)
			{
				symbol_stack.push(*str);
				str++;
			}
			else
			{
				if (symbol_stack.top() != '(' && symbol_stack.top() != ')')
				{
					postfix_string[i++] = symbol_stack.top();
				}
				symbol_stack.pop();
			}
		}
	}

	while (!symbol_stack.empty())
	{
		if (symbol_stack.top() != '(' && symbol_stack.top() != ')')
		{
			postfix_string[i++] = symbol_stack.top();
		}
		symbol_stack.pop();
	}

	
	str = infix_string;
	cout << "infix stream is = ";
	while (*str != '\0')
	{
		cout << *str++;
	}

	str = postfix_string;
	cout << endl<<"postfix stream is = ";
	while (*str != '\0')
	{
		cout << *str++;
	}
	cout << endl;

    return 0;
}

