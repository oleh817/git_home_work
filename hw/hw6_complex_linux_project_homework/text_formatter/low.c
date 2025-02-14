#include <stdio.h>
#include <stdlib.h>

void to_lowercase(char *str);  // Declare the function from shared library

int main() {
    char str[100];

    printf("Enter text to convert to lowercase: ");
    fgets(str, sizeof(str), stdin);

    // Call the function from the shared library
    to_lowercase(str);

    printf("Lowercase text: %s", str);

    return 0;
}
