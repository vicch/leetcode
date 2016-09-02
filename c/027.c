#include <stdio.h>

int removeElement(int* nums, int numsSize, int val);

int main()
{
    int seq[] = {3,2,2,3};
    int l = removeElement(seq, 4, 3);
    int i;

    for (i = 0; i < l; i++) {
        printf("%d,", seq[i]);
    }
    printf("\n");

    return 0;
}

int removeElement(int* nums, int numsSize, int val)
{
    int i, j;

    if (numsSize == 0)
        return 0;

    j = 0;
    for (i = 0; i < numsSize; i++) {
        while (nums[i] == val)
            i++;
        if (i < numsSize)
            nums[j++] = nums[i];
    }

    return j;
}