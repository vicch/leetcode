#include <stdio.h>
#include <stdlib.h>

void printArrays(int** array, int num);
void printArray(int* array, int num);

int** generateMatrix(int n);
int moveHorizontal(int num, int** matrix, int x, int y, int dir, int count);
int moveVertical(int num, int** matrix, int x, int y, int dir, int count);

int main()
{
    int** m1 = generateMatrix(2);
    printArrays(m1, 2);

    int** m2 = generateMatrix(3);
    printArrays(m2, 3);

    return 0;
}

void printArrays(int** array, int num)
{
    int i = 0;
    while (i < num)
        printArray(array[i++], num);
}

void printArray(int* array, int num)
{
    printf("[");
    while (num-- > 0)
        printf((num > 0) ? "%d," : "%d]\n", *array++);
}

int** generateMatrix(int n)
{
    if (n == 0) return NULL;

    int** matrix = malloc(sizeof(int*) * n);
    int i;

    for (i = 0; i < n; i++)
        matrix[i] = malloc(sizeof(int) * n);

    int num = 1, x = 0, y = 0, dir = 1, count = n;

    for (i = 1; ; i++) {
        num = moveHorizontal(num, matrix, x, y, dir, count);
        x += dir;
        y += (count - 1) * dir;
        count = n - i;
        if (count <= 0) break;
        
        num = moveVertical(num, matrix, x, y, dir, count);
        x += (count - 1) * dir;
        y -= dir;
        count = n - i;
        if (count <= 0) break;

        dir = -dir;
    }

    return matrix;
}

int moveHorizontal(int num, int** matrix, int x, int y, int dir, int count)
{
    int i;
    for (i = 0; i < count; y += dir, i++)
        matrix[x][y] = num++;
    return num;
}

int moveVertical(int num, int** matrix, int x, int y, int dir, int count)
{
    int i;
    for (i = 0; i < count; x += dir, i++)
        matrix[x][y] = num++;
    return num;
}