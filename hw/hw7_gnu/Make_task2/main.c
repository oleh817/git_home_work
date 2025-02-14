#include <stdio.h>

extern void hello_from_src1();
extern void hello_from_src2();
extern void hello_from_src3();

int main() {
    hello_from_src1();
    hello_from_src2();
    hello_from_src3();
    return 0;
}
