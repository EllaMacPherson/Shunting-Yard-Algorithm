#include <iostream>
#include <string>
#include "node.h"

using namespace std;

// Function declerations

// Stack functions -- linear linked list
void push(int input, node*& top);
void pop();
void peak();

// Queue functions -- double linked list
void enqueue();
void dequeue();

int main(){


  node* top = NULL; // Top of stack
  // Test stack --> should be able to take in int and operators js like queue
  int input = 0;
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
}

// Push for stack -- FUNCTIONING
void push(int input, node*& top){

  if(top == NULL){ // There is nothing else in the list
    top = new node(NULL, NULL, NULL, input, '\0'); //replace char with input if need to
  }
  else{ // There is something in list, set that equal to next
    node* temp = top;
    top = new node (temp, NULL, NULL, input, '\0');
  }
  
}
