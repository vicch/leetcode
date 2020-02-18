#include <stdio.h>

void printArray(int* seq, int count);
int removeDuplicates(int* nums, int numsSize);

int main()
{
    int seq1[] = {1,1,1,2,2,3};
    printArray(seq1, removeDuplicates(seq1, 6));

    int seq2[] = {0,0,1,1,1,1,2,2,2,4};
    printArray(seq2, removeDuplicates(seq2, 10));

    int seq3[] = {0,1,2,2,2,2,2,3,4,4,4};
    printArray(seq3, removeDuplicates(seq3, 11));

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d\n", *seq++);
    return;
}

int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize < 3) return numsSize;

    int i = 0, j = 0, k;
    while (j < numsSize) {
        for (k = 0; j < numsSize && k < 2; i++, j++, k = (nums[j] == nums[j-1]) ? k + 1 : 0)
            nums[i] = nums[j];
        for (; j < numsSize && nums[j] == nums[j-1]; j++);
    }
    return i;
}