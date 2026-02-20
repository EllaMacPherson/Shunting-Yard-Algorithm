#include "node.h"

// Constructor
node::node(node* n, node* r, node* l, int v){

  // Set all me values
  next = n;
  right = r;
  left = l;
  value = v;
  
}

// Destructer
node::~node(){

  right = NULL;
  left = NULL;
  next = NULL;

  delete next;
  delete right;
  delete left;

}
