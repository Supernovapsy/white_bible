#include <stdio.h>
#include "calc.h"

#define BUFFER_SIZE 100
// Buffer has to handle EOF.
static int buffer[BUFFER_SIZE]; // A stack.
static int bufp = 0; // Next position to be pushed.

char getch(void)
{
    char ret = bufp > 0 ? buffer[--bufp] : getchar();
//     if (ret == ' ')
//         printf("getch: space\n");
//     else
//         printf("getch: %c\n", ret);
    return ret;
}

void ungetch(char c)
{
    if (bufp == BUFFER_SIZE)
        printf("Error: buffer full, cannot ungetch!\n");
    else
    {
//         if (c == ' ')
//             printf("ungetch: space\n");
//         else
//             printf("ungetch: %c\n", c);
        buffer[bufp++] = c;
    }
}

