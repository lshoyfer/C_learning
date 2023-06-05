#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

int getline_(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getline_(line, MAXLINE)) > 0)
        if (!(len == 1 && line[0] == '\n'))
            printf("--TRIMMED--:\n\n%s\n\n", line);

    return 0;
}


int getline_(char s[], int lim) {
    int i, c;
    bool reading, has_nl;

    has_nl = false;
    reading = false;
    i = 0;
    while (i < lim-1 && (c=getchar())!=EOF && c!='\n')
        if (reading || (c != ' ' && c != '\t')) {
            s[i] = c;
            ++i;
            reading = true;
        }
    if (c == '\n')
        has_nl = true;
 
    while (i > 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
        --i;

    if (has_nl)
        s[++i] = '\n'; 
    s[++i] = '\0';
    return i;
}