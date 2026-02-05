#include <iostream>

using namespace std;

class node{
 public:
  node(node* n, node* r, node* l, int v); // Constructer

  ~node(); //destructer

  char value; // For */^ storage, and numbers
  
  node* next; // For linked list
  node* right; // For binary tree
  node* left; // For binary tree

};
