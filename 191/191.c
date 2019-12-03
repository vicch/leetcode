#include <stdio.h>

#define uint32_t unsigned long

int main()
{
    uint32_t a = 11;
    printf("%d\n", hammingWeight(a));

    return 0;
}

int hammingWeight(uint32_t n)
{
    int i = 0;

    while (n > 0) {
        i += n % 2;
        n = n / 2;
    }

    return i;
}