#include <stdio.h>

void printArray(int* seq, int count);
void moveZeroes(int* nums, int numsSize);

int main()
{
    int seq[] = {0,1,0,2,0,3,0};
    moveZeroes(seq, 7);

    printArray(seq, 7);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d\n", *seq++);
    }
}

void moveZeroes(int* nums, int numsSize)
{
    if (numsSize < 2)
        return;

    int i = 0, j = 0;

    while (j < numsSize) {
        if (nums[j] != 0)
            nums[i++] = nums[j];
        j++;
    }

    while (i < numsSize) {
        nums[i++] = 0;
    }
}