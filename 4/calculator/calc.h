#define NUMBER '0'
#define SENTINEL 's'

// Use external variables for stack.
double pop(void);
void push(double);

// Use external variables for buffer.
char getch(void);
void ungetch(char);
// str stores characters to be fed to atof().
int getop(char str[]);
