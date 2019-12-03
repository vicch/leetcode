// Problem:
// Given an array of integers where 1 =< a[i] =< n (n = size of array), some
// elements appear twice and others appear once. Find all the elements of
// [1, n] inclusive that do not appear in this array. Do it without extra space
// and in O(n) runtime.
// 
// Example:
// Input: [4,3,2,7,8,2,3,1]
// Output: [5,6]
// 
// Solution:
// First iterate the integers, mark each one that appears in another array.
// Then iterate the array to collect integers that are not marked.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int a[nums.size() + 1] = {0};
        vector<int> r;
        
        for (int n: nums)
            a[n] = 1;
        
        for (int i = 1; i <= nums.size(); i++)
            if (!a[i])
                r.push_back(i);
                
        return r;
    }
};