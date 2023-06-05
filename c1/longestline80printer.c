#include <stdio.h>
#define MAXLINELEN 1000   /* maximum input line length */
#define MAXLINES 100    /* max amt of lines to hold over 80*/

int getline_(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    int saved_lines;
    int i;
    char line[MAXLINELEN];    /* current input line */
    char longest[MAXLINELEN]; /* longest line saved here */
    char over80[MAXLINES][MAXLINELEN];

    saved_lines = 0;
    max = 0;
    while ((len = getline_(line, MAXLINELEN)) > 0) {
        if (len > 999) {
            printf("\n\tLast line exceeded the 999 character limit...\n");
        }
        if (len > 80 && saved_lines < 100) {
            copy(over80[saved_lines], line);
            ++saved_lines;
        }
        if (len >= max) {
            max = len;
            copy(longest, line);
        }
        printf("\n\tLast line is %d characters long\n\n", len);
    }
    if (max > 0) { /* there was a line */
        printf("--LONGEST--\n\n%s\n\n", longest);

        printf("--LINES OVER 80 CHARACTERS--\n\n");
        for (i=0; i < saved_lines && i < 100; ++i)
            printf("%d.)\t%s\n", i+1, over80[i]); 
    }
    return 0;
}

/* getline:  read a line into s, return length  */
int getline_(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == EOF)
        s[i] = '\0';
    if (c == '\n') {
        s[i] = c;
        s[++i] = '\0';
    } else {
        s[i] = '\0';
        while ((c=getchar())!=EOF && c!='\n')
            ++i;
        if (c == '\n')
            ++i;
    }
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