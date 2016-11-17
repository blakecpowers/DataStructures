#ifndef __LIST_H
#define __LIST_H


class Node {
public:
	int val;		// Node value
	class Node *next;	// Next node pointer

	Node();			// Constructor
	void Print();
};

// Pointer to a Node class
typedef class Node *NodePtr;

class List {
public:
	int count;		// Number of nodes in the list
	class Node *first;	// First node pointer

	List();			// Constructor
	void Insert(NodePtr n);	// Insert node in list
	NodePtr Find(int val);	// Find first occurence of node containing val
	void Remove(NodePtr n);	// Remove first occurence of node in list
	void Print();		// Print list contents
};

// Pointer to a List class
typedef class List *ListPtr;


#endif
