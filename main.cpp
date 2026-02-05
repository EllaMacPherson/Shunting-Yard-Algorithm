#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

// Function declerations

// Stack functions -- linear linked list
void push(int input, node*& top); // Add something to stack
node* pop(node*& top); // Remove top value of stack, and return it
node* peek(node*& top); // Look at top value of stack, and return it

// Queue functions -- linear linked list -- use node* head and node* tail for queue whule node* top is for stack
void enqueue(); // Add to  tail of queue 
void dequeue(); // Remove from head of queue 

int main(){

  node* top = NULL; // Top of stack
  
  // Test stack --> should be able to take in int and operators js like queue
  char input = '\0';
  cout<<"What do you want to add to stack?"<<endl;
  cin>>input;
  cin.ignore();
  push(input, top);

  cout<<top->value<<endl;

  input = 0;
  cout<<"What do you want to add to stack?"<<endl;
  cin>>input;
  cin.ignore();
  push(input, top);
  
  cout<<top->value<<" " <<endl;
  cout<<top->next->value<<endl;

  
  input = 0;
  cout<<"What do you want to add to stack?"<<endl;
  cin>>input;
  cin.ignore();
  push(input, top);
  
  cout<<top->value<<" " <<endl;
  cout<<top->next->value<<" " <<endl;
  cout<<top->next->next->value <<endl;

  cout<<"pop test " <<endl;
  node* x = pop(top);
  cout<<x->value<<endl;
  cout<<"New stack: " <<endl;
  cout<<top->value<<" " <<endl;
  cout<<top->next->value<<" " <<endl;
  
  cout<<"peek test: "<<endl;
  node* y = peek(top);
  cout<<y->value<<endl;
  
}

// Peek for stack -- FUNCTIONING 
node* peek(node*& top){
  return top;
}

// Pop for stack -- FUNCTIONING
node* pop(node*& top){
  node* oldTop = top;
  
  top = top->next;
  
  return oldTop;
    
}

// Push for stack -- FUNCTIONING
void push(int input, node*& top){

  if(top == NULL){ // There is nothing else in the list
    top = new node(NULL, NULL, NULL, input); //replace char with input if need to
  }
  else{ // There is something in list, set that equal to next
    node* temp = top;
    top = new node (temp, NULL, NULL, input);
  }
  
}

