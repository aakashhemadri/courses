// C++ implemntation of search() and traverse() methods

#include"b_tree.h"
// Constructor for BTreeNode class
BTree::BTree()
{
	this->root->miniumDegree	= 0;
	this->root->numberOfKeys	= 0;
	this->root->keys			= 0;
	this->root->children		= NULL;
	this->root->isLeaf			= false;
}
BTree::BTree(int _minimumDegree, bool _isLeaf)
{
	// Copy the given minimum degree and isLeaf property
	this->minimumDegree			= minimumDegree;
	this->root->miniumDegree	= _minimumDegree;
	this->root->isLeaf			= _isLeaf;
	// Allocate memory for maximum number of possible keys
	// and child pointers
	this->root->keys			= new int[2*_miniumDegree-1];
	this->root->children		= new BTreeNode *[2*_miniumDegree];
	// Initialize the number of keys as 0

	this->root->numberOfKeys	= 0;
}

// Function to traverse all nodes in a subtree rooted with this node
void BTree::traverse(BTreeNode* node)
{
	// There are n keys and n+1 children, traverse through n keys
	// and first n children
	int iter;
	for(iter = 0; iter < node->numberOfKeys; iter++)
	{
		// If this is not leaf, then before printing key[i],
		// traverse the subtree rooted with child C[i].
		if (node->isLeaf == false)
		{
			traverse(node->children[iter]);
		}
		std::cout<<" "<<node->keys[iter];
	}
	// Print the subtree rooted with last child
	if(node->isLeaf == false)
	{
		traverse(node->children[iter]);
	}
}

// Function to search key k in subtree rooted with this node
BTreeNode* BTree::search(BTreeNode* node ,int _key)
{
	// Find the first key greater than or equal to _key
	int iter = 0;
	while (iter < node->numberOfKeys && _key > node->keys[iter])
	{
		iter++;
	}
	// If the found key is equal to _key, return this node
	if (node->keys[iter] == _key)
	{
		return this->root;
	} // If the key is not found here and this is a leaf node
	else if (node->isLeaf == true)
	{
		return NULL;
	}
	// Go to the appropriate child
	return search(node->children[iter],_key);
}

bool BTree::insert(int _key)
{
	if (this->root == NULL)
	{
		// Allocate memory for root
		this->root 					= new BTreeNode(this->minimumDegree, true);
		this->root->keys[0] 		= _key;  // Insert key
		this->root->numberOfKeys 	= 1;  // Update number of keys in root
	}
	else // If tree is not empty
	{
		// If root is full, then tree grows in height
		if (this->root->numberOfKeys == 2*this->miniumDegree-1)
		{
			// Allocate memory for new root
			BTreeNode *s = new BTreeNode(miniumDegree, false);
			// Make old root as child of new root
			s->children[0] = root;
			// Split the old root and move 1 key to the new root
			splitChild(0, root, s);
			// New root has two children now.  Decide which of the
			// two children is going to have new key
			int i = 0;
			if (s->keys[0] < _key)
				i++;
			insertNonFull(s->children[i],k);
			// Change root
			root = s;
		}
		else  // If root is not full, call insertNonFull for root
		{
			root->insertNonFull(k);
		}
	}
}

bool BTree::insertNonFull(int _key)
{
	int iter = this->numberOfKeys - 1;
	if (this->isLeaf == true)
	{
		while(iter >= 0 && keys[iter] > _key)
		{
			key[i+1] = keys[i];
			i--;
		}
	}
}
