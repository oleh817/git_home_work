// calculator.c
#include <math.h>  // For sqrt
#include <stdio.h>  // For printf

// Function to calculate the sum
double sum(double a, double b) {
    return a + b;
}

// Function to calculate the difference
double difference(double a, double b) {
    return a - b;
}

// Function to calculate the product
double product(double a, double b) {
    return a * b;
}

// Function to calculate the fraction (division)
double fraction(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0; // Error case
    }
    return a / b;
}

// Function to calculate the factorial
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the square root
double square_root(double a) {
    if (a < 0) {
        printf("Error: Negative input for square root!\n");
        return -1; // Error case
    }
    return sqrt(a);
}
