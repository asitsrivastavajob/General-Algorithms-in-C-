// tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

template<class T>
struct node {
	node * left_node = NULL;
	node * right_node = NULL;
	T _data;
};

template<class T>
void pre_order_traversal(node<T>* _node)
{
	if (_node != NULL)
	{
		cout << _node->_data <<" ";
		pre_order_traversal(_node->left_node);
		pre_order_traversal(_node->right_node);
	}
}

template<class T>
void iterative_pre_order_traversal(node<T>* _node)
{
	stack<node<int>*> itr_stack;
	while (_node!= NULL || !itr_stack.empty())
	{
		if (_node != NULL)
		{
			cout<<_node->_data <<" ";
			itr_stack.push(_node);
			_node = _node->left_node;
		}
		else
		{
			_node = itr_stack.top();
			itr_stack.pop();
			_node = _node->right_node;
		}
	}
}

template<class T>
void post_order_traversal(node<T>* _node)
{
	if (_node != NULL)
	{
		post_order_traversal(_node->left_node);
		post_order_traversal(_node->right_node);
		cout << _node->_data << " ";
	}
}
template<class T>
void iterative_level_order_traversal(node<T>* _node)
{
	queue<node<int>*> queue;
	queue.push(_node);
	while (!queue.empty())
	{
		node<int>* temp = queue.front();
		queue.pop();
		cout << temp->_data << " ";
		if (temp->left_node != NULL)
			queue.push(temp->left_node);
		if (temp->right_node != NULL)
			queue.push(temp->right_node);
	}
}

template<class T>
void in_order_traversal(node<T>* _node)
{
	if (_node != NULL)
	{
		in_order_traversal(_node->left_node);
		cout << _node->_data << " ";
		in_order_traversal(_node->right_node);
	}
}

template<class T>
void iterative_in_order_traversal(node<T>* _node)
{
	stack<node<int>*> itr_stack;
	while (_node != NULL || !itr_stack.empty())
	{
		if (_node != NULL)
		{
			itr_stack.push(_node);
			_node = _node->left_node;
		}
		else
		{
			_node = itr_stack.top();	itr_stack.pop();
			cout << _node->_data << " ";
			_node = _node->right_node;
		}
	}
}

template<class T>
int height_of_tree(node<T>* _node)
{
	int x, y;
	if (_node != NULL)
	{
		x = height_of_tree(_node->left_node);
		y = height_of_tree(_node->right_node);
		if (x > y)
			return x + 1;
		else
			return y + 1;
	}
	return 0;
}

template<class T>
int count_all_nodes(node<T>* _node)
{
	int x, y;
	if (_node != NULL)
	{
		x = count_all_nodes(_node->left_node);
		y = count_all_nodes(_node->right_node);
		return x + y + 1;
	}
	return 0;
}

template<class T>
int count_degree_2_nodes(node<T>* _node)
{
	int x, y;
	if (_node != NULL)
	{
		x = count_degree_2_nodes(_node->left_node);
		y = count_degree_2_nodes(_node->right_node);
		if (_node->left_node != NULL && _node->right_node != NULL)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

template<class T>
int count_degree_1_nodes(node<T>* _node)
{
	int x, y;
	if (_node != NULL)
	{
		x = count_degree_1_nodes(_node->left_node);
		y = count_degree_1_nodes(_node->right_node);
		if ( (_node->left_node == NULL && _node->right_node != NULL) || (_node->left_node != NULL && _node->right_node == NULL))
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

template<class T>
int sum_of_all_nodes(node<T>* _node)
{
	int x, y;
	if (_node != NULL)
	{
		x = sum_of_all_nodes(_node->left_node);
		y = sum_of_all_nodes(_node->right_node);
		return x + y + _node->_data;
	}
	return 0;
}

//count_degree_0_nodes or leaf nodes
template<class T>
int count_leaf(node<T>* _node)
{
	int x, y;
	if (_node != NULL)
	{
		x = count_leaf(_node->left_node);
		y = count_leaf(_node->right_node);
		if(_node->left_node == NULL && _node->right_node == NULL)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

int main()
{
	
	queue<node<int>*> queue;
	int val;
	cout << "Enter root element ::";
	cin >> val;

	node<int>* root = new node<int>;
	root->_data = val;
	root->left_node = NULL;
	root->right_node = NULL;

	queue.push(root);

	while (!queue.empty())
	{
		node<int>* temp_parent = new node<int>;
		node<int>* temp_left = new node<int>;
		node<int>* temp_right = new node<int>;

		temp_parent = queue.front(); queue.pop();

		int val;
		cout << "Enter left child of :: "<< temp_parent->_data <<" ::";
		cin >> val;

		if (val != -1)
		{
			temp_left->_data = val;
			temp_left->left_node = NULL;
			temp_left->right_node = NULL;

			temp_parent->left_node = temp_left;
			queue.push(temp_left);
		}
		cout << "Enter right child of :: " << temp_parent->_data << " ::";
		cin >> val;
		if (val != -1)
		{
			temp_right->_data = val;
			temp_right->left_node = NULL;
			temp_right->right_node = NULL;

			temp_parent->right_node = temp_right;
			queue.push(temp_right);
		}

		char s;
		cout << "Do you want to exit (Y/N) :: ";
		cin >> s;
		if (s == 'Y' || s == 'y')
			break;
	}

	cout <<endl<<endl<< "Display Tree " << std::endl;
	cout << "Pre order traversal :: ";
	pre_order_traversal<int>(root);
	cout << endl;
	cout << "Post order traversal :: ";
	post_order_traversal<int>(root);
	cout << endl;
	cout << "In order traversal :: ";
	in_order_traversal<int>(root);
	cout << endl;
	cout << "Iterative Pre order traversal :: ";
	iterative_pre_order_traversal<int>(root);
	cout << endl;
	cout << "Iterative in order traversal :: ";
	iterative_in_order_traversal<int>(root);
	cout << endl;
	cout << "Iterative level order traversal :: ";
	iterative_level_order_traversal<int>(root);
	cout << endl;
	cout << "Height of tree :: ";
	cout << height_of_tree<int>(root);
	cout << endl;
	cout << "Count leaf nodes of tree :: ";
	cout << count_leaf<int>(root);
	cout << endl;
	cout << "Count degree 2 nodes of tree :: ";
	cout << count_degree_2_nodes<int>(root);
	cout << endl;

	cout << "Sum of all node :: ";
	cout << sum_of_all_nodes<int>(root);
	cout << endl;
	cout << "Count of all nodes of tree :: ";
	cout << count_all_nodes<int>(root);
	cout << endl;
	cout << "Count degree 1 nodes of tree :: ";
	cout << count_degree_1_nodes<int>(root);
	cout << endl;
    return 0;
}

