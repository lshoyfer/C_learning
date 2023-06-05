#include <stdio.h>
#include <ctype.h>

#define IN 1
#define OUT 0

int main() {
    int c, state, i, j, nchar[26];

    for (i = 0; i < 26; ++i)
        nchar[i] = 0;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') 
            state = OUT;
        else if (state == OUT)
            state = IN;
        if (state == IN) {
            char lc = tolower(c);
            if (lc >= 'a' && lc <= 'z')
                ++nchar[tolower(c) - 'a'];
        }
    }

    for (i = 0; i < 26; ++i) {
        // printf("%c %d\n", 'a' + i, nchar[i]);
        printf("%c|", 'a' + i);
        for (j = 0; j < nchar[i]; ++j)
            putchar('-');
        putchar('\n');
    }
}