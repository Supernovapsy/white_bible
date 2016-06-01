#include <stdio.h>
#include <stdlib.h> // for atof().
#include "calc.h"

#define MAXOP 100

int main()
{
    int c;
    char s[MAXOP];
    double op1, op2;
    while ((c = getop(s)) != EOF && c != SENTINEL)
    {
//         printf("\nc: %c\n", c); // Debug
        switch(c)
        {
            case NUMBER:
//                 printf("s: %s\n", s); // Debug
                push(atof(s));
                break;
            case '\n':
                printf("result:%f\n", pop());
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            case '%':
            {
                op2 = pop(), op1 = pop();
                if ((int) op2 == op2 && (int) op1 == op1)
                    push((int) op1 % (int) op2);
                else
                    printf("Error, operator %% not supported for"
                           "floating-point numbers.\n");
                break;
            }
            default:
                printf("Error, operator %c not recognized\n", c);
                break;
        }
    }

    return 0;
}
