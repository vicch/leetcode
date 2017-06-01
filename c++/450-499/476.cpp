// Problem:
// Given a positive integer, output its complement number. The complement
// strategy is to flip the bits of its binary representation.
// - The integer is guaranteed to fit within range of a 32-bit signed integer.
// - Assume no leading zero bit in the integer's binary representation.
// 
// Example:
// Input: 5 (101)
// Output: 2 (010)
// 
// Solution:
// The problem is to remove the leading 1s after negating the number. First get
// the bit length of the number, then make a mask with all 1s except the last
// n bits, and XOR with the negated number.
// 
// Example:
// 5 = 00000101 -> bit length = 3 -> mask = 11111000
// ~5 = 11111010 -> XOR 11111000 = 00000010

#include <iostream>

using namespace std;

class Solution {
public:
    int bitLength(int n) {
        int l;
        for (l = 0; n > 0; n >>= 1, l++);
        return l;
    }
    int findComplement(int num) {
        int mask = (~0) << bitLength(num);
        return mask ^ (~num);
    }
};