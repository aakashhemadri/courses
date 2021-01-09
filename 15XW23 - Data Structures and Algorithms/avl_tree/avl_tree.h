#ifndef AVL_TREE_H
#define AVL_TREE_H

#include<iostream>
#define max(a,b) a>b?a:b

typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
//    struct AVLNode *parent;
};

class AVLTree{

    public:
      struct AVLNode *root;
      AVLTree();
      AVLNode* new_node(int key);
      //AVLNode* get_root(){return this->root;}

      bool adjust_height(AVLNode *&);
      int get_height(AVLNode *&);
      int get_left_height(AVLNode *&);
      int get_right_height(AVLNode *&);

      bool rotate_left(AVLNode *&);
      bool rotate_right(AVLNode *&);
      bool balance(AVLNode *&);
      bool insert(int &);

      void pre_order(AVLNode *&);
      void in_order(AVLNode *&);
      void post_order(AVLNode *&);
};
#endif
