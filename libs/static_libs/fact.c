#include "header.h"

unsigned int fact(unsigned int n)
{
    if (n > 0)
        return n * fact(n - 1);
    else
        return 1;
}
