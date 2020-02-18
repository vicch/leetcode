// Problem:
// Given a positive integer n and possible operations as follow:
// - If n is even, replace n with n/2.
// - If n is odd, you can replace n with either n + 1 or n - 1.
// What is the minimum number of replacements needed for n to become 1?
// 
// Example:
// Input:  8
// Output: 3 (8 -> 4 -> 2 -> 1)
// Input:  7
// Output: 4 (7 -> 8 -> 4 -> 2 -> 1 or 7 -> 6 -> 3 -> 2 -> 1)
// 
// Solution:
// The key is to know when to +1 or -1 when the last bit is 1. This can be done
// by comparing the number of 1's when +1 or -1 and choose the one that has
// less 1's. A special case is 3, when it should -1.
// Instead of counting the number of 1's for the whole number, checking the
// last 2 bits is enough:
// - If the last 2 bits are 01, it should -1.
// - If the last 2 bits are 11, +1 is either equal to -1 or better.

#include <stdio.h>

int integerReplacement(int n);

int main()
{
    return 0;
}

/********** Solution **********/

int integerReplacement(int n)
{
    // MAX_INT is a special case
    if (n == 2147483647)
        return 32;

    int step = 0;

    while (n != 1) {
        if ((n & 1) == 0)
            n >>= 1;
        else if (n == 3 || !(n & 2))
            n--;
        else
            n++;
        step++;
    }

    return step;
}