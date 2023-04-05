#pragma once
#include <exception>
#include <vector>

/*
Part A, BST: implement the MoveToRoot method (3.5 points)
*/
class BST
{
	// You may change internal implementation details if You wish.
	struct node
	{
		int key;
		node* left;
		node * right;

		~node();
		void del();
		void print(int depth = 0);
	};

	node* root;

public:

	/*
	This operation finds the given 'key' in the tree and moves it to the root using single rotations. 
	If the 'key' does not exist in the tree, the method has no effect.

	If the selected node is the root, then do nothing.

	Otherwise, perform a single rotation at the parent, then a single rotation
	at the grandparent, and so on, until the selected node is pulled to to root.
	*/
	node* RR_Rotate(node* x);
	node* LL_Rotate(node* x);
	void MoveToRoot(int key);


	/*
	Default constructor, creates empty tree.
	*/
	BST();

	/*
	Destructor (remember to free all used memory).
	*/
	~BST();

	/*
	Adds a new 'key' to the tree. If 'key' is already contained in the tree, the method has no effect.

	Returns true if and only if the operation succeeds (that is, 'key' was not in the tree).

	Should work in time O(h), where h is the height of the tree.
	*/
	bool Insert(int key);

	/*
	Returns true if and only if 'key' is contained in the tree.

	Works in time O(h), where h is the height of the tree.
	*/
	bool Contains(int key);

	/*
	Prints the tree to the cout stream.
	*/
	void printTree();
};


/*
Part B, Graphs: Implement the HasCycle method (2.5 points)
*/

class IndexOutOfRangeException : std::exception
{
};

/*
Directed graph
*/
class Digraph
{
	bool** tab;
	int n;

public:
	/*
	Creates a digraph with no edges and given number of vertices
	*/
	Digraph(int vertices);

	~Digraph();
	Digraph(const Digraph& g);

	/*
	Adds the directed edge u->v to the digraph.
	If the edge already exists, then the method has no effect.

	If u or v is out of range, then IndexOutOfRangeException is thrown.
	*/
	void AddEdge(int u, int v);

	/*
	Removes the directed edge u->v from the digraph.
	If the edge does not exist, then the method has no effect.

	If u or v is out of range, then IndexOutOfRangeException is thrown.
	*/
	void DeleteEdge(int u, int v);

	/*
	Returns true if an only if the digraph has edge uv.

	If u or v is out of range, then IndexOutOfRangeException is thrown.
	*/
	bool HasEdge(int u, int v);

	/*
	Returns the numbe of vertices of the digraph.
	*/
	int Vertices() { return n; }

	/*
	Checks if the digraph has a directed cycle containing the vertex v.

	Must work in time O(n^2), where n is the number of vertices!
	*/
	bool HasCycle(int v)
	{
	}
};