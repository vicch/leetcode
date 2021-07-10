#include <stdio.h>

int mySqrt(int x);
int binaryDigits(int n);
long power(int b, int p);

int main()
{
    printf("%d: %d\n", 16, mySqrt(16));
    printf("%d: %d\n", 99, mySqrt(99));
    printf("%d: %d\n", 100, mySqrt(100));
    printf("%d: %d\n", 101, mySqrt(101));
    printf("%d: %d\n", 3, mySqrt(3));
    printf("%d: %d\n", 4, mySqrt(4));
    printf("%d: %d\n", 5, mySqrt(5));
    printf("%d: %d\n", 6, mySqrt(6));
    printf("%d: %d\n", 2147483647, mySqrt(2147483647));

    return 0;
}

int mySqrt(int x)
{
    int d = binaryDigits(x);
    if (d == 0) return 0;

    d = (d + 1) / 2;

    int l = power(2, d - 1);
    int r = l * 2 - 1;
    int mid;

    while (l < r) {
        mid = (l + r) / 2;
        if (power(mid, 2) <= x)
            if (power(mid + 1, 2) > x)
                return mid;
            else
                l = mid + 1;
        else
            r = mid - 1;
    }

    return l;
}

int binaryDigits(int n)
{
    int i = 0;
    for (; n > 0; n >>= 1, i++);
    return i;
}

long power(int b, int p)
{
    long i = 1;
    while (p-- > 0) i *= b;
    return i;
}