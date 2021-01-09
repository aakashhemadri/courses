#ifndef B_TREE_H
#define B_TREE_H
// A BTree node

#include<iostream>

typedef struct BTreeNode
{
	// An array of keys
	int *keys;
	// Minimum degree (defines the range for number of keys)
	int miniumDegree;
	// An array of children pointers
	BTreeNode **children;
	// Number of keys
	int numberOfKeys;
	// Holds truth if node is leaf otherwise false
	bool isLeaf;
}BTreeNode;

// A BTree
class BTree
{
	BTreeNode *root; // Pointer to root node
	int minimumDegree;
	
	public:
	// Default Constructor
	BTree();
	// Parameterized Constructor
	BTree(int _minimumDegree, bool _isLeaf);
	//Helper Functions
	// A function to traverse all nodes in a subtree rooted with this node
	// A function to search a key in the subtree rooted with this node. Returns NULL if k is not present.
	// Insert Function.
	void traverse(BTreeNode*);
	BTreeNode* search(BTreeNode*, int _key);
	bool insert(int _key);
	bool insertNonFull(int _key);
	bool splitChild(int _key)
};

#endif
