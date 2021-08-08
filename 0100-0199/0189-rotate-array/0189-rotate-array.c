#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* seq, int count);
void rotate(int* nums, int numsSize, int k);

int main()
{
    int seq[] = {1,2,3,4,5,6};
    rotate(seq, 6, 11);
    printArray(seq, 6);

    return 0;

}

void printArray(int* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d\n", *seq++);
    }
}

void rotate(int* nums, int numsSize, int k)
{
    while (k < 0)
        k += numsSize;

    while (k >= numsSize)
        k -= numsSize;

    if (k == 0)
        return;

    int* copy = malloc(sizeof(int) * numsSize);
    int i;

    memcpy(copy, nums, sizeof(int) * numsSize);

    for (i = numsSize - k; i < numsSize; i++) {
        nums[k - numsSize + i] = copy[i];
    }

    for (i = 0; i < numsSize - k; i++) {
        nums[k + i] = copy[i];
    }

    return;
}