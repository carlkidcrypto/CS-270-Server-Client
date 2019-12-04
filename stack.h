#include <stdlib.h>
struct Node { 
   int data; 
   struct Node *next; 
}; 
struct Node* top = NULL;


void display();
void pop();
void push(int val);
