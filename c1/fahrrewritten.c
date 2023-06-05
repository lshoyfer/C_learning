#include <stdio.h>

float f_to_c(float f);

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;

    printf("--Fahrenheit to Celsius--\n");
    while (fahr >= lower) {
        celsius = f_to_c(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr -= step;
    }

    return 0;
}

float f_to_c(float f) {
    return (5.0/9.0) * (f-32.0);
}