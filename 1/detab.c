#include <stdio.h>
#define TABSTOP 4

/* print each incoming character, or enough spaces to fill a '\t' character.
 */

int main()
{
    int c, count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            short i;
            for (i = 0; i != TABSTOP - count; ++i)
                putchar(' ');
            count = 0;
        }
        else
        {
            putchar(c);
            count = (count + 1) % TABSTOP;
            if (c == '\n')
                count = 0;
        }
    }

    return 0;
}
