#include<iostream>
  2
  3
  4 typedef struct BSNode{
  5     int data;
  6     BSNode *left;
  7     BSNode *right;
  8 }BSNode;
  9
 10 class BSTree{
 11     public:
 12         BSNode* root;
 13
 14         BSTree();
 15         BSNode* new_node(int&);
 16         bool insert(int&);
 17 }BSTree;
 18
 19 BSTree::BSTree(){
 20     root = NULL;
 21 }
 22
 23 BSNode* BSTree::new_node(int &key){
 24     BSNode* node = new BSNode;
 25     node->data = key;
 26     node->left = node->right = NULL;
 27     return node;
 28 }
 29
 30 bool BSTree::insert(int &key){
 31     BSNode* iterator = this->root;
 32     BSNode* item = new_node(key);
 33     while(1){
 34         if( key < iterator->data )
 35             if( iterator->left != NULL )
 36                 iterator = iterator->left;
 37             else{
 38                 iterator->left = item;
 39                 return true;
 40             }
 41         else if( key > iterator->data )
 42             if( iterator->right != NULL )
"bstree.cpp" 57L, 922C                                                                                                                                