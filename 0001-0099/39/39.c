#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArrays(int** arrays, int* cols, int size);
void printArray(int* seq, int count);

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize);
int** combination(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize);
int* joinArray(int* a, int sa, int* b, int sb);
int* repeatInt(int v, int t);
int cmpInt(const void * a, const void * b);

int main()
{
    // int seq1[] = {2,3,6,7};
    // int* cols1;
    // int size1;
    // int** comb1 = combinationSum(seq1, 4, 7, &cols1, &size1);
    // printf("%d\n", size1);
    // printArrays(comb1, cols1, size1);

    // int seq2[] = {7,3,2};
    // int* cols2;
    // int size2;
    // int** comb2 = combinationSum(seq2, 3, 18, &cols2, &size2);
    // printf("%d\n", size2);
    // printArrays(comb2, cols2, size2);

    int seq3[] = {8,10,6,3,4,12,11,5,9};
    int* cols3;
    int size3;
    int** comb3 = combinationSum(seq3, 9, 28, &cols3, &size3);
    printf("%d\n", size3);
    printArrays(comb3, cols3, size3);

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

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
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

    int i, j;
    for (i = candidatesSize - 1; i >= 0; i--) {
        if (candidates[i] > target) continue;

        for (j = 1; j * candidates[i] < target; j++) {
            if (i > 0) {
                int subReturnSize;
                int* subColumnSizes;
                int** subCombination = combination(candidates, i, target - j * candidates[i], &subColumnSizes, &subReturnSize);

                if (subReturnSize > 0) {
                    int* base = repeatInt(candidates[i], j);
                    int k;
                    for (k = 0; k < subReturnSize; k++) {
                        comb[*returnSize] = joinArray(base, j, subCombination[k], subColumnSizes[k]);
                        (*columnSizes)[*returnSize] = j + subColumnSizes[k];
                        (*returnSize)++;
                        free(subCombination[k]);
                    }
                    free(base);
                    free(subColumnSizes);
                    free(subCombination);
                }
            }
        }

        if (j * candidates[i] == target) {
            comb[*returnSize] = repeatInt(candidates[i], j);
            (*columnSizes)[*returnSize] = j;
            (*returnSize)++;
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