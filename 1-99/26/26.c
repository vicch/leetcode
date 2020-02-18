#include <stdio.h>

int removeDuplicates(int* nums, int numsSize);

int main()
{
    int seq[] = {1,1};
    int l = removeDuplicates(seq, 2);
    int i;

    for (i = 0; i < l; i++) {
        printf("%d,", seq[i]);
    }
    printf("\n");

    return 0;
}

int removeDuplicates(int* nums, int numsSize)
{
    int i, j;

    if (numsSize < 2)
        return numsSize;

    j = 0;
    for (i = 1; i < numsSize; i++) {
        while (nums[i] == nums[j])
            i++;
        if (i < numsSize)
            nums[++j] = nums[i];
    }

    return j + 1;
}