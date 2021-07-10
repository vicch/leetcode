// Problem:
// Given a positive integer, write a function to determine if it is a perfect
// square. Do not use any built-in library function such as sqrt().
// 
// Solution:
// If   2^n < x < 2^(n+1)
// Then 2^(n/2) < x^(1/2) < 2^((n+1)/2)
// So by right shifting a number half the number of its binary digits, we can
// get the lower boundary of its possible square root.
// - Get the number of binary digits n.
// - Right shift the number ceil(n/2) bits to get lower boundary of square root.
// - Increment the value and calculate its square.
// - Once the sqaure is greater than the integer, it's not a perfect square.

#include <stdio.h>

#define bool int

bool isPerfectSquare(int num);
int getBinaryDigits(int num);

int main()
{
    printf("%d\n", isPerfectSquare(16));
    printf("%d\n", isPerfectSquare(14));
    printf("%d\n", isPerfectSquare(100));
    printf("%d\n", isPerfectSquare(2446096));
    printf("%d\n", isPerfectSquare(2447096));
    printf("%d\n", isPerfectSquare(2147483647));
    printf("%d\n", isPerfectSquare(2147395600));

    return 0;
}

bool isPerfectSquare(int num)
{
    int unsigned n, base, square;

    n = getBinaryDigits(num);
    for (
        base = num >> ((n + 1) >> 1), square = base * base;
        square < num;
        base++, square = base * base
    );

    return base * base == num;
}

int getBinaryDigits(int num)
{
    int n;
    for (n = 0; num != 0; num >>= 1, n++);
    return n;
}