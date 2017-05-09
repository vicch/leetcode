// Problem:
// Given an unsorted array of integers, find the length of longest increasing
// subsequence. There may be more than one LIS combination, it is only
// necessary to return the length.
// 
// Example:
// Input: [10, 9, 2, 5, 3, 7, 101, 18]
// Output: 4 ([2, 3, 7, 101] or [2, 5, 7, 101])

#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <climits>

class Solution {
    unordered_map<int, int>* cache;

public:
    int lengthOfLIS(vector<int>& nums) {
        cache = new unordered_map<int, int>[nums.size()];
        return lengthSub(nums, 0, INT_MIN);
    }

    int lengthSub(vector<int>& nums, int i, int min) {
        if (i == nums.size())
            return 0;

        if (cache[i][min])
            return cache[i][min];

        if (nums[i] > min)
            cache[i][min] = max(lengthSub(nums, i + 1, nums[i]) + 1, lengthSub(nums, i + 1, min));
        else
            cache[i][min] = lengthSub(nums, i + 1, min);  

        return cache[i][min];
    }
};