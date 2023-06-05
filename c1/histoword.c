#include <stdio.h>
#include <ctype.h>

#define IN 1
#define OUT 0

// im not checking for repeats/case sensitivities
// also not doing vertical version
int main() {
    int c, state, i, j; 
    int wl_arr[20][10]; // 20 words, max 9 characters long
    /*
        [
            [length, char1, ... , char9],
            ... etc ...
        ]
    */

    // initalize lengths to 0
    for (i = 0; i < 20; ++i)
        wl_arr[i][0] = 0;

    i = -1;
    j = 1;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            j = 1;
        } else if (state == OUT) {
            state = IN;
            if (i < 20) ++i;
        }
        if (state == IN) {
            ++wl_arr[i][0];
            wl_arr[i][j] = c;
            ++j;
        }
    }

    int nwords = i+1;
    for (i = 0; i < nwords; ++i) {
        printf("%d ", wl_arr[i][0]);

        int wl = wl_arr[i][0] + 1;
        for (j = 1; j < wl; ++j)
            printf("%c", wl_arr[i][j]);

        putchar('\n');
    }
    
    putchar('\n');

    for (i = 0; i < nwords; ++i) {
        int wl = wl_arr[i][0];

        for (j = 0; j < 9-wl; ++j)
            putchar('~');
        for (j = 1; j < wl + 1; ++j)
            printf("%c", wl_arr[i][j]);

        
        putchar('|');

        for (j = 0; j < wl; ++j)
            putchar('-');
        
        putchar('\n');
    }
}