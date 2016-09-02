#include <stdio.h>

int reverse(int x);

int main()
{
    printf("%d,%d\n", 123, reverse(123));
    printf("%d,%d\n", 1, reverse(1));
    printf("%d,%d\n", 100, reverse(100));
    printf("%d,%d\n", -123, reverse(-123));
    printf("%d,%d\n", 1534236469, reverse(1534236469));

    return 0;
}

int reverse(int x)
{
    long rev = 0;
    int sign = 1;

    if (x < 0) {
        x = -x;
        sign = -1;
    }

    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    rev *= sign;
    if (rev > 2147483647 || rev < -2147483648) {
        rev = 0;
    }

    return (int)rev;
}