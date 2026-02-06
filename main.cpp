#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

// Function declerations

// Stack functions
void push(char input, node*& top); // Add something to stack
node* pop(node*& top); // Remove top value of stack, and return it
node* peek(node*& top); // Look at top value of stack, and return it

// Queue functions
void enqueue(node*& front, node*& rear, char input); // Add to  tail of queue 
node* dequeue(node*& front, node*& rear); // Remove head of queue and return it

int main(){

  node* top = NULL; // Top of stack

  node* front = NULL; // front of queue
  node* rear = NULL; // end of queue
  
  // Test queue
  char input = '\0';
  cout<<"What do you want to add to queue?"<<endl;
  cin>>input;
  cin.ignore();

  enqueue(front, rear, input);
  cout<<front->value<<endl;

  cout<<"What do you want to add to queue?"<<endl;
  cin>>input;
  cin.ignore();

  enqueue(front, rear, input);
  cout<<front->value<<rear->value<<endl;

  cout<<"What do you want to add to queue?"<<endl;
  cin>>input;
  cin.ignore();

  enqueue(front, rear, input);
  cout<<front->value<<endl;
  cout<<front->next->value<<endl;
  cout<<front->next->next->value<<endl;

  cout<<"dequeue test: " <<endl;
  node* x = dequeue(front, rear);
  cout<<front->value<<endl;
  cout<<front->next->value<<endl;

  cout<<"removed: "<<x->value<<endl;
}

// Dequeue for queue -- FUNCTIONING
node* dequeue(node*& front, node*& rear){

  node* oldFront = front;

  // Set new front to whats after it in queue
  front = front->next;

  // If our new front is NULL than rear must be made the same
  if(front == NULL){
    rear = NULL;
  }

  return oldFront;
}

// Enqueue for queue -- FUNCTIONING 
void enqueue(node*& front, node*& rear, char input){

  // Create new node with no next pointer
  node* x = new node(NULL, NULL, NULL, input);
  
  // Queue is empty
  if(front == NULL && rear == NULL){
    front = x;
    rear = x;
  }
  else{ // There is something in the queue
    rear->next = x;
    rear = x;
  }
  
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
void push(char input, node*& top){

  if(top == NULL){ // There is nothing else in the list
    top = new node(NULL, NULL, NULL, input); //replace char with input if need to
  }
  else{ // There is something in list, set that equal to next
    node* temp = top;
    top = new node (temp, NULL, NULL, input);
  }
  
}

