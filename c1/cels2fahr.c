#include <stdio.h>

int main() {
    float celsius, fahr;
    float lower, upper, step;

    lower = 75;
    upper = 405;
    step = 15;

    celsius = lower;

    printf("--CELSIUS 2 FAHRENHEIT--\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.2f\n", celsius, fahr);
        celsius += step;
    }
}