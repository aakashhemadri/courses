#include"avl_tree.h"

AVLTree::AVLTree()
{
	root = NULL;
}

AVLNode* AVLTree::new_node(int key)
{
	AVLNode* node	= new AVLNode;
	node->height	= 1;
	node->data	  	= key;
	node->left	  	= node->right = NULL;

	return node;
}

bool AVLTree::adjust_height(AVLNode *&node)
{
	if(node->left == NULL && node->right == NULL && (node->height = 1))
	{
		return true;
	}
	else if(node->left  == NULL && (node->height = 1 + node->right->height))
	{
		return true;
	}
	else if(node->right == NULL && (node->height = 1 + node->left->height))
	{
		return true;
	}
	else if(node->height== max(node->right->height,node->left->height))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int AVLTree::get_height(AVLNode *&node)
{
	if(node == NULL)
	{
		return 0;
	}
	else
	{
		return node->height;
	}
}

int AVLTree::get_left_height(AVLNode *&node)
{
	if (node == NULL || node->left == NULL)
	{
		return 0;
	}else return node->left->height;
}

int AVLTree::get_right_height(AVLNode *&node)
{
	if (node == NULL || node->right == NULL)
	return 0; else return node->right->height;
}

bool AVLTree::rotate_left(AVLNode *&node)
{
	if(node != NULL)
	{
		AVLNode *y  = node->right;
		node->right = y->left;
		y->left	 = node;
		if(adjust_height(y) && adjust_height(node))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool AVLTree::rotate_right(AVLNode *&node)
{
	if(node != NULL)
	{
		AVLNode *y = node->left;
		node->left = y->right;
		y->right = node;
		if(adjust_height(y) && adjust_height(node))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool AVLTree::balance(AVLNode *&node)
{
	if (get_height(node->left) > get_height(node->right) + 1)
	{
		if (get_left_height(node->left) < get_right_height(node->left))
		{
			rotate_left(node->left);
		}
		rotate_right(node);
		return true;
	}
	else if (get_height(node->right) > get_height(node->left) + 1)
	{
		if (get_right_height(node->right) < get_left_height(node->right))
		{
			rotate_right(node->right);
		}
		rotate_left(node);
		return true;
	}
	else
	{
		return false;
	}
}

bool AVLTree::insert(int &key)
{
	AVLNode *iterator = this->root;
	if(this->root == NULL)
	{
		return this->root = new_node(key);
	}
	while(1)
	{
		if(iterator->data > key)
		{
			if(iterator->left == NULL)
			{
				iterator->left=new_node(key);
  				adjust_height(iterator);
  				balance(iterator);
  				return true;
			}
			else
			{
				iterator=iterator->left;
			}
		}
		else if(iterator->data < key)
		{
			if(iterator->right == NULL)
			{
				iterator->right=new_node(key);
				//adjust_height(iterator);
				adjust_height(iterator);
				balance(iterator);
				return true;
			}
			else
			{
				iterator=iterator->right;
			}
		}
		else
		{
			return true;//as the element already exists it will return as successful.
		}
	}
	return false;//if none of this happens--- which is impossible as all cases are covered then return false.
}

void AVLTree::pre_order(AVLNode *&node)
{
	if(node != NULL)
	{
		std::cout<<"["<<node->data<<":"<<node->height<<"]";
		pre_order(node->left);
		pre_order(node->right);
	}
}

void AVLTree::in_order(AVLNode *&node)
{
	if(node != NULL)
	{
		pre_order(node->left);
		std::cout<<"["<<node->data<<":"<<node->height<<"]";
		pre_order(node->right);
	}
}

void AVLTree::post_order(AVLNode *&node)
{
	if(node != NULL)
	{
		pre_order(node->left);
		pre_order(node->right);
		std::cout<<"["<<node->data<<":"<<node->height<<"]";
	}
}
