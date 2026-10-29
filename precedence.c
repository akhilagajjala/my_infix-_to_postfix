#include”precenence.h”

int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
            return 0;
    }
}
