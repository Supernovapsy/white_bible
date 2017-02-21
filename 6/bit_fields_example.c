#include <stdio.h>

int main()
{
    struct
    {
        unsigned happy: 1;
        unsigned sad: 2;
        unsigned confused: 3;
        unsigned focused: 4;
        unsigned furious: 30;
    } fields;

    fields.happy = 0;
    fields.furious = 0x3fffffff;
    fields.sad = 1;
    fields.confused = 1;
    fields.focused = 1;

    printf("%u\n", fields.furious);
    fields.furious = 0x7fffffff;
    printf("%u\n", fields.furious);

    return 0;
}
