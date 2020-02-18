// Problem:
// Given a matrix of M x N elements (M rows, N columns), return all elements of
// the matrix in diagonal order.
// 
// Example:
// Input: [
//     [1, 2, 3],
//     [4, 5, 6],
//     [7, 8, 9]
// ]
// Output: [1, 2, 4, 7, 5, 3, 6, 8, 9]
// 
// Solution:
// On each run, x + y is a fixed value. Outter loop increments this value, and
// inner loop increment or decrement x within the matrix boundary.

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize);

int main()
{
    return 0;
}

int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize)
{
    int i, x, d;
    int* ret = malloc(sizeof(int) * matrixRowSize * matrixColSize);

    for (i = *returnSize = 0, d = 1; i < matrixRowSize + matrixColSize - 1; i++, d = -d)
        if (d == 1)
            for (x = MIN(matrixRowSize - 1, i); x > MAX(-1, i - matrixColSize); x--)
                ret[(*returnSize)++] = matrix[x][i - x];
        else
            for (x = MAX(0, i - matrixColSize + 1); x < MIN(i + 1, matrixRowSize); x++)
                ret[(*returnSize)++] = matrix[x][i - x];

    return ret;
}