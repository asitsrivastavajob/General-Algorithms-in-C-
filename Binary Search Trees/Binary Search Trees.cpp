// Binary Search Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

struct node {
	node * left;
	int data;
	node * right;
};

void create_node(node **_node, int *_data)
{
	node *_ptr = *_node;
	node * prev_ptr = NULL;
	node * temp = new node;
	temp->data = *_data;
	temp->left = NULL;
	temp->right = NULL;
	if (_ptr == NULL)
	{
		*_node = temp;
		return;
	}
	while (_ptr != NULL)
	{
		prev_ptr = _ptr;
		if (_ptr->data > temp->data)
		{
			_ptr = _ptr->left;
		}
		else
		{
			_ptr = _ptr->right;
		}
	}

	if (prev_ptr->data > temp->data)
		prev_ptr->left = temp;
	else
		prev_ptr->right = temp;
	return;
}

node* recursive_insert(node *_node, int _data)
{
	if (_node == NULL)
	{
		node* temp = new node;
		temp->data = _data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	if (_node->data > _data)
	{
		_node->left = recursive_insert(_node->left, _data);
	}
	else
	{
		_node->right = recursive_insert(_node->right, _data);
	}
	return _node;
}

void create_tree(node **_node, int *_data)
{
	//for (int i = 0; _data[i] != NULL; i++)
	//{
	//	create_node(_node, &_data[i]);
	//}

	for (int i = 0; _data[i] != NULL; i++)
	{
		if(i == 0)
			*_node = recursive_insert(*_node, _data[i]);
		else
			recursive_insert(*_node, _data[i]);
	}
}

void preorder_traversal(node* _ptr)
{
	stack<node *> st;
	while (!st.empty() || _ptr != NULL)
	{
		if (_ptr != NULL)
		{
			cout << _ptr->data << " ";
			st.push(_ptr);
			_ptr = _ptr->left;
		}
		else
		{
			_ptr = st.top();
			st.pop();
			_ptr = _ptr->right;
		}
	}
}

void inorder_traversal(node* _ptr)
{
	stack<node *> st;
	while (!st.empty() || _ptr != NULL)
	{
		if (_ptr != NULL)
		{
			st.push(_ptr);
			_ptr = _ptr->left;
		}
		else
		{
			_ptr = st.top();
			st.pop();
			cout << _ptr->data << " ";
			_ptr = _ptr->right;
		}
	}
}

int Height(node* _ptr)
{
	int x, y;
	if (_ptr == NULL)
	{
		return 0;
	}
	x = Height(_ptr->left);
	y = Height(_ptr->right);
	return x > y ? x+1 : y+1;
}

node * Pre(node* _ptr)
{
	while (_ptr && _ptr->right != NULL)
	{
		_ptr = _ptr->right;
	}
	return _ptr;
}

node * Suc(node* _ptr)
{
	while (_ptr && _ptr->left != NULL)
	{
		_ptr = _ptr->left;
	}
	return _ptr;
}

node* delete_a_node(node* _node,int key)
{
	node* temp;
	if (_node == NULL)
	{
		return NULL;
	}
	if (_node->left == NULL && _node->right == NULL)
	{
		delete _node;
		_node = NULL;
		return NULL;
	}

	if (_node->data > key)
		_node->left = delete_a_node(_node->left, key);
	else if(_node->data < key)
		_node->right = delete_a_node(_node->right, key);
	else
	{
		int l_height = Height(_node->left);
		int r_height = Height(_node->right);
		if ( l_height > r_height )
		{
			temp = Pre(_node->left);
			_node->data = temp->data;
			_node->left = delete_a_node(_node->left, temp->data);
		}
		else
		{
			temp = Suc(_node->right);
			_node->data = temp->data;
			_node->right = delete_a_node(_node->right, temp->data);
		}
	}
	return _node;
}

int main()
{
	node  *root=NULL;
	int data[] = { 5,34,78,98,1,2,56,11,22,43,100,88,99,200,50,NULL };
	create_tree(&root, data);

	cout << "Preorder traversal :: ";
	preorder_traversal(root);

	cout << endl;
	cout << "inorder traversal :: ";
	inorder_traversal(root);

	cout << endl;
	int node_to_delete = 56;
	cout << "Delete node:: "<< node_to_delete << endl;
	delete_a_node(root,node_to_delete);
	cout << "inorder traversal :: ";
	inorder_traversal(root);

	cout << endl;
	node_to_delete = 78;
	cout << "Delete node:: " << node_to_delete << endl;
	delete_a_node(root, node_to_delete);
	cout << "inorder traversal :: ";
	inorder_traversal(root);

	cout << endl;
	node_to_delete = 34;
	cout << "Delete node:: " << node_to_delete << endl;
	delete_a_node(root, node_to_delete);
	cout << "inorder traversal :: ";
	inorder_traversal(root);

	cout << endl;
    return 0;
}

