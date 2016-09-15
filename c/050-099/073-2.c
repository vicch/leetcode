#include <stdio.h>
#include <string.h>

int main()
{

}

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize)
{
    int fcol = 1;

    int i, j;

    for (i = 0; i < matrixRowSize; i++) {
        if (matrix[i][0] == 0) fcol = 0;
        for (j = 1; j < matrixColSize; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (i = matrixRowSize - 1; i >= 0; i--) {
        for (j = matrixColSize - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (fcol == 0) matrix[i][0] = 0;
    }

    return;
}