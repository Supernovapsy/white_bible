#include <stdio.h>
#define MAXLINE 50

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void echo();

int main()
{
    int len, max = 0;
    char line[MAXLINE], maxLine[MAXLINE];

    while ((len = getLine(line, MAXLINE)) != 0)
    {
        // Check for overflow.
        // If there is overflow, then a character other than '\n' precedes the '\0' character.
        if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n')
        {
            int c;
            while ((c = getchar()) != EOF && c != '\n')
                ++len;
            if (c == '\n')
                ++len;
        }
        if (len > max)
        {
            max = len;
            copy(maxLine, line);
        }
    }

    if (max != 0)
        printf("length: %d, %s\n", max, maxLine);

    return 0;
}

void echo()
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}

// Assumes "to" has enough space for "from".
void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}

int getLine(char s[], int lim)
{
    int i, c;

    // Ordering in the conditional expression is crucial.
    for (i = 0; i != lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}
