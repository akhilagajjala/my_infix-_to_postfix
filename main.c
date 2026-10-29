#include <stdio.h>
#include "stack.h"
#include "precedence.h"

char postfix[100];
int j = 0;

int main()
{
    char str[50];
    char c, open;

    printf("Enter the infix expression:\n");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
    {
        c = str[i];

        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z'))
        {
            postfix[j++] = c;
        }
        else if (c == '(' || c == '[' || c == '{')
        {
            push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            open = (c == ')') ? '(' :
                   (c == ']') ? '[' : '{';

            while (top != -1 && stack[top] != open)
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();
        }
        else if (c == '+' || c == '-' ||
                 c == '*' || c == '/' || c == '^')
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   stack[top] != '[' &&
                   stack[top] != '{' &&
                   (precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c) &&
                    c != '^')))
            {
                postfix[j++] = pop();
            }

            push(c);
        }
    }

    while (top != -1)
    {
        c = pop();

        if (c != '(' && c != '[' && c != '{')
            postfix[j++] = c;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


