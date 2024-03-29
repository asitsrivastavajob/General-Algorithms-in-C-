// ParenthesisMatching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
using namespace std;

void curly_parenthesis_matching(char *str)
{
	stack<char> s;
	while (*str != '\0')
	{
		if (*str == '(')
			s.push(*str);
		if (*str == ')')
			s.pop();
		str++;
	}
	if (s.empty())
		cout << "All parenthesis are proper"<<endl;
	else
		cout << "All parenthesis are not proper"<<endl;
}

void all_parenthesis_matching(char *str)
{
	stack<char> s;
	while (*str != '\0')
	{
		if (*str == '(' || *str == '{' || *str == '[')
			s.push(*str);
		if (*str == ')' || *str == '}' || *str == ']')
		{
			char a = s.top();
			if (*str < 42 && a < 42 || *str > 90 && *str < 94 && a > 90 && a < 94 || *str > 122 && *str < 126 && a > 122 && a < 126)
			{
				s.pop();
			}
		}
		str++;
	}
	if (s.empty())
		cout << "All parenthesis are proper" << endl;
	else
		cout << "All parenthesis are not proper" << endl;
}

int main()
{
	char string1[] = { '(',')','1','+','_','(','r','f','j','k',')','\0' };
	char string2[] = { '(',')','1','+','_','(','r','f','j','k',')','(','d','\0' };
	char string3[] = { '(','1','+','_','(','r','f','j','k',')','\0' };

	curly_parenthesis_matching(string1);
	curly_parenthesis_matching(string2);
	curly_parenthesis_matching(string3);


	char string4[] = { '(',')','1','[','_',']','r','{','j','k','}','\0' };
	char string5[] = { '(','[','1','+','_','{','r','f','j','k','}',']','d',')','\0' };
	char string6[] = { '(','1','+','_','[','r',']','j','k',']','\0' };

	all_parenthesis_matching(string4);
	all_parenthesis_matching(string5);
	all_parenthesis_matching(string6);
    return 0;
}

