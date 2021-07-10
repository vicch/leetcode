// Problem:
// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
// each cell. The distance between two adjacent cells is 1.
// 
// Example:
// Input: 0 0 0
//        0 1 0
//        1 1 1
// Output: 0 0 0
//         0 1 0
//         1 2 1
//         

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** updateMatrix(int** matrix, int matrixRowSize, int matrixColSize, int** columnSizes, int* returnSize);

int main()
{
    return 0;
}

/********** Solution **********/

#define MIN(a, b) ((a) > (b) ? (b) : (a))

int getNewCell(int** old, int** new, int row, int col, int x, int y, int recur, int dep);

int** updateMatrix(int** matrix, int matrixRowSize, int matrixColSize, int** columnSizes, int* returnSize)
{
    *returnSize = matrixRowSize;
    *columnSizes = malloc(sizeof(int) * matrixRowSize);

    int i, j;
    int** new = malloc(sizeof(int*) * matrixRowSize);

    for (i = 0; i < matrixRowSize; i++) {
        (*columnSizes)[i] = matrixColSize;
        new[i] = malloc(sizeof(int) * matrixColSize);
        memset(new[i], -1, sizeof(int) * matrixColSize);
    }

    for (i = 0; i < matrixRowSize; i++)
        for (j = 0; j < matrixColSize; j++)
            if (matrix[i][j] == 0)
                new[i][j] = 0;

    for (i = 0; i < matrixRowSize; i++)
        for (j = 0; j < matrixColSize; j++)
            if (new[i][j] == -1 || new[i][j] > 10000)
                new[i][j] = getNewCell(matrix, new, matrixRowSize, matrixColSize, i, j, 0, 0);

    return new;
}

int getNewCell(int** old, int** new, int row, int col, int x, int y, int recur, int dep)
{
    // printf("%*s", dep, "");
    // printf("(%d, %d)\\n", x, y);

    if (new[x][y] != -1 && (recur || new[x][y] < 10000)) {
        // printf("%*s", dep, "");
        // printf("(%d, %d) found %d\\n", x, y, new[x][y]);
        return new[x][y];
    }

    // Use impossible big number to indicate this cell is being checked
    new[x][y] = 10000;

    if (
        (x > 0 && old[x - 1][y] == 0) ||
        (y > 0 && old[x][y - 1] == 0) ||
        (x < row - 1 && old[x + 1][y] == 0) ||
        (y < col - 1 && old[x][y + 1] == 0)
    ) {
        // printf("%*s", dep, "");
        // printf("(%d, %d) return 1\\n", x, y, new[x][y]);
        return new[x][y] = 1;
    }

    int min, adj;

    min = 10000;

    if (x > 0) adj = getNewCell(old, new, row, col, x - 1, y, 1, dep + 1), min = MIN(min, adj);
    if (y > 0) adj = getNewCell(old, new, row, col, x, y - 1, 1, dep + 1), min = MIN(min, adj);
    if (x < row - 1) adj = getNewCell(old, new, row, col, x + 1, y, 1, dep + 1), min = MIN(min, adj);
    if (y < col - 1) adj = getNewCell(old, new, row, col, x, y + 1, 1, dep + 1), min = MIN(min, adj);

    // printf("%*s", dep, "");
    // printf("(%d, %d) return %d\\n", x, y, min + 1);
    return new[x][y] = min + 1;
}