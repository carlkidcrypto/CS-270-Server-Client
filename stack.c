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
int pop()
{
    if (top == NULL)
        printf("Stack Underflow");
    else
    {
        int temp = top->data;
        printf("The popped element is: %d \n", (top->data));
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