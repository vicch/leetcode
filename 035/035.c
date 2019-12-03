#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target);

int main()
{
    int seq1[] = {1,3,4};
    printf("%d\n", searchInsert(seq1, 3, 2));

    int seq2[] = {1,2,3,4};
    printf("%d\n", searchInsert(seq2, 4, 2));

    int seq3[] = {2,3,4};
    printf("%d\n", searchInsert(seq3, 3, 1));

    int seq4[] = {1};
    printf("%d\n", searchInsert(seq4, 1, 0));

    int seq5[] = {1};
    printf("%d\n", searchInsert(seq5, 1, 2));

    return 0;
}

int searchInsert(int* nums, int numsSize, int target)
{
    if (numsSize < 1)
        return 0;

    int i = 0, j = numsSize - 1, mid;

    while (i <= j) {
        mid = (i + j) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }

    return i;
}