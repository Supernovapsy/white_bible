#include <stdio.h>
#define TABSTOP 4

/* Given input, output with as few tabs and spaces as possible while achieving
 * the same spacing under the specified tabstop number.
 */

int main()
{
    int c, spaceHeld = 0, count = 3;

    while ((c = getchar()) != EOF)
    {
        count = (count + 1) % TABSTOP;

        if (spaceHeld != 0 && count == 0)
        {
            putchar('\t');
            spaceHeld = 0;
        }

        if (spaceHeld != 0)
        {
            if (c == '\t')
                putchar('\t');
            else if (c != ' ')
            {
                spaceHeld -= TABSTOP - count;
                for (; spaceHeld != 0; --spaceHeld)
                    putchar(' ');
                putchar(c);
            }
        }
        else if (c == ' ')
        {
            spaceHeld = TABSTOP - count;
        }
        else
            putchar(c);

        if (c == '\t' || c == '\n')
        {
            spaceHeld = 0;
            count = 3;
        }
    }

    return 0;
}
