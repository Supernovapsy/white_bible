#include <stdio.h>
#include "calc.h"

#define STACK_SIZE 100
static double stack[STACK_SIZE];
static int sp = 0; // Next position to be pushed.

double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else
        printf("Error: cannot pop, stack empty!\n");
}

void push(double f)
{
    if (sp < STACK_SIZE)
        stack[sp++] = f;
    else
        printf("Error: cannot push, stack full!\n");
}

