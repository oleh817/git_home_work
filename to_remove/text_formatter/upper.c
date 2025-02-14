#include <stdio.h>
#include <stdlib.h>

void to_uppercase(char *str);  // Declare the function from shared library

int main() {
    char str[100];

    printf("Enter text to convert to uppercase: ");
    fgets(str, sizeof(str), stdin);

    // Call the function from the shared library
    to_uppercase(str);

    printf("Uppercase text: %s", str);

    return 0;
}
