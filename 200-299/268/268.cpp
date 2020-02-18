// Problem:
// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
// find the one that is missing from the array. The algorithm should run in
// linear runtime complexity. Could you implement it using only constant extra
// space complexity.
// 
// Example:
// Input: [0, 1, 3]
// Output: 2
// 
// Solution:
// For an input vector of size n, it may contain numbers from 0 to n. For each
// number < n, use it as an index to mark the corresponding number as negative.
// Then all numbers should be negative except 2 at most: the number 0 and the
// number whose index does not exist in the vector.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s, i, j, idx0;
        bool max;
        
        s = nums.size();
        idx0 = -1;
        max = false;
        
        for (i = 0; i < s; i++) {
            j = abs(nums[i]);

            // Index s is out of bound, mark it specially
            if (j == s)
                max = true;
            // Mark the number with index j as negative
            else
                nums[j] = -nums[j];

            // Mark number 0's index
            if (j == 0)
                idx0 = i;
        }
        
        // If the max number s does not exist
        if (!max)
            return s;
        
        // Look for the number which is still positive, return its index
        for (i = 0; i < s; i++)
            if (nums[i] > 0)
                return i;

        // If positive number not exist, then number 0's index is missing
        return idx0;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {0};
    vector<int> v2 = {0, 1};
    vector<int> v3 = {1, 0};
    vector<int> v4 = {0, 2};
    vector<int> v5 = {2, 0};
    vector<int> v6 = {1, 2};
    vector<int> v7 = {2, 1};
    vector<int> v8 = {0, 1, 3};
    vector<int> v9 = {3, 0, 1};

    cout << s.missingNumber(v1) << endl;

    return 0;
}