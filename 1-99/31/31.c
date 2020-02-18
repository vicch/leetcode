#include <stdio.h>

void printArray(int* seq, int count);
void nextPermutation(int* nums, int numsSize);
void revArray(int* nums, int numsSize);
void swap(int* nums, int i, int j);

int main()
{
    int seq1[] = {1,3,1,2};
    nextPermutation(seq1, 4);
    printArray(seq1, 4);

    int seq2[] = {1,2,3};
    nextPermutation(seq2, 3);
    printArray(seq2, 3);

    int seq3[] = {3,2,1};
    nextPermutation(seq3, 3);
    printArray(seq3, 3);

    int seq4[] = {1,1,5};
    nextPermutation(seq4, 3);
    printArray(seq4, 3);

    int seq5[] = {1};
    nextPermutation(seq5, 1);
    printArray(seq5, 1);

    int seq6[] = {1,1,1};
    nextPermutation(seq6, 3);
    printArray(seq6, 3);

    int seq7[] = {1,3,5,4,2};
    nextPermutation(seq7, 5);
    printArray(seq7, 5);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d\n", *seq++);
    }
}

/**
 * e.g. 1,3,5,4,2
 * 1. Starting from index -2, find the first digit less than its successor, in this case, 3
 * 2. Starting from index -1, find the first digit greater than it, in this case, 4
 * 3. Replace these 2 digits, in this case, 1,4,5,3,2
 * 4. Reverse the part following the digit being replaced, in this case, 1,4,2,3,5
 */
void nextPermutation(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return;

    int i, j, tmp;

    // Find the digit to replace
    for (i = numsSize-2; i >= 0 && nums[i] >= nums[i+1]; i--);

    if (i < 0) {
        revArray(nums, numsSize);
        return;
    }

    // Find the digit to replace with
    for (j = numsSize-1; j > i && nums[i] >= nums[j]; j--);

    swap(nums, i, j);

    // Order ascendingly
    revArray(nums+i+1, numsSize-i-1);

    return;
}

void revArray(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return;

    int i;
    for (i = 0; i < numsSize / 2; i++)
        swap(nums, i, numsSize-1-i);
    return;
}

void swap(int* nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
    return;
}