#include <stdio.h>

int main()
{
    enum BOOLEAN { NO, YES };

    if (NO == 0)
        printf("No!\n");
    else
        printf("Yes!\n");

    return 0;
}
