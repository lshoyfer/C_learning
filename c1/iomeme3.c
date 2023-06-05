#include <stdio.h>

int main() {
    int c, prev;

    printf("%d", prev);
    while ((c = getchar()) != EOF) {
        if (c == ' ' && prev == ' ');
        else putchar(c);
        prev = c;
    }

}