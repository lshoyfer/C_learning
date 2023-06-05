#include <stdio.h>

int main() {
    int c, blanks_ts_nls;

    while ((c = getchar()) != EOF)
       if (c == '\t' || c == ' ' || c == '\n') 
            ++blanks_ts_nls; 

    printf("%d\n", blanks_ts_nls);

}