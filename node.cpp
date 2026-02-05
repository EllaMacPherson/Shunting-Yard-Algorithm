#include "node.h"

// Constructor
node::node(node* n, node* r, node* l, int v, char o){

  next = n;
  right = r;
  left = l;
  value = v;
  op = o;
  
}
