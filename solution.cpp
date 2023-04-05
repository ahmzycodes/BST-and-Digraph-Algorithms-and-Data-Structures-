#include "Task.h"
#include <iostream>
#include <stack>
using namespace std;

#define USE_COLORS

#ifdef USE_COLORS
#include <windows.h>

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // USE_COLORS



BST::node* BST::RR_Rotate(node* x)
{
    node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
 

BST::node* BST::LL_Rotate(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

void BST::MoveToRoot(int key)
{
	// TODO


		node* header = new node;
		header->left = header->right = nullptr;
		node* LeftTreeMax = header;
		node* RightTreeMin = header;
		while (1)
		{
			if (key < root->key)
			{
				if (!root->left)
					break;
				if (key < root->left->key)
				{
					root = RR_Rotate(root);
					if (!root->left)
						break;
				}
				RightTreeMin->left = root;
				RightTreeMin = RightTreeMin->left;
				root = root->left;
				RightTreeMin->left = nullptr;
			}
			else if (key > root->key)
			{
				if (!root->right)
					break;
				if (key > root->right->key)
				{
					root = LL_Rotate(root);
					if (!root->right)
						break;
				}
				LeftTreeMax->right = root;
				LeftTreeMax = LeftTreeMax->right;
				root = root->right;
				LeftTreeMax->right = nullptr;
			}
			else
				break;
		}
		LeftTreeMax->right = root->left;
		RightTreeMin->left = root->right;
		root->left = header->right;
		root->right = header->right;
	}




BST::BST()
{
	root = nullptr;
}

BST::node::~node()
{
}

void BST::node::del()
{
	if (left != nullptr)
		left->del();
	if (right != nullptr)
		right->del();
	delete this;
}

BST::~BST()
{
	if (root != nullptr)
		root->del();
}

bool BST::Insert(int key)
{
	node** n = &root;
	while (*n != nullptr)
		if (key < (*n)->key)
			n = &((*n)->left);
		else if (key > (*n)->key)
			n = &((*n)->right);
		else
			return false;
	*n = new node;
	(*n)->left = (*n)->right = nullptr;
	(*n)->key = key;
	return true;
}

#ifdef USE_COLORS
WORD getcol(int depth)
{
	WORD flag = 0;
	int reddepth = depth % 7;
	if (reddepth >= 3)
		reddepth = (reddepth + 1) % 7;
	if (reddepth % 2 == 0)
		flag = flag | FOREGROUND_RED;
	if (reddepth % 4 < 2)
		flag = flag | FOREGROUND_GREEN;
	if (reddepth < 4)
		flag = flag | FOREGROUND_BLUE;
	if (depth >= 7)
		flag = flag | FOREGROUND_INTENSITY;
	return flag;
}
#endif // USE_COLORS

void BST::node::print(int depth)
{
#ifdef USE_COLORS
	SetConsoleTextAttribute(hOut, getcol(depth));
#endif // USE_COLORS
	cout << "(";
	if (left != nullptr)
		left->print(depth + 1);
#ifdef USE_COLORS
	SetConsoleTextAttribute(hOut, getcol(depth));
#endif // USE_COLORS
	cout << key;
	if (right != nullptr)
		right->print(depth + 1);
#ifdef USE_COLORS
	SetConsoleTextAttribute(hOut, getcol(depth));
#endif // USE_COLORS
	cout << ")";
}

void BST::printTree()
{
	if (root != nullptr)
		root->print();
}




bool BST::Contains(int key)
{
	MoveToRoot(key);
	return (root && root->key == key);
}

Digraph::Digraph(int n)
{
	this->n = n;
	tab = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new bool[n];
		for (int j = 0; j < n; j++)
			tab[i][j] = false;
	}
}

Digraph::~Digraph()
{
	for (int i = 0; i < n; i++)
		delete[] tab[i];
	delete[] tab;
}

Digraph::Digraph(const Digraph& g)
{
	n = g.n;
	tab = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new bool[n];
		for (int j = 0; j < n; j++)
			tab[i][j] = g.tab[i][j];
	}
}

void Digraph::AddEdge(int u, int v)
{
	if (u < 0 || u >= n || v < 0 || v >= n || u == v)
		throw IndexOutOfRangeException();
	tab[u][v] = true;
}

void Digraph::DeleteEdge(int u, int v)
{
	if (u < 0 || u >= n || v < 0 || v >= n || u == v)
		throw IndexOutOfRangeException();
	tab[u][v] = false;
}

bool Digraph::HasEdge(int u, int v)
{
	if (u < 0 || u >= n || v < 0 || v >= n || u == v)
		throw IndexOutOfRangeException();
	return tab[u][v];
}

bool Digraph::HasCycle(int v)
{
	// TODO

	color[v] = 1;
	for (int u = 0; u < n; u++) {
		if (color[u] == 0) {
			parent[u] = v;
			if (HasCycle(u))
				return true;
		}
		else if (color[u] == 1) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
	}
	color[v] = 2;
	return false;

}