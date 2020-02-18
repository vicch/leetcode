#include <stdio.h>

int climbStairs(int n);

int main()
{
    printf("%d\n", climbStairs(3));
    printf("%d\n", climbStairs(4));
    printf("%d\n", climbStairs(5));
    printf("%d\n", climbStairs(6));
    printf("%d\n", climbStairs(44));

    return 0;
}

int climbStairs(int n)
{
    if (n == 1)
        return 1;

    int a, b;
    a = b = 1;
    for (; n > 1; n--) {
        b += a;
        a = b - a;
    }

    return b;
}