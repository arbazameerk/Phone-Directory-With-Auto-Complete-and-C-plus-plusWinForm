#pragma once
#include <iostream>
using namespace std;
#include "MyForm.h"
#include "DOUBLY LINK LIST.h"

struct node
{
    string PHONENUMBERAVL, NAMEAVL;
	node* left;
	node* right;
	node(string ph, string na)
	{
		PHONENUMBERAVL = ph;
		NAMEAVL = na;
		left = NULL;
		right = NULL;
	}
};
class AVL:public DoubleLinkedList
{
public:
	bool search;
	string DGN, DGP;
	node* root;
	AVL()
	{
		search = false;
		root = NULL;
	}
	int height(node* root)
	{
		if (root == NULL)
		{
			return -1;
		}

		int left = height(root->left);
		int right = height(root->right);

		if (left > right)
		{
			return (left + 1);
		}
		else
			return (right + 1);
	}
	int balance_factor(node* root)
	{
		if (root == NULL)
		{
			return -1;
		}
		return (height(root->left) - height(root->right));
	}
	node* LR(node* x)
	{
		node* y = x->right;
		node* T = y->left;
		y->left = x;
		x->right = T;
		return y;
	}
	node* RR(node* y)
	{
		node* x = y->left;
		node* T = x->right;
		x->right = y;
		y->left = T;
		return x;
	}
	bool INSERT_AVL(string ph, string name)
	{
		root = INSERTER_AVL(ph, name, root);
		return true;
	}
	node* INSERTER_AVL(string ph, string na, node* root)
	{
		if (root == NULL)
		{
			node* newnode = new node(ph, na);
			newnode->PHONENUMBERAVL = ph;
			newnode->NAMEAVL = na;
			root = newnode;
			return root;
		}
		if (na < root->NAMEAVL)
		{
			root->left = INSERTER_AVL(ph,na, root->left);
		}
		else if (na > root->NAMEAVL)
		{
			root->right = INSERTER_AVL(ph,na, root->right);
		}
		else
		{
			return root;
		}

		int bf = balance_factor(root);

		if (bf == 2 && balance_factor(root->left) >= 0)
		{
			return RR(root);
		}
		else if (bf == -2 && balance_factor(root->right) <= 0)
		{
			return LR(root);
		}
		else if (bf == 2 && balance_factor(root->left) < 0)
		{
			root->left = LR(root->left);
			return RR(root);
		}
		else if (bf == -2 && balance_factor(root->right) > 0)
		{
			root->right = RR(root->right);
			return LR(root);
		}
		return root;
	}
	node* DELETE_AVL(node*& n)
	{
		node* temp = n;
		if (n->left == NULL)
		{
			n = n->right;
			delete(temp);
		}
		else if (n->right == NULL)
		{
			n = n->left;
			delete(temp);
		}
		else
		{
			temp = n->right;

			while (temp->left != NULL)
			{
				temp = temp->left;
			}

			n->NAMEAVL = temp->NAMEAVL;
			DEL_SEARCH_AVL(temp->NAMEAVL, n->right);
		}

		int bf = balance_factor(n);

		if (bf == 2 && balance_factor(n->left) >= 0)
		{
			return RR(n);
		}
		else if (bf == -2 && balance_factor(n->right) <= 0)
		{
			return LR(n);
		}
		else if (bf == 2 && balance_factor(n->left) < 0)
		{
			n->left = LR(n->left);
			return RR(n);
		}
		else if (bf == -2 && balance_factor(n->right) > 0)
		{
			n->right = RR(n->right);
			return LR(n);
		}
		return n;
	}
	void DEL_SEARCH_AVL(string na, node*& root)
	{
		if (root == NULL)
		{
			return;
		}
		if (na < root->NAMEAVL)
		{
			DEL_SEARCH_AVL(na, root->left);
		}
		else if (na > root->NAMEAVL)
		{
			DEL_SEARCH_AVL(na, root->right);
		}
		else
		{
			DELETE_AVL(root);
			search = true;
		}
	}
	void DISP_AVL(node* r)
	{
		if (r == NULL)
			return;
		else
		{
			DISP_AVL(r->left);
			cout << r->PHONENUMBERAVL << "\t|\t" << r->NAMEAVL << "\n";
			DISP_AVL(r->right);
		}
	}
	/*bool UPDATE_AVL(node* root,string prevName, string newName, string newPH)
	{
		if (root == NULL)
			return false;
		else if (root->NAMEAVL == prevName)
		{
			root->NAMEAVL = newName;
			root->PHONENUMBERAVL= newPH;
			return true;
		}
		else if (root->NAMEAVL > prevName)
		{
			bool val = UPDATE_AVL(root->left, prevName, newName, newPH);
			return val;
		}
		else
		{
			bool val = UPDATE_AVL(root->right, prevName, newName, newPH);
			return val;
		}
	}*/
	void READ_AVL()
	{
		string ph, name;//dummy variables
		ifstream read;
		auto start = high_resolution_clock::now();
		read.open("DATA.csv", ios::in);
		string line;
		if (!read.is_open())
		{
			cout << "\n\nCONTACTS FILE NOT FOUND\n\n";
		}
		while (getline(read, line))
		{
			stringstream ss(line);
			getline(ss, ph, ',');
			getline(ss, name, ',');
			INSERT_AVL(ph, name);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "\nTime to insert a all element in the AVL TREE: " << duration.count() << " microseconds\n" << endl;
		read.close();
	}
};
