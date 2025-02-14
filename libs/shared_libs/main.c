#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int f;
    int a;
    int b;

    printf("Enter the number to calculate the factorial: ");
    scanf("%i", &f);

    printf("fact(%d) = %u\n", f, fact(f));  // Змінили %lu на %u

    printf("Enter first number to calculate sum: ");
    scanf("%i", &a);

    printf("Enter second number to calculate sum: ");
    scanf("%i", &b);

    printf("%d + %d = %ld\n", a, b, add(a, b));

    return 0;
}
