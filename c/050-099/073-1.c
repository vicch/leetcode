#include <stdio.h>
#include <string.h>

int main()
{

}

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize)
{
    int* zrows[matrixRowSize];
    int* zcols[matrixColSize];
    memset(zrows, 0, sizeof(zrows));
    memset(zcols, 0, sizeof(zcols));

    int i, j;

    for (i = 0; i < matrixRowSize; i++) {
        for (j = 0; j < matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                zrows[i] = 1;
                zcols[j] = 1;
            }
        }
    }

    for (i = 0; i < matrixRowSize; i++) {
        for (j = 0; j < matrixColSize; j++) {
            if (zrows[i] || zcols[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return;
}