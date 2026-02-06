#include <iostream>
#include <cstring>
#include <string>
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

// Shunting Yard Algorithm
void shuntingyard(string input); //Puts operators in stack, integers in queue, handle parantheses accordingly, than outputs the queue

// Overall notes:
//   - Take in infix notation -> convert to post fix with: _____
//   - Create an expression tree with that post fix
//   - Then allow user to choose infix, prefix, or postfix as output
//   - ^^^^ USE BINARY TREE FOR THIS NO REUSE OF POSTFIX

int main(){

  node* top = NULL; // Top of stack

  node* front = NULL; // front of queue
  node* rear = NULL; // end of queue

  string input = ""; // Input holder
  string noSpaces = "";

  // Begin the program
  cout<<"Enter a mathematical expression"<<endl;

  getline(cin, input);

  cout<<input<<endl;

  // Remove spaces from string
  for(int i = 0; i < input.length(); i++){
    if(input[i] != ' '){
      noSpaces += input[i]; // Add it to noSpaces
    }
  }

  // Get postfix
  shuntingyard(noSpaces, top, front, rear);
  
}

// Convert infix input to postfix
void shuntingyard(string input, node*& top, node*& front, node*& rear){
  
  // Iterator through each 
  for(int i = 0; i < input.length(); i++){
    // If its a number
    if(int(input[i]) >= 48 && int(input[i]) <= 57){
      // Push to the stack
      push(input[i], top);
    }
    // If its an operator or parantheses
    else if(){
      if(){
	// Do extra operation for parantheses
      }
    }
    else{
      cout<<"You entered an invalid character"<<endl;
      return;
    }
  }

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

