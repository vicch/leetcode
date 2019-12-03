#include <stdio.h>
#include <stdlib.h>

/**
 * Array of sums
 * sums[i] = sum of elements 0 to i
 */
struct NumArray {
    int* sums;
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
    int i;

    a->sums = malloc(sizeof(int) * numsSize);
    a->sums[0] = nums[0];
    
    for (i = 1; i < numsSize; i++)
        a->sums[i] = a->sums[i - 1] + nums[i];

    return a;
}

int sumRange(struct NumArray* numArray, int i, int j)
{
    if (i == 0) return numArray->sums[j];
    else        return numArray->sums[j] - numArray->sums[i - 1];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray)
{
    free(numArray->sums);
    free(numArray);
}