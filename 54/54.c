#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int num);

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize);
int* moveHorizontal(int* seq, int** matrix, int x, int y, int dir, int count);
int* moveVertical(int* seq, int** matrix, int x, int y, int dir, int count);

int main()
{
    int** m1 = malloc(sizeof(int*) * 2);
    m1[0] = malloc(sizeof(int) * 2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1] = malloc(sizeof(int) * 2);
    m1[1][0] = 3;
    m1[1][1] = 4;
    int* s1 = spiralOrder(m1, 2, 2);
    printArray(s1, 4);

    return 0;
}

void printArray(int* array, int num)
{
    while (num-- > 0)
        printf((num > 0) ? "%d," : "%d\n", *array++);
}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
    int* seq = malloc(sizeof(int) * matrixRowSize * matrixColSize);
    int x = 0, y = 0, dir = 1, count = matrixColSize;
    int i;

    for (i = 1; ; i++) {
        seq = moveHorizontal(seq, matrix, x, y, dir, count);
        x += dir;
        y += (count - 1) * dir;
        count = matrixRowSize - i;
        if (count <= 0) break;
        
        seq = moveVertical(seq, matrix, x, y, dir, count);
        x += (count - 1) * dir;
        y -= dir;
        count = matrixColSize - i;
        if (count <= 0) break;
        dir = -dir;
    }

    return seq - matrixRowSize * matrixColSize;
}

int* moveHorizontal(int* seq, int** matrix, int x, int y, int dir, int count)
{
    int i;
    for (i = 0; i < count; y += dir, i++)
        *seq++ = matrix[x][y];
    return seq;
}

int* moveVertical(int* seq, int** matrix, int x, int y, int dir, int count)
{
    int i;
    for (i = 0; i < count; x += dir, i++)
        *seq++ = matrix[x][y];
    return seq;
}