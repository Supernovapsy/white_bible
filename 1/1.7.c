#include <stdio.h>

// Program to print the value of EOF, test integer behaviour of characters, and
// print size of types.

main()
{
    printf("%d\n", EOF);

    char c = '\0';
    printf("%d\n", --c == EOF);

    printf("%d\n", sizeof(long double));
}
