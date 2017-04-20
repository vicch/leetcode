// Problem:
// Given a binary array, find the maximum length of a contiguous subarray with
// equal number of 0 and 1.
// 
// Example:
// Input: [0,1,0]
// Output: 2
// 
// Solution:
// Consider a "diff" value for each element of the array which indicates the
// difference between the number of 0's and 1's from the beginning of the
// array to this element (with diff > 0 meaning more 0's than 1's for example).
// If subarray array[m] to array[n] contains equal numbers of 0's and 1's, then
// diff[n] == diff[m - 1]. Therefore by using an array to store the index where
// each "diff" value appears, when the same value appears again, a wanted
// subarray is found. By keeping the length of the longest subarray found so
// far, then in the end it's the wanted value.

#include <stdio.h>

int findMaxLength(int* nums, int numsSize);

int main()
{
    return 0;
}

/********** Solution **********/

int findMaxLength(int* nums, int numsSize)
{
    if (numsSize < 2)
        return 0;

    int diff, longest, i, j;

    // -numsSize <= diff <= numsSize
    int* diffs = malloc(sizeof(int) * (numsSize * 2 + 1));
    memset(diffs, -1, sizeof(int) * (numsSize * 2 + 1));
    // Move pointer to middle for simpler code
    diffs += numsSize;

    for (i = diff = longest = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            diff++;
        else
            diff--;

        // Ignore diff 0, as the index of first diff 0 is actually -1
        if (diff == 0)
            longest = i + 1;
        else {
            // Set first index for this diff
            if (diffs[diff] == -1)
                diffs[diff] = i;
            // If length of current subarray is longer
            else if (i - diffs[diff] > longest)
                longest = i - diffs[diff];
        }
    }

    free(diffs - numsSize);

    return longest;
}