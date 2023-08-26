#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target);
int getRow(int** matrix, int rows, int target);
int getCol(int** matrix, int row, int cols, int target);

int main()
{
    int** m = (int**)malloc(sizeof(int*) * 2);
    m[0] = (int*)malloc(sizeof(int) * 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1] = (int*)malloc(sizeof(int) * 2);
    m[1][0] = 3;
    m[1][1] = 4;

    searchMatrix(m, 2, 2, 4);

    return 0;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    int row = getRow(matrix, matrixRowSize, target);
    int col = getCol(matrix, row, matrixColSize, target);
    return matrix[row][col] == target;
}

int getRow(int** matrix, int rows, int target)
{
    int l = 0;
    int r = rows - 1;
    int m;
    
    while (l < r) {
        m = (l + r) / 2;
        if (matrix[m][0] <= target)
            if (matrix[m+1][0] > target)
                return m;
            else
                l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int getCol(int** matrix, int row, int cols, int target)
{
    int l = 0;
    int r = cols - 1;
    int m;
    
    while (l < r) {
        m = (l + r) / 2;
        if (matrix[row][m] == target)
            return m;
        else if (matrix[row][m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}