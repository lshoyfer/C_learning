#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000 // max length of line input (output is longer, factoring in that 1 tab = 8 spaces @ maximum)
#define MAXTABS 100
#define MAXCOLUMNDIGITS 3

int getline_(char line[], int maxline);
int pow_int(int x, int y);
int read_int(int default_int);
void entab(char to[], char from[], int columns);

int main() {
    int len, n;
    char line[MAXLINE];
    char result[MAXLINE];

    n = read_int(8);

    printf("n: %d\tn+5: %d\n", n, n+5);

    while ((len = getline_(line, MAXLINE)) > 0) {
        printf("\nI\n%s", line);
        entab(result, line, n);
        printf("\nO\n%s", result);
    }

    return 0;
}


int getline_(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

int pow_int(int x, int y) {
    if (y == 0)
        return 1;
    return x * pow_int(x, y-1);
}

int read_int(int d) {
    int c, i, sum, offset;
    int s[MAXCOLUMNDIGITS] = { 10, 10, 10 };

    printf("in read_int\n");

    i = 0;
    while ((c=getchar()) != EOF && c!='\n' && i < MAXCOLUMNDIGITS)
        if (c >= 48 && c <= 57)
            s[i++] = c - 48;
    
    sum = 0;
    offset = 0;
    for (i = MAXCOLUMNDIGITS-1; i >= 0; --i) {
        if (s[i] != 10)
            sum += s[i] * pow_int(10, 2-i-offset);
        else
            ++offset;
    }

    if (sum != 0)
        return sum;

    return d;
}

void entab(char to[], char from[], int n) {
    int i, j, to_len, n_count, spaces;
    int buffer[n];

    for (i = 0; i < n; ++i)
        buffer[i] = '\0';

    to_len = 0;
    spaces = 0;
    n_count = 0;

    // lots of code dupliction but oh well! i dont feel like refactoring
    for (i = 0; from[i] != '\0'; ++i) {
        ++n_count;
        if (n_count % n != 0) {
            if (from[i] == ' ')
                ++spaces;
            else {
                for (j = 0; j < spaces; ++j)
                    to[to_len++] = ' ';
                spaces = 0;

                to[to_len++] = from[i];
            }
        }
        else if (spaces > 0) {
            if (from[i] != ' ') {
                for (j = 0; j < spaces; ++j)
                    to[to_len++] = ' ';    
                to[to_len++] = from[i];
            }
            else {
                to[to_len++] = from[i];
                // if (from[i] != '\t')
                to[to_len++] = '\t';
            }
            spaces = 0;
            n_count = 0;
        }
        else
            to[to_len++] = from[i];
    }

    to[to_len] = '\0';
}

// check in n
    // in n
        // add space
        // if char found, reset spaces

    // out n
        // reset space