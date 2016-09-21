#include <stdio.h>
#include <stdlib.h>

void printArrays(int** arrays, int* cols, int size);
void printArray(int* seq, int count);

int** combine(int n, int k, int** columnSizes, int* returnSize);
int calcCombination(int a, int b);
int* nextIncrs(int* incrs, int size, int max);

int main()
{
    // int* incrs = malloc(sizeof(int) * 2);
    // incrs[0] = 1;
    // incrs[1] = 4;
    // incrs = nextIncrs(incrs, 2, 4);
    // printArray(incrs, 2);

    int* cols;
    int size;
    int** comb = combine(4, 2, &cols, &size);
    printf("%d\n", size);
    printArray(cols, size);
    printArrays(comb, cols, size);

    return 0;
}

void printArrays(int** arrays, int* cols, int size)
{
    for (; size > 0; size--, arrays++, cols++)
        printArray(*arrays, *cols);
    return;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d\n", *seq++);
    return;
}

int** combine(int n, int k, int** columnSizes, int* returnSize)
{
    int* incrs = malloc(sizeof(int) * k);
    incrs[0] = -1;

    int i, j, idx = 0;

    *returnSize = calcCombination(n, k);
    *columnSizes = malloc(sizeof(int) * *returnSize);
    int** ret = malloc(sizeof(int*) * *returnSize);
    
    while (incrs = nextIncrs(incrs, k, n-1)) {
        for (i = 1; i + incrs[k-1] <= n; i++, idx++) {
            (*columnSizes)[idx] = k;
            ret[idx] = malloc(sizeof(int) * k);
            for (j = 0; j < k; j++)
                ret[idx][j] = i + incrs[j];
        }
    }

    return ret;
}

int calcCombination(int a, int b)
{
    int r = 1, i;
    for (i = 1; i <= b; i++) {
        r *= a + 1 - i;
        r /= i;
    }
    return r;
}

/**
 * Get next set of increments
 * e.g. 3 increments, max increment is 5:
 * 1,2,3 -> 1,2,4
 * 1,4,5 -> 2,4,5
 */
int* nextIncrs(int* incrs, int size, int max)
{
    int i;

    // Init as 0,1,2...
    if (incrs[0] == -1) {
        for (i = 0; i < size; i++)
            incrs[i] = i;
        return incrs;
    }

    for (i = size-1; i > 0 && incrs[i] >= max+i+1-size; i--);

    if (i < 1)
        return NULL;

    incrs[i] += 1;
    for (i++; i < size; i++)
        incrs[i] = incrs[i-1] + 1;

    return incrs;
}