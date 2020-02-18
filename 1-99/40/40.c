#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArrays(int** arrays, int* cols, int size);
void printArray(int* seq, int count);

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize);
int** combination(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize);
int* joinArray(int* a, int sa, int* b, int sb);
int* repeatInt(int v, int t);
int cmpInt(const void * a, const void * b);

int main()
{
    // int seq1[] = {2,3,6,7};
    // int* cols1;
    // int size1;
    // int** comb1 = combinationSum2(seq1, 4, 7, &cols1, &size1);
    // printf("%d\n", size1);
    // printArrays(comb1, cols1, size1);

    // int seq2[] = {7,3,2};
    // int* cols2;
    // int size2;
    // int** comb2 = combinationSum2(seq2, 3, 18, &cols2, &size2);
    // printf("%d\n", size2);
    // printArrays(comb2, cols2, size2);

    // int seq3[] = {8,10,6,3,4,12,11,5,9};
    // int* cols3;
    // int size3;
    // int** comb3 = combinationSum2(seq3, 9, 28, &cols3, &size3);
    // printf("%d\n", size3);
    // printArrays(comb3, cols3, size3);

    int seq4[] = {10,1,2,7,6,1,5};
    int* cols4;
    int size4;
    int** comb4 = combinationSum2(seq4, 7, 8, &cols4, &size4);
    printf("%d\n", size4);
    printArrays(comb4, cols4, size4);

    return 0;
}

void printArrays(int** arrays, int* cols, int size)
{
    for (; size > 0; size--, arrays++, cols++) {
        printArray(*arrays, *cols);
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

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
    qsort(candidates, candidatesSize, sizeof(int), cmpInt);
    return combination(candidates, candidatesSize, target, columnSizes, returnSize);
}

int** combination(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
    *columnSizes = NULL;
    *returnSize = 0;

    if (candidatesSize == 0 || target < candidates[0]) return 0;

    int maxComb = 1000;
    int** comb = malloc(sizeof(int*) * maxComb);
    *columnSizes = malloc(sizeof(int) * maxComb);

    int i;
    for (i = candidatesSize - 1; i >= 0; i--) {
        if (candidates[i] > target || (i < candidatesSize - 1 && candidates[i] == candidates[i+1])) {
            continue;
        } else if (candidates[i] == target) {
            comb[*returnSize] = repeatInt(candidates[i], 1);
            (*columnSizes)[*returnSize] = 1;
            (*returnSize)++;
        } else if (i > 0) {
            int subReturnSize;
            int* subColumnSizes;
            int** subCombination = combination(candidates, i, target - candidates[i], &subColumnSizes, &subReturnSize);

            if (subReturnSize > 0) {
                int* base = repeatInt(candidates[i], 1);
                int k;
                for (k = 0; k < subReturnSize; k++) {
                    comb[*returnSize] = joinArray(base, 1, subCombination[k], subColumnSizes[k]);
                    (*columnSizes)[*returnSize] = 1 + subColumnSizes[k];
                    (*returnSize)++;
                    free(subCombination[k]);
                }
                free(base);
                free(subColumnSizes);
                free(subCombination);
            }
        }
    }

    return comb;
}

int* joinArray(int* a, int sa, int* b, int sb)
{
    int* r = malloc(sizeof(int) * (sa + sb));
    memcpy(r, a, sizeof(int) * sa);
    memcpy(r + sa, b, sizeof(int) * sb);
    return r;
}

int* repeatInt(int v, int t)
{
    int* array = malloc(sizeof(int) * t);
    for (t--; t >= 0; t--) {
        array[t] = v;
    }
    return array;
}

int cmpInt(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}