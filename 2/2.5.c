#include <stdio.h>

int any(const char[], const char[]);

int main()
{
    printf("%d\n", -1 == any("Hey Nick, how are you doing today?", "hello"));
    printf("%d\n", 10 == any("Hey Nick, how are you doing today?", "how are you"));

    return 0;
}

int any(const char s1[], const char s2[])
{
    int i, j;
    for (i = 0; ; ++i)
    {
        for (j = 0; ; ++j)
        {
            if (!s2[j])
                return i;
            else if (!s1[i + j])
                return -1;
            else if (s2[j] != s1[i + j])
                break;
        }
    }
    return -1;
}
