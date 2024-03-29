// AVL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct node
{
	int data = 0;
	node* left = NULL;
	node* right = NULL;
	int height = 0;
};
node *head = NULL;
int Height(node* root)
{
	int hl, hr;
	hl = root && root->left ? root->left->height : 0;
	hr = root && root->right ? root->right->height : 0;
	return (hl > hr) ? hl + 1 : hr + 1;
}

int BalanceFactor(node* root)
{
	int hl, hr;
	hl = root && root->left ? root->left->height : 0;
	hr = root && root->right ? root->right->height : 0;
	return (hl - hr);
}

node* LL_Rotation(node* root)
{
	node * root_l = root->left;
	node * root_l_r = root->left->right;

	root_l->right = root;
	root->left = root_l_r;

	root->height = Height(root);
	root_l->height = Height(root_l);
	
	if (head == root)
		head = root_l;

	return root_l;
}

node* LR_Rotation(node* p)
{
	node *pl = p->left;
	node *plr = pl->right;

	pl->right = plr->left;
	p->left = plr->right;
	plr->left = pl;	
	plr->right = p;

	pl->height = Height(pl);
	p->height = Height(p);
	plr->height = Height(plr);
	
	if (head == p)
		head = plr;

	return plr;
}

node* RR_Rotation(node* root)
{
	node * root_R = root->right;
	node * root_R_l = root->right->left;

	root_R->left = root;
	root->right = root_R_l;

	root->height = Height(root);
	root_R->height = Height(root_R);

	if (head == root)
		head = root_R;

	return root_R;
}

node* RL_Rotation(node* p)
{
	node *pl = p->right;
	node *plr = pl->left;

	pl->left = plr->right;
	p->right = plr->left;
	plr->right = pl;
	plr->left = p;

	pl->height = Height(pl);
	p->height = Height(p);
	plr->height = Height(plr);

	if (head == p)
		head = plr;

	return plr;
}

node* Insert_node(node* root,int _data)
{
	if (root == NULL)
	{
		node* temp = new node;
		temp->data = _data;
		temp->height = 1;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	if (root->data > _data)
		root->left = Insert_node(root->left, _data);
	else
		root->right = Insert_node(root->right,_data);

	root->height = Height(root);

	if (BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1)
		return LL_Rotation(root);
	else if (BalanceFactor(root) == 2 && BalanceFactor(root->left) == -1)
		return LR_Rotation(root);
	else if (BalanceFactor(root) == -2 && BalanceFactor(root->right) == -1)
		return RR_Rotation(root);
	else if(BalanceFactor(root) == -2 && BalanceFactor(root->right) == 1)
		return RL_Rotation(root);
		
	return root;
}


int main()
{
	head = Insert_node(head, 30);
	Insert_node(head, 20);
	Insert_node(head, 10);
	Insert_node(head, 25);
	Insert_node(head, 11);
	Insert_node(head, 12);

    return 0;
}

