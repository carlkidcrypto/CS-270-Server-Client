/* stack.h
** header file for stack.c
** Name: Carlos Santos
** 12/4/19
** Instructor: Bruce Bolden
** CS 270
*/

#include <stdlib.h>

struct Node { 
   int data; 
   struct Node *next; 
}; 
struct Node* top = NULL;


void display();
int peek();
int pop();
void push(int val);
