// Problem:
// Super ugly numbers are positive numbers whose all prime factors are in the
// given prime list primes of size k. Write a program to find the nth super
// ugly number.
// - 1 is a super ugly number for any given primes.
// - The given numbers in primes are in ascending order.
// - 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
// - The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
// 
// Example:
// Input: primes = [2, 7, 13, 19], n = 8
// Output: 16 (1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32, ...)
// 
// Solution:
// - Keep a sorted sequence of ugly numbers, start with the primes.
// - Pop an ugly number from the start, multiply it by the primes and push the
//   results into the sequence.
// - Each number only multiply with primes less than or equal to its biggest
//   prime factor. For example, 14 only multiplies 2 and 7, but not 13 and 19.
// 
// Example:
// Input: primes = [2, 7, 13, 19], n = 8
// Sequence: 2, 7, 13, 19 (pop 2, push 4)
//           4, 7, 13, 19 (pop 4, push 8)
//           7, 8, 13, 19 (pop 7, push 14, 49)
//           8, 13, 14, 19, 49 (pop 8, push 16)
//           13, 14, 16, 19, 49 (pop 13, push 26, 91, 169)
//           14, 16, 19, 26, 49, 91, 169 (pop 14, push 28, 98)
//           16, 19, 26, 28, 49, 91, 98, 169
// Output: 16

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1)
            return 1;

        int size, i;
        long num;
        map<long, int> seq;
        map<long, int>::iterator it;

        size = primes.size();

        for (i = 0; i < size; i++)
            seq[primes[i]] = i;

        it = seq.begin();

        while (--n > 1) {
            for (i = 0; i <= it->second; i++) {
                num = it->first * primes[i];

                // Ignore values over the limit
                if (num > 2147483647)
                    break;

                seq[num] = it->second;
            }

            // Do not erase passed values, just move forward to next
            it = next(it);
        }

        return (int)it->first;
    }
};