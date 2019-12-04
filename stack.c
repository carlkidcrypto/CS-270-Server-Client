/* stack.c
** stack implementation file
** Name: Carlos Santos
** 12/4/19
** Instructor: Bruce Bolden
** CS 270
*/

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(int val)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}
int peek()
{
    if (top == NULL)
        printf("Stack Underflow\n");
    else
    {
        // old debug code printf("The popped element is: %d \n", (top->data));
        return (top->data);
    }
}
int pop()
{
    if (top == NULL)
        printf("Stack Underflow\n");
    else
    {
        int temp = top->data;
        // old debug code printf("The popped element is: %d \n", (top->data));
        top = top->next;
        return temp;
    }
}
void display()
{
    struct Node *ptr;
    if (top == NULL)
        printf("stack is empty\n");
    else
    {
        ptr = top;
        printf("Stack elements are:\n");
        while (ptr != NULL)
        {
            printf("Data: %d \n",(ptr->data));
            ptr = ptr->next;
        }
    }
    printf("\n");
}