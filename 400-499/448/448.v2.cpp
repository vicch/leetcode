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
// On first iteration, for each a[i], negate the number with index a[i]. On
// second iteration, collect all indexes where the number is still positive (
// because its index did not appear). 


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i, j, s;
        vector<int> r;

        s = nums.size();

        for (i = 0; i < s; i++) {
            j = abs(nums[i]) - 1;
            if (nums[j] > 0)
                nums[j] = -nums[j];
        }

        for (i = 0; i < s; i++)
            if (nums[i] > 0)
                r.push_back(i + 1);

        return r;
    }
};