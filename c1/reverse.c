#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

int getline_(char line[], int maxline);
void reverse(char to[], char from[], int str_len);

int main() {
    int len;
    char line[MAXLINE];
    char reversed[MAXLINE];

    while ((len = getline_(line, MAXLINE)) > 0) {
        printf("\n\nB4: %s\n", line);
        reverse(reversed, line, len);
        printf("\nAFTR: %s\n", reversed);
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

void reverse(char to[], char from[], int len) {
    int i;

    for (i = 0; i < len && (to[len-1-i] = from[i]) != '\0'; ++i);

    to[i] = '\0';
}