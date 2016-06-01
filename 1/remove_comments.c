// Removes comments from a C program.
#include <stdio.h>

/* idea:
    two comment states and a non-comment state.
    if not in comment:
        get character
        if character is not '/'
            print character
        else
            get character
            if character is '/' or '*'
                enter corresponding comment state
            else
                print both characters
    if in a comment state
        look for comment state ender
        if found, enter non-comment state.
*/

#define PROGRAM     0
#define SL_COMMENT  1
#define ML_COMMENT  2
#define END         3

int main()
{
    int state = PROGRAM;
    int c, prev_c;

    while (state != END)
    {
        switch (state)
        {
            case PROGRAM:
                // Check if there is still more text and set up prev_c if
                // so for the two-character checking mechanism that follows.
                prev_c = getchar();
                if (prev_c == EOF)
                {
                    state = END;
                    break;
                }
                // If there is still more text, then keep printing characters
                // until comment identifiers are found or EOF is reached.
                while ((c = getchar()) != EOF && !(prev_c == '/' && (c == '/'
                || c == '*')))
                {
                    putchar(prev_c);
                    prev_c = c;
                }
                // Consider all cases for c at this point.
                if (c == EOF)
                {
                    putchar(prev_c);
                    state = END;
                }
                else if (c == '/')
                    state = SL_COMMENT;
                else
                    state = ML_COMMENT;
                break;

            case SL_COMMENT:
                // Keep printing characters until newline (end of comment
                // state) or EOF is reached.
                while ((c = getchar()) != EOF && c != '\n')
                    ;
                // Now handle EOF and the newline cases.
                if (c == EOF)
                    state = END;
                else
                {
                    putchar('\n');
                    state = PROGRAM;
                }
                break;

            case ML_COMMENT:
                // Check if there is still more text and set up prev_c if
                // so for the two-character checking mechanism that follows.
                prev_c = getchar();
                if (prev_c == EOF)
                {
                    state = END;
                    break;
                }
                // Look for EOF or end-of-multiline comment identifier. But
                // unlike PROGRAM, do not print anything.
                while ((c = getchar()) != EOF && !(prev_c == '*' && c ==
                '/'))
                    prev_c = c;
                // Handle EOF and end-of-comment cases.
                if (c == EOF)
                    state = END;
                else
                    state = PROGRAM;
                break;
        }
    }

    return 0;
}
