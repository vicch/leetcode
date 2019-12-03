// Problem:
// Given a 2D binary matrix filled with 0's and 1's, find the largest square
// containing only 1's and return its area.
// 
// Example:
// Input: 1 0 1 0 0
//        1 0 1 1 1
//        1 1 1 1 1
//        1 0 0 1 0
// Output: 4
// 
// Solution:
// DFS calculate the largest square of 1's for each cell, return the largest.

#include <stdio.h>
#include <stdio.h>
#include <string.h>

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize);

int main()
{
    return 0;
}

/********** Solution **********/

int* cache;
char** m;
int row;
int col;

int maximalSquareSub(int x, int y);

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize)
{
    if (matrixRowSize == 0 || matrixColSize == 0)
        return 0;

    int i, j, size = 0, largest = 0;

    cache = malloc(sizeof(int) * matrixRowSize * matrixColSize);
    memset(cache, -1, sizeof(int) * matrixRowSize * matrixColSize);

    m = matrix;
    row = matrixRowSize;
    col = matrixColSize;

    for (i = 0; i < matrixRowSize; i++)
        for (j = 0; j < matrixColSize; j++)
            if ((size = maximalSquareSub(i, j)) > largest)
                largest = size;

    free(cache);

    return largest * largest;
}

int maximalSquareSub(int x, int y)
{
    if (cache[x * col + y] != -1)
        return cache[x * col + y];

    if (m[x][y] == '0')
        return cache[x * col + y] = 0;

    // On right or bottom edge
    if (x == row - 1 || y == col - 1)
        return cache[x * col + y] = 1;

    int subsize, i;

    subsize = maximalSquareSub(x + 1, y + 1);

    // If current cell has enough 1's on right and bottom to form a larger
    // square on the basis of the recursive square
    for (i = 1; i <= subsize; i++)
        if (m[x + i][y] == '0' || m[x][y + i] == '0')
            break;

    return cache[x * col + y] = i;
}