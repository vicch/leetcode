#include <stdio.h>

int trailingZeroes(int n);

int main()
{
    printf("%d:%d\n", 3, trailingZeroes(3));
    printf("%d:%d\n", 5, trailingZeroes(5));
    printf("%d:%d\n", 10, trailingZeroes(10));
    printf("%d:%d\n", 25, trailingZeroes(25));
    printf("%d:%d\n", 125, trailingZeroes(125));

    return 0;
}

int trailingZeroes(int n)
{
    int i = 0;

    while (n > 0) {
        n /= 5;
        i += n;
    }

    return i;
}