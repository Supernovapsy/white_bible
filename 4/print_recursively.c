#include <stdio.h>

void printd(int);

int main()
{
    int n = 1234567890;
    printd(n);

    return 0;
}

void printd_aux(int);

void printd(int n)
{
    printd_aux(n);
    putchar('\n');
}

void printd_aux(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd_aux(n / 10);
    putchar('0' + n % 10);
}
