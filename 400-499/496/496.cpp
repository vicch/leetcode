// Problem:
// Given two arrays (without duplicates) nums1 and nums2, where nums1's
// elements are subset of nums2. Find all the next greater numbers for nums1's
// elements in the corresponding places of nums2. The Next Greater Number of a
// number x in nums1 is the first greater number to its right in nums2. If it
// does not exist, output -1 for this number.
// 
// Example:
// Intput: nums1 = [2, 4], nums2 = [1, 2, 3, 4]
// Output: [3, -1]
// 
// Solution:
// As all numbers are unique, a hash map can be used to store "next greater
// number" for each number in nums2, then read for the map for each number in
// nums1. Get "next greater number" by iterating backwards and use a stack.

#include <iostream>
#include <vector>
#include <stack>
#include <map>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        int i;
        vector<int> ret(findNums.size());
        stack<int> nstack;
        map<int, int> nmap;

        // Iterating backwards
        for (i = nums.size() - 1; i >= 0; i--) {
            // Find the next greater number for current number
            while (!nstack.empty() && nstack.top() < nums[i])
                nstack.pop();
            nmap[nums[i]] = (nstack.empty() ? -1 : nstack.top());
            // Push current number as new greater number
            nstack.push(nums[i]);
        }

        // Get next greater numbers by reading the hash map for each number
        for (i = 0; i < findNums.size(); i++)
            ret[i] = nmap[findNums[i]];

        return ret;
    }
};