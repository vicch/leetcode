#include <stdio.h>

int singleNumber(int* nums, int numsSize);

int main()
{
    int seq[] = {1,2,4,2,1};
    printf("%d\n", singleNumber(seq, 5));

    return 0;
}

int singleNumber(int* nums, int numsSize)
{
    int i;

    for (i = 1; i < numsSize; i++) {
        nums[0] ^= nums[i];
    }

    return nums[0];
}