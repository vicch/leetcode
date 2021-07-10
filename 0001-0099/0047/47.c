#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArrays(int** arrays, int cols, int size);
void printArray(int* seq, int count);

int** permuteUnique(int* nums, int numsSize, int* returnSize);
int** permute(int* nums, int numsSize, int* returnSize);
int cmpInt(const void * a, const void * b);
int factorial(int n);
int* removeIndex(int* nums, int n, int i);

int main()
{
    int seq1[] = {1,2,3};
    int size1;
    int** per1 = permuteUnique(seq1, 3, &size1);
    printArrays(per1, 3, size1);

    int seq2[] = {1,1};
    int size2;
    int** per2 = permuteUnique(seq2, 2, &size2);
    printArrays(per2, 2, size2);

    int seq3[] = {4,3,2,1,0,4};
    int size3;
    int** per3 = permuteUnique(seq3, 6, &size3);
    printArrays(per3, 6, size3);

    return 0;
}

void printArrays(int** arrays, int cols, int size)
{
    for (; size > 0; size--, arrays++) {
        printArray(*arrays, cols);
    }
    return;
}

void printArray(int* seq, int count)
{
    printf("[");
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d]\n", *seq++);
    }
    return;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize)
{
    qsort(nums, numsSize, sizeof(int), cmpInt);
    return permute(nums, numsSize, returnSize);
}

int** permute(int* nums, int numsSize, int* returnSize)
{
    int** res;

    if (numsSize == 1) {
        *returnSize = 1;
        res = malloc(sizeof(int*));
        res[0] = malloc(sizeof(int));
        res[0][0] = nums[0];

    } else {
        *returnSize = 0;
        res = malloc(sizeof(int*) * factorial(numsSize));

        int i, j;
        for (i = 0; i < numsSize; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int* sub = removeIndex(nums, numsSize, i);
            int subSize;
            int** subPermute = permute(sub, numsSize - 1, &subSize);

            for (j = 0; j < subSize; j++, (*returnSize)++) {
                res[*returnSize] = malloc(sizeof(int) * numsSize);
                res[*returnSize][0] = nums[i];
                memcpy(res[*returnSize] + 1, subPermute[j], sizeof(int) * (numsSize - 1));
                free(subPermute[j]);
            }

            free(sub);
            free(subPermute);
        }
    }

    return res;
}

int cmpInt(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int factorial(int n)
{
    int i = 1;
    while (n > 1) i *= n--;
    return i;
}

int* removeIndex(int* nums, int n, int i)
{
    int* res = malloc(sizeof(int) * (n - 1));
    memcpy(res, nums, sizeof(int) * i);
    memcpy(res + i, nums + i + 1, sizeof(int) * (n - i - 1));
    return res;
}