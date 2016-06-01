// Hello world.

// Links functions defined in the standard input/output library, which is
// defined in the ANSI standard.
#include <stdio.h>

// This function defaults to int as the return type.
test()
{
    return 0;
}

// The "main" function is special: it is the starting point for all C programs.
main() // Compiler makes the return type default to int.
{
    // While C is free-form, it does not allow strings to extend over two
    // lines with a single pair of double-quotes.
    printf("hello world!\n")
    ; // Although many other parts of the program can.
    // \c translates to just c. Since '\c' is unrecognized, the backslash is
    // ignored.
    printf(
        "%d\c\n", test());
}
