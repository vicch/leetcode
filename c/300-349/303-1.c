#include <stdio.h>
#include <stdlib.h>

/**
 * 2-dimensional array of sums
 * sums[i][j] = sum of elements i to i+j
 */
struct NumArray {
    int** sums;
    int count;
};

struct NumArray* NumArrayCreate(int* nums, int numsSize);
int sumRange(struct NumArray* numArray, int i, int j);
void NumArrayFree(struct NumArray* numArray);

int main()
{
    int seq1[] = {-2,0,3,-5,2,-1};
    struct NumArray* a = NumArrayCreate(seq1, 6);
    printf("%d,%d:%d\n", 0, 2, sumRange(a, 0, 2));
    printf("%d,%d:%d\n", 2, 5, sumRange(a, 2, 5));
    printf("%d,%d:%d\n", 0, 5, sumRange(a, 0, 5));
    NumArrayFree(a);

    int seq2[] = {1,4,-6};
    struct NumArray* b = NumArrayCreate(seq2, 3);
    printf("%d,%d:%d\n", 0, 2, sumRange(b, 0, 2));
    printf("%d,%d:%d\n", 1, 2, sumRange(b, 1, 2));
    printf("%d,%d:%d\n", 0, 1, sumRange(b, 0, 1));
    NumArrayFree(b);

    return 0;
}

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize)
{
    struct NumArray* a = malloc(sizeof(struct NumArray));
    a->sums = malloc(sizeof(int*) * numsSize);
    a->count = numsSize;

    int i, j;
    for (i = 0; i < numsSize; i++) {
        a->sums[i] = malloc(sizeof(int) * (numsSize - i));
        a->sums[i][0] = nums[i];
        for (j = i - 1; j >= 0; j--) {
            a->sums[j][i - j] = a->sums[j][i - j - 1] + nums[i];
        }
    }

    return a;
}

int sumRange(struct NumArray* numArray, int i, int j)
{
    return numArray->sums[i][j - i];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray)
{
    int i;
    for (i = 0; i < numArray->count; i++) {
        free(numArray->sums[i]);
    }
    free(numArray->sums);
    free(numArray);
}