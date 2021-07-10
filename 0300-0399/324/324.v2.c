// Problem:
// Given an array, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]...
// 
// Example:
// Input: [1, 3, 2, 2, 3, 1]
// Output: [2, 3, 1, 3, 1, 2]
// 
// Solution:
// Find the median, and rearrange the array:
// - If larger than median, put in first odd positions
// - If less than median, put in last even positions
// - Put in rest positions

#include <stdio.h>

void wiggleSort(int* nums, int numsSize);
void printArray(int* seq, int count);

int main()
{
    int n1[] = {1, 3, 2, 2, 3, 1};
    wiggleSort((int*)n1, 6);
    printArray(n1, 6);

    int n2[] = {1, 5, 1, 1, 6, 4};
    wiggleSort((int*)n2, 6);
    printArray(n2, 6);

    int n3[] = {4, 5, 5, 6};
    wiggleSort((int*)n3, 4);
    printArray(n3, 4);

    int n4[] = {4, 5, 5, 5, 5, 6, 6, 6};
    wiggleSort((int*)n4, 8);
    printArray(n4, 8);

    int n5[] = {2, 3, 3, 2, 2, 2, 1, 1};
    wiggleSort((int*)n5, 8);
    printArray(n5, 8);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d", *seq++);
    printf("\n");
}

/********** Solution **********/

#define SWAP(a, b) (tmp = (a), (a) = (b), (b) = tmp)
// Translate normal indices to wiggles indices
// Before: 0 1 2 3 4  5 6 7 8 9 10 11
// After:  1 3 5 7 9 11 0 2 4 6  8 10
#define WIGGLE(i) ((2 * (i) + 1) % (numsSize | 1))

void wiggleSort(int* nums, int numsSize)
{
    if (numsSize < 2)
        return;

    int median = findMedian(nums, numsSize);
    printf("median=%d\n", median);
    
    int first, middle, last, tmp;

    for (first = middle = 0, last = numsSize - 1; middle <= last;) {
        if (nums[WIGGLE(middle)] > median) {
            SWAP(nums[WIGGLE(middle)], nums[WIGGLE(first)]);
            first++, middle++;
        } else if (nums[WIGGLE(middle)] < median) {
            SWAP(nums[WIGGLE(middle)], nums[WIGGLE(last)]);
            last--;
        } else
            middle++;
    }

    return;
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