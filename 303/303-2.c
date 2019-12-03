#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Stores a list of sums for every 100 elements
 * sums[i] = sum of elements 100i to 100i + 99
 */
struct NumArray {
    int count;
    int* nums;
    long* sums;
};

void printArray(int* seq, int count);
struct NumArray* NumArrayCreate(int* nums, int numsSize);
long sumIndexRange(int* nums, int f, int t);
long sumRange(struct NumArray* numArray, int i, int j);
void NumArrayFree(struct NumArray* numArray);

int main()
{
    int seq1[] = {-2,0,3,-5,2,-1};
    struct NumArray* a = NumArrayCreate(seq1, 6);
    printArray(a->nums, a->count);
    printf("%ld,%d:%d\n", 0, 2, sumRange(a, 0, 2));
    printf("%ld,%d:%d\n", 2, 5, sumRange(a, 2, 5));
    printf("%ld,%d:%d\n", 0, 5, sumRange(a, 0, 5));
    NumArrayFree(a);

    int seq2[] = {1,4,-6};
    struct NumArray* b = NumArrayCreate(seq2, 3);
    printArray(b->nums, b->count);
    printf("%ld,%d:%d\n", 0, 2, sumRange(b, 0, 2));
    printf("%ld,%d:%d\n", 1, 2, sumRange(b, 1, 2));
    printf("%ld,%d:%d\n", 0, 1, sumRange(b, 0, 1));
    NumArrayFree(b);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d", *seq++);
    }
    printf("\n");
}

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize)
{
    struct NumArray* a = malloc(sizeof(struct NumArray));
    a->count = numsSize;
    a->nums = malloc(sizeof(int) * numsSize);
    a->sums = malloc(sizeof(long) * (numsSize + 99) / 100.0);

    memcpy(a->nums, nums, sizeof(int) * numsSize);

    int i;
    for (i = 0; i * 100 < numsSize; i++) {
        a->sums[i] = sumIndexRange(nums, i * 100, (i * 100 + 99 < numsSize) ? i * 100 + 99 : numsSize - 1);
    }

    return a;
}

long sumIndexRange(int* nums, int f, int t)
{
    // printf("%d to %d = ", f, t);
    long i = 0;
    for (; f <= t; f++) {
        i += nums[f];
    }
    // printf("%ld\n", i);
    return i;
}

long sumRange(struct NumArray* numArray, int i, int j)
{
    int a = i / 100;
    int b = j / 100;
    int k;
    long sum = 0;

    // Adding sums of ranges
    // e.g. for 50~150, add sums of 0~99 and 100~199
    for (k = a; k <= b; k++) {
        sum += numArray->sums[k];
    }

    // Minus sums of extra ranges
    // e.g. for 50~150, minus sums of 0~49 and 151~199
    if (i > a * 100)
        sum -= sumIndexRange(numArray->nums, a * 100, i - 1);

    // Last index of the range
    int l = (b * 100 + 99 < numArray->count) ? b * 100 + 99 : numArray->count - 1;
    if (j < l)
        sum -= sumIndexRange(numArray->nums, j + 1, l);

    return sum;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray)
{
    free(numArray->nums);
    free(numArray->sums);
    free(numArray);
}