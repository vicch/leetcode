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
// The way to get the next ugly number is by comparing several candidates, each
// prime number multiplies a certain ugly number in the previous sequence is a
// candidate. Find the smallest candidate, add it to the sequence, and update
// the "certain" ugly number each prime number should multiply with nextly.
// 
// Example:
// Input: primes = [2, 7, 13, 19], n = 8
// indices = [0, 0, 0, 0], ugly numbers = [1]
// indices = [1, 0, 0, 0], ugly numbers = [1, 2]
// indices = [2, 0, 0, 0], ugly numbers = [1, 2, 4]
// indices = [2, 1, 0, 0], ugly numbers = [1, 2, 4, 7]
// indices = [3, 1, 0, 0], ugly numbers = [1, 2, 4, 7, 8]
// indices = [3, 1, 1, 0], ugly numbers = [1, 2, 4, 7, 8, 13]
// indices = [4, 2, 1, 0], ugly numbers = [1, 2, 4, 7, 8, 13, 14]
// indices = [5, 2, 1, 0], ugly numbers = [1, 2, 4, 7, 8, 13, 14, 16]
// indices = [5, 2, 1, 1], ugly numbers = [1, 2, 4, 7, 8, 13, 14, 16, 19]
// ...

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1)
            return 1;

        vector<int> index(primes.size(), 0);
        vector<int> ugly(n, INT_MAX);

        ugly[0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < primes.size(); j++)
                ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);

            for (int j = 0; j < primes.size(); j++)
                index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
        }

        return ugly[n - 1];
    }
};