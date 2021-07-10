#include <stdio.h>
#include <stdlib.h>

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize);
int power(int b, int p);

int main()
{
    int nums[] = {1,2,3};
    int* cols;
    int size;
    int** sets = subsets(nums, 3, &cols, &size);

    return 0;
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
    *returnSize = power(2, numsSize);
    *columnSizes = malloc(sizeof(int) * *returnSize);
    int** sets = malloc(sizeof(int*) * *returnSize);
    int i, j, k, l;

    for (i = 0; i < *returnSize; i++) {
        sets[i] = malloc(sizeof(int) * numsSize);
        for (j = i, k = 0, l = 0; j > 0; j >>= 1, k++)
            if (j & 01)
                sets[i][l++] = nums[k];
        (*columnSizes)[i] = l;
    }

    return sets;
}

int power(int b, int p)
{
    int i = 1;
    while (p-- > 0) i *= b;
    return i;
}