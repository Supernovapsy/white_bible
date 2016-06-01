#include <stdio.h>
#include <ctype.h>
#include "calc.h"

// str stores characters to be fed to atof().
int getop(char s[])
{
    /*
    If one compares this implementation with the one in kr, one would notice
    that this one is bigger and harder to understand. The reason is because
    kr's version eliminates the 'non-number character' path first before
    handles the 'number characters' case. This allowed assumptions to be made
    in that second part of the program, which took away any need to check
    whether s stored a number or not.
    */
    int c, i = 0;
    // Skip spaces, but not newlines.
    while ((c = getch()) != EOF && isspace(c) && c != '\n')
        ;

    // Exit the program upon seeing the sentinel.
    if (c == SENTINEL)
        return SENTINEL;

    // Check if the string here is a number, and store the number characters
    // into s.
    if (isdigit(c) || c == '.' || c == '+' || c == '-')
    {
        s[i++] = c;
        while ((c = getch()) != EOF && isdigit(c))
            s[i++] = c;
        if (s[0] != '.' && c == '.')
        {
            s[i++] = c;
            while ((c = getch()) != EOF && isdigit(c))
                s[i++] = c;
        }
    }

    // Store all read characters into s. Here there is one left to be stored.
    s[i] = c;

    // Exit conditions.
    // 1. A number was read into s.
    // Return flag saying a number was read.
    int j, digit_exists = 0;
    for (j = 0; j != i; ++j)
    {
        if (isdigit(s[j]))
        {
            digit_exists = 1;
            break;
        }
    }
    if (digit_exists)
    {
        ungetch(s[i]);
        s[i] = '\0';
        return NUMBER;
    }

    // 3. Some characters were read into s, but it is not a number.
    // Return the first such character read.
    for (; i != 0; --i)
        ungetch(s[i]);
    return s[0];
}
