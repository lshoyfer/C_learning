#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000 // max length of line input (output is longer, factoring in that 1 tab = 8 spaces @ maximum)
#define MAXTABS 100
#define MAXCOLUMNDIGITS 3

int getline_(char line[], int maxline);
int pow_int(int x, int y);
int read_int(int default_int);
void detab(char to[], char from[], int columns);

int main() {
    int len, n;
    char line[MAXLINE];
    char result[MAXLINE + MAXTABS*8];

    n = read_int(8);

    while ((len = getline_(line, MAXLINE)) > 0) {
        printf("\nI\n%s", line);
        detab(result, line, n);
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

void detab(char to[], char from[], int n) {
    int i, j, to_len, n_count;

    to_len = 0;
    n_count = 0;
    for (i = 0; from[i] != '\0'; ++i) {
        if (from[i] == '\t') {
            for (j = 0; j < (n - (n_count % n)); ++j)
                to[to_len++] = ' ';
            n_count = 0;
        }
        else {
            to[to_len++] = from[i];
            ++n_count;
        }
    }

    to[to_len] = '\0';
}