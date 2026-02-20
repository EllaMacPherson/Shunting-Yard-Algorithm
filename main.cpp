/*
  Shunting Yard Algorithm 2026 2/20
  Ella MacPherson C++

  - Take in infix notation -> convert to post fix with: shunting yard algorithm
  - Create an expression tree with that post fix
  - Then allow user to choose infix, prefix, or postfix as output

 */

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
void shuntingyard(string input, node*& top, node*& front, node*& rear); //Puts operators in stack, integers in queue, handle parantheses accordingly, than outputs the queue
int precedence(char input); // Return precedence of a character

// Binary Tree Algorithms
void build(string input, node*& top); // Build the binary expression tree
void pushNode(node* input, node*& top); // Push an already formed node and NOT a char
void infix(node* current); // Output infix notation from binary expression tree
void postfix(node* current); // Output postfix notation from binary expression tree
void prefix(node* current); // Ouput prefix notation from binary expression

// Main start of program

int main(){

  node* top = NULL; // Top of stack

  node* front = NULL; // front of queue
  node* rear = NULL; // end of queue

  string input = ""; // Input holder
  string noSpaces = ""; // Holds string with no spaces
  string treeInput = ""; // What is fed into binary tree, in postfix

  // Begin the program
  cout<<"Enter a mathematical expression"<<endl;

  getline(cin, input);

  // Remove spaces from string
  for(int i = 0; i < input.length(); i++){
    if(input[i] != ' '){
      noSpaces += input[i]; // Add it to noSpaces
    }
  }

  // Get postfix
  shuntingyard(noSpaces, top, front, rear);

  // Print out the postfix
  cout<<"Postfix: ";

  // Store current node
  node* printer;
  // While not at end of queue
  while(front != NULL){
    printer = dequeue(front, rear);
    // Add it to the string that will be put into the binary expression tree
    treeInput += printer->value;
  }

  // Print out per instructions
  cout<<treeInput<<endl;

  // Build binary expression tree
  build(treeInput, top);
  // Create variable to hold the root of tree and print to test
  node* root = peek(top);
  cout<<"Root of tree created: ";
  cout<<root->value<<endl;

  // Repeat FOREVERR
  while(true){
    // Clear the input
    input = "";
  
    cout<<"Enter, PREFIX, INFIX, or POSTFIX to convert to corresponding notation"<<endl;
    getline(cin, input);

    // Check input and run corresponding functions...
    if (input == "INFIX" || input == "infix"){
      infix(root);
      cout<<endl;
    }
    else if (input == "POSTFIX" || input == "postfix"){
      postfix(root);
      cout<<endl;
    }
    else if (input == "PREFIX" || input == "prefix"){
      prefix(root);
      cout<<endl;
    }
    else{
      // They misentered something
      cout<<"Enter a valid command"<<endl;
    }
  }
  
}

// Use tree to output prefix notation, recursively
void prefix(node* current){
  // Output current value
  cout<<current->value<< " " ;

  // Check left
  if(current->left != NULL){
    prefix(current->left);
  }

  // Check right
  if(current->right != NULL){
    prefix(current->right);
  }
}

// Use tree to output postfix notation, recursively
void postfix(node* current){

  // Check Left
  if(current->left != NULL){
    postfix(current->left);
  }

  // Check right
  if(current->right != NULL){
    postfix(current->right);
  }

  // Output current value
  cout<<current->value<< " " ;
  
}

// Use tree to output infix notation, recursively
void infix(node* current){

  // Check left
  if(current->left != NULL){
    infix(current->left); 
  }
  // Output current value
  cout<<current->value<< " ";

  // Check right
  if(current->right != NULL){ 
    infix(current->right);
  }
  
}


// Build an expression tree
void build(string input, node*& top){

  // Iterate through the input
  for(int i = 0; i < input.length(); i++){
    //if char is int
    if(int(input[i]) >= 48 && int(input[i]) <= 57){
      // Push it to stack
      push(input[i], top);
    }

    // If its an operator
    else if(input[i] == '+' || input[i] == '-' || input[i] == '*' ||
	    input[i] == '/' || input[i] == '^'){
      // Create left and right nodes by poping from stack
      node* leftS = pop(top);
      node* rightS = pop(top);

      // Create a new node with all those values
      node* treeNode = new node(NULL, leftS, rightS, input[i]);

      // Use a function to push the node to the top of the stack 
      pushNode(treeNode, top); 
    }
  }

  // Done iterating through input
  return;
}


// Push a node to the stack, not a value that then creates a npde
void pushNode(node* input, node*& top){

  if(top == NULL){ // There is nothing else in the list
    top = input; //replace char with input if need to
  }
  else{ // There is something in list, set that equal to next
    node* temp = top;
    top = input;
    top->next = temp;
  }
  
}

// Convert infix input to postfix
void shuntingyard(string input, node*& top, node*& front, node*& rear){

  // Iterate through each char
  for(int i = 0; i < input.length(); i++){
    // If its a number
    if(int(input[i]) >= 48 && int(input[i]) <= 57){
      // add it to queue
      enqueue(front, rear, input[i]);
    }
    
    // If its an operator
    else if(input[i] == '+' || input[i] == '-' || input[i] == '*' ||
	    input[i] == '/' || input[i] == '^'){
      // Send it to the queue... I'm not sure if those while loop ever calls but everythng is working so I am NOT touching it
      while(top != NULL && peek(top)->value != '(' && precedence(peek(top)->value) >= precedence(input[i])){
	enqueue(front, rear, pop(top)->value);
      }
	
      push(input[i], top);
    }
    
    // If its a left parantheses
    else if(input[i] == '('){
      push(input[i], top); // Push it to stack
    }

    // If its a right parantheses
    else if(input[i] == ')'){
      // Move items from stack into queue until we reach the end parantheses
      while(peek(top)->value != '(' && top != NULL){ //Checks if top is (
	// Move top of stack to queue
	if(top->next != NULL){
	  enqueue(front, rear, pop(top)->value); // Add to queue
	}else{
	  cout<<"Mismatched parantheses, please enter an accurate equaton"<<endl;
	  return;
	}
      }

      // Delete node
      node* x = pop(top);
      delete x;
    }
    
    else{ // Character doesn't match any of above
      cout<<"You entered an invalid character, restart program to retry"<<endl;
      return;
    }
  }

  // Now move remaining from stack to queue
  node* temp;
  while(top != NULL){
    // Verify that parantheses aren't cooked
    if(peek(top)->value == '('){
      cout<<"There are mismatched parantheses, please enter a valid expression"<<endl;
      return;
    }
    // If not mismatchd paaranthese move it to the queue
    temp = pop(top);
    enqueue(front, rear, temp->value);
  }
  
}

// Return precedence of a value
int precedence(char input){

  if(input == '-' || input == '+'){ // Lowest precedence 
    return 1;
  }
  if(input == '*'|| input == '/'){
    return 2;
  }
  if(input = '^'){
    return 3;
  }
  if(input  == ')' || input == '('){ // Highest precedence
    return 4;
  }

  return 0;
  
}

// Dequeue for queue
node* dequeue(node*& front, node*& rear){

  // Store old front
  node* oldFront = front;

  // Set new front to whats after it in queue
  front = front->next;

  // If our new front is NULL than rear must be made the same
  if(front == NULL){
    rear = NULL;
  }

  return oldFront;
}

// Enqueue for queue
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

// Peek for stack
node* peek(node*& top){
  return top;
}

// Pop for stack
node* pop(node*& top){
  // Store old top
  node* oldTop = top;

  // If next is not NULL, set top to next item down
  if(top->next != NULL){
    top = top->next;
  }
  else{
    // If not just set equal to NULL
    top = NULL;
  }
  
  return oldTop;
    
}

// Push for stack
void push(char input, node*& top){

  if(top == NULL){ // There is nothing else in the list
    top = new node(NULL, NULL, NULL, input); //replace char with input if need to
  }
  else{ // There is something in list, set that equal to next
    node* temp = top;
    top = new node (temp, NULL, NULL, input);
  }
  
}

// Hallelujah!!!!!!!!!!!!!!!!!!!!!!!!!!!

