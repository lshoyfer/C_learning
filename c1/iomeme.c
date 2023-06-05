#include <stdio.h>

int main() {
    int c;

    putchar(EOF);
    printf("%d", EOF);

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    putchar(EOF);
    printf("%d", EOF);
}