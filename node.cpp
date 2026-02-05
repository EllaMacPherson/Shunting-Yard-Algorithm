#include "node.h"

// Constructor
node::node(node* n, node* r, node* l, int v){

  next = n;
  right = r;
  left = l;
  value = v;
  
}

// Destructer
node::~node(){
  next = NULL;
}
