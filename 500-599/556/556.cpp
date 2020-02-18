// Problem:
// Given a positive 32-bit integer n, find the smallest 32-bit integer which
// has exactly the same digits existing in the integer n and is greater in
// value than n. If no such positive 32-bit integer exists, return -1.
// 
// Example:
// Input: 12
// Output: 21
// 
// Solution:
// If the digits of the number is in descending order, there is no solution. If
// a digit can be found which is less than its right next digit, there is a
// solution. After finding this digit, swap it with the smallest digit that is
// larger than it on its right. Then sort all digits on its right in ascending
// order.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 12)
            return -1;

        string s = to_string(n);
        int i;

        // Find the rightmost digit less than its right next digit
        for (
            i = s.length() - 2;
            i >= 0 && s[i] >= s[i + 1];
            i--
        );

        // No solution
        if (i < 0 || (i == 0 && s[0] == s[1]))
            return -1;

        reverse(s.begin() + i + 1, s.end());

        for (int j = i + 1; j < s.length(); j++)
            if (s[j] > s[i]) {
                swap(s[i], s[j]);
                break;
            }

        long m = stol(s);

        return m > 2147483647 ? -1 : m;
    }
};