#include <stdio.h>

extern void hello_from_src1();

int main() {
    printf("Hello from main.c!\n");
    hello_from_src1();
    return 0;
}
