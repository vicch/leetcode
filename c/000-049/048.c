#include <stdio.h>
#include <string.h>

void printArray(int* seq, int count);
void rotate(int** matrix, int matrixRowSize, int matrixColSize);

int main()
{
    // int m[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    // rotate(m, 3, 3);
    // printArray(m[0], 3);
    // printArray(m[1], 3);
    // printArray(m[2], 3);

    return 0;
}

void printArray(int* seq, int count)
{
    printf("[");
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d]\n", *seq++);
    return;
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize)
{
    if (matrixRowSize != matrixColSize || matrixRowSize == 1 || matrixColSize == 1)
        return;

    int moved[matrixRowSize][matrixRowSize];
    memset(moved, 0, sizeof(moved));

    int x, y, i, j;
    int v, vt, t;
    for (y = 0; y < matrixRowSize; y++) {
        for (x = 0; x < matrixRowSize; x++) {
            for (
                i = x, j = y, v = matrix[i][j];
                moved[i][j] != 1;
                t = i, i = j, j = matrixRowSize-t-1, v = vt
            ) {
                vt = matrix[j][matrixRowSize-i-1];
                matrix[j][matrixRowSize-i-1] = v;
                moved[i][j] = 1;
            }
        }
    }
    return;
}