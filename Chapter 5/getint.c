#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 10 // for array size
#define BUFFSIZE 10

int buffer[BUFFSIZE];
int buffp = 0; // points to free

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main() {
    int array[MAXSIZE];
    int n, result, c;

    n = 0;

    while (n < MAXSIZE && (result = getint(&array[n])) != EOF) {
        if (result > 0) {
            n++;
        } else {
            c = getch();
            printf("Skipping non-integer character: '");
            if (isprint(c)) {
                putchar(c);
            } else {
                printf("\\x%02X", c);
            }
            printf("'\n");
        }
    }

    printf("Stored %d valid integers in the array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch())) // Skip whitespace
        ;

    if (c == EOF) { // Check for EOF early
        return EOF;
    }

    if (!isdigit(c) && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int next_char = getch();
        if (!isdigit(next_char)) {
            if (next_char != EOF) {
                ungetch(next_char);
            }
            ungetch((sign == -1) ? '-' : '+');
            return 0;
        }
        c = next_char;
    }

    *pn = 0;
    int has_digits = 0; // Track if any digits were parsed
    while (isdigit(c)) {
        *pn = 10 * *pn + (c - '0');
        c = getch();
        has_digits = 1;
    }

    if (!has_digits) { // No digits parsed, return 0
        if (c != EOF) {
            ungetch(c);
        }
        return 0;
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return 1;
}

int getch(void) {
    return buffp > 0 ? buffer[--buffp] : getchar();
}

void ungetch(int c) {
    if (buffp >= BUFFSIZE)
        printf("Buffer full, cant store!!!\n");
    else
        buffer[buffp++] = c;
}
