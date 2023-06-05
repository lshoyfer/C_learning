#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000 // max length of line input
#define MAXFILE 10000 // max length of all line inputs

int getline_(char line[], int maxline);
void decomment(char to[], char from[]);

int main() {
    int len, n;
    char rline[MAXLINE];
    char data[MAXFILE];
    char result[MAXLINE]; 

    while ()
    while ((len = getline_(rline, MAXLINE)) > 0) {
        printf("\nI\n%s", rline);

        decomment(result, rline);
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

void decomment(char r[], char l[]) {
    int i, r_len;

    r_len = 0;
    for (i=0; (r[r_len++] = l[i]) != '\0'; ++i);
}