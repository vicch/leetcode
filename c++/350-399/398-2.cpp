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
// To solve this problem using only O(1) extra space. The problem is how to
// randomly select a index without knowing the total number of indice at start.
// - If only 1 index is found, it is the answer.
// - If 2nd index is found, there should be 1/2 chance to replace the 1st with
//   the 2nd.
// - If nth index is found, there should be 1/n chance to replace the previous
//   index with it.

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
    vector<int> nums;

public:
    Solution(vector<int> vnums) {
        nums = vnums;
    }

    int pick(int target) {
        int cnt = 0;
        int idx = -1;

        for (int i = 0 ; i < nums.size(); i++) {
            if (nums[i] != target)
                continue;

            cnt++;

            if (cnt == 1)
                idx = i;
            else
                // Use random number to get 1/n chance to replace the index
                if (rand() % cnt == 0)
                    idx = i;
        }

        return idx;
    }
};