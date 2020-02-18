#include <stdio.h>

typedef int bool;

bool isPowerOfTwo(int n);

int main()
{
    printf("%d\n", isPowerOfTwo(1));
    printf("%d\n", isPowerOfTwo(2));
    printf("%d\n", isPowerOfTwo(3));
    printf("%d\n", isPowerOfTwo(4));
    printf("%d\n", isPowerOfTwo(5));

    return 0;
}

bool isPowerOfTwo(int n)
{
    if (n < 1)
        return 0;

    while (n > 1) {
        if (n % 2 == 1)
            return 0;
        n >>= 1;
    }
    return 1;
}