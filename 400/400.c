// Problem:
// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
// 9, 10, 11, ...
// 
// Example:
// Input: 11
// Output: 0
// 
// Solution:
// Total number of digits = 9 + 90 * 2 + 900 * 3 + ... First find out which
// range n falls into. If n corresponds to a, for example, 3-digit number, then
// for all number before it to have the same number of digits (3), it will need
// 9 * 2 + 90 * 1 more digits, add this number to n, and ceil(n / 3) will be
// the target number, then calculate which digit of this number n refers to,
// and get that digit.

#include <stdio.h>

int main()
{
    return 0;
}

/********** Solution **********/

int getDigitFromBack(long num, int digit);

int findNthDigit(long n)
{
    int digit, i;
    long len, base, total, num;

    for (len = 1, base = total = 9; n > total;) {
        len += 1;
        base *= 10;
        total += len * base;
    }

    for (i = len - 1, base = 9; i > 0; i--, base *= 10)
        n += i * base;

    num = ceil((double)n / len);
    digit = num * len - n + 1;

    return getDigitFromBack(num, digit);
}

int getDigitFromBack(long num, int digit)
{
    for (; digit > 1; digit--, num /= 10);
    return num % 10;
}