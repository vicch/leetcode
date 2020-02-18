// Problem:
// Given an integer array, find one continuous subarray that if you only sort
// this subarray in ascending order, then the whole array will be sorted in
// ascending order. Find the shortest such subarray and output its length.
// 
// Example:
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5 (sort [6, 4, 8, 10, 9])
// 
// Solution:
// Every partly sorted array consists of 3 subarrays: left and right sorted
// subarray and a middle unsorted subarray. The unsorted subarray needs to be
// sorted at least. And if the unsorted array contains values within the ranges
// of the sorted arrays (for example [1,3,4,6,2,5,7], [1,3,4] and [5,7] are
// sorted arrays, [6,2] is unsorted array, but 2 falls in [1,3,4] and 6 falls
// in [5,7]), the subarray to sort expands to the location where those values
// should be.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s, i, l1, r1, l2, r2;
        int m, n, mi, ni;

        s = nums.size();

        // Find left bound of unsorted subarray
        for (i = 0; nums[i] <= nums[i+1] && i < s - 1; i++);
        l1 = i;

        // Find right bound of unsorted subarray
        for (i = s - 1; nums[i] >= nums[i-1] && i > 0; i--);
        r1 = i;

        // Find max and min value in unsorted subarray
        for (i = l1, m = INT_MAX, n = INT_MIN; i <= r1; i++) {
            if (nums[i] < m)
                m = nums[i], mi = i;
            if (nums[i] > n)
                n = nums[i], ni = i;
        }

        // Find position for min value inside left sorted subarray
        for (i = 0; nums[i] <= m && i < s; i++);
        l2 = i;

        // Find position for max value inside right sorted subarray
        for (i = s - 1; nums[i] >= n && i >= 0; i--);
        r2 = i;

        // Expand subarray bounds
        l1 = min(l1, l2);
        r1 = max(r1, r2);

        return l1 < r1 ? r1 - l1 + 1 : 0;
    }
};