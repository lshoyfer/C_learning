#include <stdio.h>
#include <ctype.h>

#define IN 1
#define OUT 0

// find largest integer of a set of positive integers
int max(int arr[], int len) {
    int i, max;

    max = 0;
    for (i = 0; i < len; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

void prntraw(int arr[]) { // debug
    int i;
    putchar('\n');
    for (i = 0; i < 26; ++i)
        printf("%d ", arr[i]);
    
    putchar('\n');
    
}

int main() {
    int c, state, wl, i, j, nchar[26];

    for (i = 0; i < 26; ++i)
        nchar[i] = 0;

    wl = 0;
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

    putchar('\n');
    for (i = 0; i < 26; ++i) {
        printf("%c %d\n", 'a' + i, nchar[i]);
    }
    printf("Max: %d\n", max(nchar, 26));
    putchar('\n');

    prntraw(nchar);

    for (i = 0; i < 26; ++i)
        printf("%c ", 'a' + i);
    putchar('\n');
    for (i = 0; i < 26; ++i)
        printf("- ");
    putchar('\n');

    int lines = max(nchar, 26);
    for (i = 0; i < lines; ++i) { 
        for (j = 0; j < 26; ++j) {
            if (nchar[j] > 0) { 
                printf("| ");
                --nchar[j];
            } else
                printf("  ");
        }
        putchar('\n');
    }

   return 0;
}