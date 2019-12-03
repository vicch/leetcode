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
// Solution (NOT WORKING):
// First consider each bit 1 needs 2 steps to eliminate, each bit 0 needs 1
// step to eliminate. And each bit 1 carries over 1 to its left bit, if its
// left bit is 1, its step minus 1, if it's 0, its step plus 1.

#include <stdio.h>

int integerReplacement(int n);

int main()
{
    return 0;
}

/********** Solution **********/

int integerReplacement(int n)
{
    int step, bit, lbit, carry;

    for (step = carry = 0, bit = -1; n != 1; n >>= 1) {
        lbit = bit;
        bit = n & 1;
        if (bit == 0) {
            step += 1 + carry;
            carry = (lbit > 0 && (n & 2) && (n & 4)) ? 1 : 0;
        } else {
            step += 2 - carry;
            carry = (lbit < 1 && !(n & 2)) ? 0 : 1;
        }
    }

    return step + carry;
}