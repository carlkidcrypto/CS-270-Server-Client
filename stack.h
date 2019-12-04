#include <stdlib.h>
struct Node { 
   int data; 
   struct Node *next; 
}; 
struct Node* top = NULL;


void display();
int pop();
void push(int val);
