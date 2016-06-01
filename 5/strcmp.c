#include <stdio.h>

int strcomp(const char*, const char*);

int main()
{
    printf("%d\n", strcomp("hello", "hello how are you"));
    printf("%d\n", strcomp("hello", "hello"));
    printf("%d\n", strcomp("hi", "hello"));
    printf("%d\n", 'i' - 'e');
    printf("%d\n", "hi"[1] - "hello"[1]);

    return 0;
}

int strcomp(const char* s, const char* t)
{
    // Ensures that stops loop when *s and *t are different, OR when the end of
    // either string has been reached.
    int count = 0;
    while (*s - *t == 0 && *s)
        ++s, ++t, ++count;
    return *s - *t;
}
