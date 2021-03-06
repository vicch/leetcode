// Problem:
// Given a non-empty integer array, find the minimum number of moves required
// to make all array elements equal, where a move is incrementing a selected
// element by 1 or decrementing a selected element by 1.
// 
// Example:
// Input: [1,2,3]
// Output: 2
// 
// Solution:
// The key is to find the median (see #324). Calculate the sum of each number's
// difference with the median.

#include <stdio.h>

int minMoves2(int* nums, int numsSize);

int main()
{
    return 0;
}

/********** Solution **********/

#define SWAP(a, b) (tmp = (a), (a) = (b), (b) = tmp)

int findMedian(int* nums, int size);

int minMoves2(int* nums, int numsSize)
{
    int median, total, i;

    median = floor(findMedian(nums, numsSize));

    for (total = i = 0; i < numsSize; i++)
        total += (nums[i] < median) ? median - nums[i] : nums[i] - median;

    return total;
}

int findMedian(int* nums, int size)
{
    int low, high, median, middle, ll, hh, tmp;

    low = 0, high = size - 1, median = (low + high) / 2;

    for (;;) {
        // 1 element
        if (high <= low)
            return nums[median];

        // 2 elements
        if (high == low + 1) {
            if (nums[low] > nums[high])
                SWAP(nums[low], nums[high]);
            return nums[median];
        }

        // Find median of low, middle and high items. Swap into position low.
        middle = (low + high) / 2;
        if (nums[middle] > nums[high]) SWAP(nums[middle], nums[high]);
        if (nums[low]    > nums[high]) SWAP(nums[low],    nums[high]);
        if (nums[middle] > nums[low])  SWAP(nums[middle], nums[low]);

        // Swap low item (now in position middle) into position low+1
        SWAP(nums[middle], nums[low + 1]);

        // Nibble from each end towards middle, swapping items when stuck
        for (ll = low + 1, hh = high; ;) {
            do ll++; while (nums[low] > nums[ll]);
            do hh--; while (nums[hh]  > nums[low]);

            if (hh < ll)
                break;

            SWAP(nums[ll], nums[hh]);
        }

        // Swap middle item (in position low) back into correct position
        SWAP(nums[low], nums[hh]);

        // Re-set active partition
        if (hh <= median)
            low = ll;
        if (hh >= median)
            high = hh - 1;
    }
}