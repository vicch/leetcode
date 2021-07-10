// Problem:
// Given an array, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]...
// 
// Example:
// Input: [1, 3, 2, 2, 3, 1]
// Output: [2, 3, 1, 3, 1, 2]
// 
// Solution (NOT WORKING):
// While iterating the array, keep 2 indexes:
// - Index of the smallest value in odd indices
// - Index of the largest value in even indices
// When the second index's value is larger than the first, exchange 2 values.
// Also keep moving the smaller values to the end of the array.

#include <stdio.h>

void printArray(int* seq, int count);
void wiggleSort(int* nums, int numsSize);

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

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d", *seq++);
    printf("\n");
}

#define SWAP(a, b) (tmp = (a), (a) = (b), (b) = tmp)

void wiggleSort(int* nums, int numsSize)
{
    if (numsSize < 2)
        return;

    int i, evenmax, oddmin, tmp;

    if (nums[0] > nums[1])
        SWAP(nums[0], nums[1]);

    for (evenmax = 0, oddmin = 1, i = 2; i < numsSize; i++) {
        if (i % 2 == 0 && nums[i] > nums[evenmax])
            evenmax = i;
        else if (i % 2 == 1 && nums[i] < nums[oddmin])
            oddmin = i;
        if (nums[evenmax] > nums[oddmin])
            SWAP(nums[evenmax], nums[oddmin]);

        if (nums[i] > nums[i - 2]) {
            if (oddmin == i - 2)
                oddmin = i;
            if (evenmax == i)
                evenmax = i - 2;
            SWAP(nums[i], nums[i - 2]);
        }
    }

    return;
}