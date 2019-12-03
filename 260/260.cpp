// Problem:
// Given an array of numbers nums, in which exactly two elements appear only
// once and all the other elements appear exactly twice. Find the two elements
// that appear only once.
// 
// Example:
// Input: [1, 2, 1, 3, 2, 5]
// Output: [3, 5]
// 
// Solution:
// 1. XOR all numbers to get one number. Each bit in this number represents one
//    different bit in the two distinct numbers.
// 2. Take one bit in this number, for example, the rightmost one bit, and
//    divide all numbers into two groups, one group with this bit as 0, the
//    other with this bit as 1. The two distinct numbers must be separated into
//    two groups, with other numbers come in pairs.
// 3. XOR all numbers in each group to get the two distinct numbers.

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff;
        vector<int> singles;

        diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

        // Get rightmost bit
        diff &= -diff;

        singles = {0, 0};

        for (int num : nums)
            // Group 1: bit is 1
            if (num & diff)
                singles[0] ^= num;
            // Group 2: bit is 0
            else
                singles[1] ^= num;

        return singles;
    }
};