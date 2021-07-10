#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArrays(int** arrays, int* cols, int size);
void printArray(int* array, int num);

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize);
int* makeMap(int* nums, int numsSize);
int** subsetsRecursive(int* nums, int* map, int numsSize, int** columnSizes, int* returnSize);
int* repeat(int i, int n);
int* concat(int* a, int as, int* b, int bs);
int cmpInt(const void * a, const void * b);

int main()
{
    int i;

    int seq1[] = {1,2,3};
    int* cols1;
    int size1;
    int** sub1 = subsetsWithDup(seq1, 3, &cols1, &size1);
    printArrays(sub1, cols1, size1);

    free(cols1);
    for (i = 0; i < size1; i++) free(sub1[i]);
    free(sub1);

    int seq2[] = {3,1,2,3};
    int* cols2;
    int size2;
    int** sub2 = subsetsWithDup(seq2, 4, &cols2, &size2);
    printArrays(sub2, cols2, size2);

    free(cols2);
    for (i = 0; i < size2; i++) free(sub2[i]);
    free(sub2);
    
    return 0;
}

void printArrays(int** arrays, int* cols, int size)
{
    for (; size > 0; size--, arrays++, cols++)
        printArray(*arrays, *cols);
}

void printArray(int* array, int num)
{
    printf("[");
    while (num-- > 0)
        printf((num > 0) ? "%d," : "%d", *array++);
    printf("]\n");
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int* map = makeMap(nums, numsSize);
    int** subsets = subsetsRecursive(nums, map, numsSize, columnSizes, returnSize);
    free(map);
    return subsets;
}

/**
 * Make a map of indexes and occurences of unique numbers
 * e.g. {1,1,2,2,3,4} -> {2,0,2,0,1,1}
 */
int* makeMap(int* nums, int numsSize)
{
    int i, j;
    int* map = malloc(sizeof(int) * numsSize);

    for (i = 0, j = 0; i < numsSize; i++) {
        map[i] = 0;
        if (nums[i] != nums[j]) j = i;
        map[j]++;
    }

    return map;
}

int** subsetsRecursive(int* nums, int* map, int numsSize, int** columnSizes, int* returnSize)
{
    if (numsSize == 0) return NULL;

    // Get subsets recursively
    int* subCols = NULL;
    int subSize = 0;
    int** subSets = subsetsRecursive(nums+1, map+1, numsSize-1, &subCols, &subSize);

    *returnSize = (subSize == 0 ? 1 : subSize) * (map[0]+1);
    *columnSizes = malloc(sizeof(int) * *returnSize);
    int** sets = malloc(sizeof(int*) * *returnSize);

    // Join current number with subsets
    int i, j;
    int* base;
    for (i = 0; i <= map[0]; i++) {
        base = repeat(nums[0], i);
        // Without subsets
        if (!subSize) {
            (*columnSizes)[i] = i;
            sets[i] = concat(base, i, NULL, 0);
        // With subsets
        } else {
            for (j = 0; j < subSize; j++) {
                (*columnSizes)[i*subSize+j] = i + subCols[j];
                sets[i*subSize+j] = concat(base, i, subSets[j], subCols[j]);
            }
        }
        free(base);
    }

    free(subCols);
    for (i = 0; i < subSize; i++) free(subSets[i]);
    free(subSets);

    return sets;
}

/**
 * Repeat a number and return the array
 */
int* repeat(int i, int n)
{
    if (n == 0) return NULL;
    int* seq = malloc(sizeof(int) * n);
    while (--n >= 0) seq[n] = i;
    return seq;
}

/**
 * Concat two arrays
 */
int* concat(int* a, int as, int* b, int bs)
{
    if (as == 0 && bs == 0) return NULL;
    int* seq = malloc(sizeof(int) * (as+bs));
    int i;
    for (i = 0; i < as; i++) seq[i] = a[i];
    for (i = 0; i < bs; i++) seq[as+i] = b[i];
    return seq;
}

int cmpInt(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}