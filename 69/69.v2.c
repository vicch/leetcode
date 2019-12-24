#include <stdio.h>

int mySqrt(int x);

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
    int l = 0;
    int r = 46340;
    int mid;

    while (l < r) {
        mid = (l + r) / 2;
        if (mid * mid <= x)
            if ((mid + 1) * (mid + 1) > x)
                return mid;
            else
                l = mid + 1;
        else
            r = mid - 1;
    }

    return l;
}