#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize);
int cmpint(const void * a, const void * b);

int main()
{
    int seq[] = {1,2,3,1,2,1,1};
    printf("%d\n", majorityElement(seq, 7));

    return 0;
}

int majorityElement(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmpint);
    return nums[numsSize / 2];
}

int cmpint(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}