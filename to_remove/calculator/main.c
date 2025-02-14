// main.c
#include <stdio.h>
#include "static_lib/calculator.h"

int main() {
    double a, b;
    int n;

    // Take user input for numbers
    printf("Enter first number: ");
    scanf("%lf", &a);

    printf("Enter second number: ");
    scanf("%lf", &b);

    printf("Enter a number for factorial: ");
    scanf("%d", &n);

    // Perform operations
    printf("Sum: %.2lf\n", sum(a, b));
    printf("Difference: %.2lf\n", difference(a, b));
    printf("Product: %.2lf\n", product(a, b));
    printf("Fraction (a / b): %.2lf\n", fraction(a, b));
    printf("Factorial of %d: %lld\n", n, factorial(n));
    printf("Square root of %.2lf: %.2lf\n", a, square_root(a));

    return 0;
}
