// Problem:
// Given an array of integers with possible duplicates, randomly output the
// index of a given target number. Each index should have equal probability of
// returning. Assume that the given target number must exist in the array.
// 
// Example:
// int[] nums = new int[] {1,2,3,3,3};
// Solution solution = new Solution(nums);
// solution.pick(3); // Return index 2, 3, or 4 randomly
// 
// Solution:
// Store number indice in a map. When picking, return a random index of the
// target number's indice.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution {
    unordered_map<int, vector<int>> idx;

public:
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++)
            idx[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        return idx[target][rand() % idx[target].size()];
    }
};