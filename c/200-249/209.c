// Problem:
// Given an array of n positive integers and a positive integer s, find the
// minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
// one, return 0 instead.
// 
// Example:
// Input: [2,3,1,2,4,3], s = 7
// Output: 2 ([4,3])
// 
// Solution:
// Use a "sums" array where sums[i] = nums[0] + ... + nums[i - 1], and sums[0]
// is 0. The difference of any 2 numbers in the sums array represents the sum
// of a subarray in nums array. Use to pointers i and j running from forwardly
// on sums array, i is on the right of j. When sums[i] - sums[j] < s, increment
// i, otherwise increment j until sums[i] - sums[j] < s, then the current
// shortest subarray is found. Keep the length updated as i and j increment
// until i reaches the end.

#include <stdio.h>

int minSubArrayLen(int s, int* nums, int numsSize);

int main()
{
    return 0;
}

/********** Solution **********/

int minSubArrayLen(int s, int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int sums[numsSize + 1], len, i, j;

    for (sums[0] = 0, i = 0; i < numsSize; i++)
        sums[i + 1] = sums[i] + nums[i];

    // All numbers add up still not enough
    if (sums[i] < s)
        return 0;

    // Initial length as the largest possible length
    i = 1, j = 0, len = numsSize;

    while (1) {
        while (i < numsSize + 1 && sums[i] - sums[j] < s)
            i++;
        // Check boundary
        if (i >= numsSize + 1)
            break;
        while (sums[i] - sums[j] >= s)
            j++;
        if (len > i - j + 1)
            len = i - j + 1;
    }

    return len;
}