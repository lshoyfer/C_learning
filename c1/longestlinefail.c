#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */
#define OVERFLOWN 1
#define BOUNDED 0

int getline_(char line[], int maxline, int *line_status);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    int status;
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    status = BOUNDED;
    while ((len = getline_(line, MAXLINE, &status)) > 0)
        printf("\t\t--STATUS IS: %d", status);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)  /* there was a line */
        printf("%s", longest);
    return 0;
}

/* getline:  read a line into s, return length  */
int getline_(char s[], int lim, int *status)
{
    if (*status == OVERFLOWN) {
        *status = BOUNDED;
        return 1;
    }

    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    } else {
        printf("--{Character limit exceeded, cutting everything after character 999}--");
        *status = OVERFLOWN;
    }
    s[i] = '\0';

    printf("\n\tLast line was %d characters long\n\n", i);
    return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}