#include "stack.h"

char stack[100];
int top = -1;

void push(char c)
{
    if (top < 99)
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}












