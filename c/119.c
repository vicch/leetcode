#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* array, int num);
int* getRow(int rowIndex, int* returnSize);

int main()
{
    int size;
    int* row;

    row = getRow(0, &size);
    printArray(row, size);

    row = getRow(1, &size);
    printArray(row, size);

    row = getRow(2, &size);
    printArray(row, size);

    row = getRow(3, &size);
    printArray(row, size);

    row = getRow(4, &size);
    printArray(row, size);

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

int* getRow(int rowIndex, int* returnSize)
{
    int* lrow = malloc(sizeof(int) * rowIndex);
    int* crow = malloc(sizeof(int) * (rowIndex + 1));

    // First row
    *returnSize = 1;
    *crow = 1;

    if (rowIndex < 1) {
        return crow;
    }

    int i, j;
    for (i = 1; i <= rowIndex; i++) {
        memcpy(lrow, crow, *returnSize * sizeof(int));
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                *(crow + j) = 1;
            else
                *(crow + j) = *(lrow + j - 1) + *(lrow + j);
        }
        *returnSize += 1;
    }

    return crow;
}