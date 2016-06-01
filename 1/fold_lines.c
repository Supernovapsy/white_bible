// Program to fold long lines into multiple lines.
// No lines can be longer than N characters, but words are better non-broken
// than broken.

// pseudo-code.
// loop
//   read a line of n characters
//   find a space or tab before n
//   OR find the n-1 th character.
//   Now print the characters seen with a newline.

#include <stdio.h>

// Number of chars in a line.
#define N 60

// States of the program.
#define CHARACTER_NOT_FOUND 0
#define FILL_BUFFER         1
#define PRINT_LONG_WORD     2
#define PRINT_LINE          3
#define PRINT_LAST_LINE     4
#define END                 5

// Increment argument to next index.
int inc(int* index);
void print_buffer(char* buffer, int start_index);

int main()
{
    char buffer[N+1];
    int c;
    // Next character to be possibly printed.
    int print_i = 0;
    // Next character to be read.
    int scan_i = 0;
    // Marks the position up-until print_i should print for a line.
    int char_i = 0;

    int state = CHARACTER_NOT_FOUND;

    while (state != END)
    {
//         printf("\n***state*** %d\n", state);
//         print_buffer(buffer, print_i);
//         printf("\n");
        switch (state)
        {
            // Conditions:
            // 1. print_i is before scan_i.
            // 2. scan_i is not yet read.
            // 3. Characters between print_i and scan_i should not have a nonempty
            // character - to - empty character transition.
            case CHARACTER_NOT_FOUND:
                // Search for characters already scanned past the last-printed line
                // for the first nonempty character.
//                 printf("point 1\n");
                while (print_i != scan_i && (buffer[print_i] == ' '
                       || buffer[print_i] == '\t' || buffer[print_i] == '\n'))
                    inc(&print_i);
//                 printf("point 2\n");
                // If no characters already scanned past the last-printed line is
                // non-empty, scan characters until a nonempty character or EOF is
                // reached.
                if (print_i == scan_i)
                {
                    while ((c = getchar()) != EOF && (c == ' ' || c == '\t' || c
                    == '\n'))
                        ;
                    if (c == EOF)
                    {
                        state = END;
                        break;
                    }
                    buffer[print_i] = c;
                    inc(&scan_i);
                }
//                 printf("point 3\n");
                char_i = (scan_i - 1 + N + 1) % (N + 1);
                state = FILL_BUFFER;
                break;

            // Conditions:
            // 1. print_i is on a nonempty character, first one yet to be printed.
            // 2. scan_i is not yet read, and is at least one character ahead of
            // print_i.
            // 3. char_i is one character before scan_i.
            case FILL_BUFFER:
            {
                int first_word_found = 0;
                // Track previous character to identify end-of-words.
                char prev_c = buffer[print_i];
                do
                {
                    c = getchar();
                    if (c == EOF)
                        break;
                    if (!first_word_found)
                    {
                        // If end-of-first-word still not found and next
                        // character is not empty, bring forward char_i with
                        // scan_i.
                        if (c != ' ' && c != '\t' && c != '\n')
                            char_i = scan_i;
                        // If end-of-first-word still not found and next
                        // character is empty, AND previous character is not
                        // empty, end-of-first word is now found, and char_i
                        // happens to be at the right position.
                        else if (prev_c != ' ' && prev_c != '\t')
                            first_word_found = 1;
                    }
                    // Otherwise look for end-of-words.
                    else if (prev_c != ' ' && prev_c != '\t' && (c == ' ' || c ==
                    '\t' || c == '\n'))
                        char_i = (scan_i - 1 + N + 1) % (N + 1);

                    if (c == '\n')
                        break;
                    buffer[scan_i] = c;
                } while (inc(&scan_i) != print_i);
                if (c == EOF)
                    state = END;
                else if (!first_word_found)
                    state = PRINT_LONG_WORD;
                else
                    state = PRINT_LINE;
                break;
            }
            // Conditions for both cases below:
            // 1. scan_i = print_i.
            // 2. char_i is at the last character before the last nonempty
            // character - to - empty character transition. If no such transition
            // exists between print_i and scan_i (which is the entirety of the
            // buffer), then char_i should equal scan_i.
            case PRINT_LONG_WORD:
            {
                int end_i = (char_i - 2 + N + 1) % (N + 1);
                do putchar(buffer[print_i]);
                while (inc(&print_i) != end_i);
                putchar('-');
                putchar('\n');
                state = FILL_BUFFER;
                break;
            }
            case PRINT_LINE:
                inc(&char_i);
                do putchar(buffer[print_i]);
                while (inc(&print_i) != char_i);
                putchar('\n');
                state = CHARACTER_NOT_FOUND;
                break;
            case PRINT_LAST_LINE:
                inc(&char_i);
                do putchar(buffer[print_i]);
                while (inc(&print_i) != scan_i);
                putchar('\n');
                state = END;
                break;
            default:
                printf("Error! non-existent state.\n");
                return 1;
        }
    }

    return 0;
}

int inc(int* i)
{
    return *i = (*i + 1) % (N + 1);
}

void print_buffer(char* buffer, int i)
{
    int end_i = i;
    do putchar(buffer[i]);
    while (inc(&i) != end_i);
}
