#include <stdio.h>
#include <limits.h>
#include <math.h>

int divide(int dividend, int divisor);
int binaryDivide(unsigned int a, unsigned int b, int* r);

int main()
{
    // printf("%d\n", divide(100, 7));
    // printf("%d\n", divide(100, -7));
    // printf("%d\n", divide(-100, 7));
    // printf("%d\n", divide(-100, -7));
    // printf("%d\n", divide(1, 0));
    // printf("%d\n", divide(0, 1));
    // printf("%d\n", divide(1, 1));
    // printf("%d\n", divide(1, 2));
    printf("%d\n", divide(-2147483648, -1));
    printf("%d\n", divide(-2147483648, 1));
    printf("%d\n", divide(2147483647, -1));
    printf("%d\n", divide(2147483647, 1));
    printf("%d\n", divide(-2147483648, 2));
    printf("%d\n", divide(-2147483648, 2147483647));
    printf("%d\n", divide(2147483647, -2147483648));
    printf("%d\n", divide(-1010369383, -2147483648));

    return 0;
}

int divide(int dividend, int divisor)
{
    if (divisor == 0) return INT_MAX;
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (dividend == divisor) return 1;
    if (divisor == INT_MIN) return 0;

    if (dividend == INT_MAX) {
        if (divisor == 1) return INT_MAX;
        if (divisor == -1) return -INT_MAX;
    } else if (dividend == INT_MIN) {
        if (divisor == 1) return INT_MIN;
        if (divisor == -1) return INT_MAX;
    }

    int sign = dividend < 0 ? (divisor > 0 ? -1 : 1) : (divisor > 0 ? 1 : -1);

    unsigned int dividendAbs = abs(dividend);
    unsigned int divisorAbs = abs(divisor);

    if (dividendAbs < divisorAbs) return 0;

    int r;
    int q = binaryDivide(dividendAbs, divisorAbs, &r);

    if (q == 0) q = INT_MAX;
    else q = (sign == -1) ? -q : q;

    return q;
}

int binaryDivide(unsigned int a, unsigned int b, int* r)
{
    if (a < b) {
        *r = a;
        return 0;
    } else if (a == b) {
        *r = 0;
        return 1;
    } else {
        int l = a & 0x1;
        a >>= 1;
        int r2;
        int q = binaryDivide(a, b, &r2);
        *r = r2 + r2 + l;
        q += q;
        if (*r >= b) {
            *r -= b;
            q += 1;
        }
        return q;
    }
}