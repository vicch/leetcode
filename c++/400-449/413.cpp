// Problem:
// A sequence of number is called arithmetic if it consists of at least three
// elements and if the difference between any two consecutive elements is the
// same. For example: 1, 3, 5, 7, 9 or 7, 7, 7, 7. Given an array of N integers,
// a slice of that array is any pair of integers (P,Q) such that 0 <= P < Q < N.
// Return the number of arithmetic slices in the array.
// 
// Example:
// Input: [1, 2, 3, 4]
// Output: 3 ([1, 2, 3], [2, 3, 4], [1, 2, 3, 4])
// 
// Solution:
// Consider the diff between each 2 consecutive integers in the array, if there
// are N consecutive diffs that are equal, there is (N-1) + (N-2) + ... + 1 =
// N * (N-1) / 2 different arithmetic slices. Iterating the array, keep track
// of the 2 last diffs. If they 2 diffs are equal, increment a counter. When a
// different diff appears, increment the total number of arithmetic slices by
// N * (N-1) / 2, with N be the value of the counter, and reset the counter to
// 1. Continue till the end of the array.

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int s = v.size() - 1;
        
        if (s < 2)
            return 0;
        
        // Last 2 diffs
        int prev = v[1] - v[0];
        int curr;

        int count = 1;
        int total = 0;
        
        for (int i = 1; i < s; i++) {
            curr = v[i + 1] - v[i];
            if (prev == curr) {
                count++;
            } else {
                total += count * (count - 1) / 2;
                count = 1;
            }
            prev = curr;
        }
        
        total += count * (count - 1) / 2;
            
        return total;
    }
};