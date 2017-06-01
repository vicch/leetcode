// Problem:
// Given a list of non negative integers, arrange them such that they form the
// largest number. The result may be very large, so you need to return a string
// instead of an integer.
// 
// Example:
// Input: [3, 30, 34, 5, 9]
// Output: 9534330
// 
// Solution:
// The key is to implement a sorting function to sort the numbers properly.
// Convert all numbers to string first, and compare string pairs by
// concatenating them as a+b and b+a, check which one is bigger and swap if
// necessary.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        string r;

        // Convert numbers to strings
        for (int i: nums)
            strs.push_back(to_string(i));

        sort(strs.begin(), strs.end(), Solution::sortString);

        // All numbers are 0
        if (strs[0] == "0")
            return "0";

        // Concatenate sorted strings
        for (string s: strs)
            r += s;

        return r;
    }

    static bool sortString(string a, string b) {
        string c = a + b;
        string d = b + a;
        return c > d;
    }
};