#include <stdio.h>

// Program to output a Celsius to Farenheit conversion table.

main()
{
    float cel, far;
    int lower = -40, upper = 100, step = 10;

    printf("Celsius to Farenheit Conversion Table\n");
    printf("\n  C    F\n");
    cel = lower;
    while (cel <= upper)
    {
        far = cel * (9.0/5.0) + 32.0;
        printf("%3.0f %6.1f\n", cel, far);
        cel += step;
    }
}
