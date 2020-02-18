#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int num);
int** generate(int numRows, int** columnSizes);

int main()
{
    int* columnSizes;
    int** results = generate(10, &columnSizes);

    int i;
    for (i = 0; i < 10; i++) {
        printArray(*(results + i), *(columnSizes + i));
    }

    return 0;
}

void printArray(int* array, int num)
{
    printf("[");
    while (num-- > 0) {
        printf((num > 0) ? "%d," : "%d", *array++);
    }
    printf("]\n");
}

int** generate(int numRows, int** columnSizes)
{
    int** results = malloc(sizeof(int*) * numRows);
    *columnSizes = malloc(sizeof(int) * numRows);

    int lcount = 0;
    int* lrow;
    int i = 0, j;

    while (i < numRows) {
        *(results + i) = malloc(sizeof(int) * (lcount + 1));
        for (j = 0; j < lcount + 1; j++) {
            if (j == 0 || j == lcount)
                *(*(results + i) + j) = 1;
            else
                *(*(results + i) + j) = *(lrow + j - 1) + *(lrow + j);
        }
        *(*columnSizes + i) = lcount + 1;
        lrow = *(results + i);
        lcount++;
        i++;
    }

    return results;
}