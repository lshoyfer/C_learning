#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000 // max length of line input (output is longer, factoring in that 1 tab = 8 spaces @ maximum)

int getline_(char line[], int maxline);
int pow_int(int x, int y);
int read_int(int default_int);
void fold(char to[], char from[], int break_point);

int main() {
    int len, n;
    char line[MAXLINE];
    char result[MAXLINE]; 

    printf("Enter Column Break Point:\n");
    n = read_int(20);


    while ((len = getline_(line, MAXLINE)) > 0) {
        printf("\nI\n%s", line);
        fold(result, line, n);
        printf("\nO\n%s", result);
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

int pow_int(int x, int y) {
    if (y == 0)
        return 1;
    return x * pow_int(x, y-1);
}

int read_int(int d) {
    int c, i, sum, offset;
    int s[3] = { 10, 10, 10 };

    printf("in read_int\n");

    i = 0;
    while ((c=getchar()) != EOF && c!='\n' && i < 3)
        if (c >= 48 && c <= 57)
            s[i++] = c - 48;
    
    sum = 0;
    offset = 0;
    for (i = 2; i >= 0; --i) {
        if (s[i] != 10)
            sum += s[i] * pow_int(10, 2-i-offset);
        else
            ++offset;
    }

    if (sum != 0)
        return sum;

    return d;
}

// i was thinking of using a linked list but ill wait for pointers chapter
// also he said last non-blank but wtvvvvv
void fold(char r[], char l[], int n) {
    int i, r_len;
    char before, current;

    r_len = 0;
    for (i=0; (r[r_len++] = l[i]) != '\0'; ++i) {
        if (i % n == 0 && i != 0) {
            before = l[i-1];
            current = l[i];
            printf("B4: %c\tCR: %c\n", before, current);
            if (
                before != '.' && current != '.' 
                && before != ' ' && current != ' '
                && before != ',' && current != ','
                && before != '\'' && current != '\''
                && before != '"' && current != '"'
            ) {
                r[r_len-1] = '-';
                r[r_len++] = '\n';
                r[r_len++] = '-';
                r[r_len++] = current;
            }
            else {
                r[r_len-1] = '\n';
                r[r_len++] = current;
            }
        }
    } 
    
}