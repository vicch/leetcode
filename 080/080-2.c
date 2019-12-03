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
    int i = 0, j;
    for (j = 0; j < numsSize; j++)
        if (i < 2 || nums[j] > nums[i-2])
            nums[i++] = nums[j];
    return i;
}