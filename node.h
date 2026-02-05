#include <iostream>

using namespace std;

class node{
 public:
  node(node* n, node* r, node* l, int v, char o); // Constructer

  int value; // for # storage <-- DO I NEEDA EVEN SEPERATE THESE -> check end goal of project
  char op; // For */^ storage
  
  node* next; // For linked list
  node* right; // For binary tree
  node* left; // For binary tree

};
