#include <stdio.h>
#include <stdlib.h>

typedef int bool;

void printArrays(int** arrays, int* cols, int size);
void printArray(int* seq, int count);

bool exist(char** board, int boardRowSize, int boardColSize, char* word);
bool adjacent(int a, int b, int colSize);

int main()
{
    char** board = malloc(sizeof(char*) * 2);
    board[0] = malloc(sizeof(char) * 2);
    board[0][0] = 'A';
    board[0][1] = 'B';
    board[1] = malloc(sizeof(char) * 2);
    board[1][0] = 'C';
    board[1][1] = 'A';

    char* word = "ABC";

    exist(board, 2, 2, word);
}

void printArrays(int** arrays, int* cols, int size)
{
    for (; size > 0; size--, arrays++, cols++)
        printArray(*arrays, *cols);
    return;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d\n", *seq++);
    return;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word)
{
    int* map[26];
    int size[26];
    int i, j, k;

    for (i = 0; i < 26; i++)
        map[i] = NULL, size[i] = 0;

    for (i = 0; i < boardRowSize; i++)
        for (j = 0; j < boardColSize; j++) {
            k = board[i][j] - 'A';
            map[k] = realloc(map[k], sizeof(int) * (++size[k]));
            map[k][size[k]-1] = i * boardRowSize + j;
        }

    printArrays(map, size, 26);

    return 1;
}

bool adjacent(int a, int b, int colSize)
{
    int ra = a / colSize, rb = b / colSize;
    int ca = a % colSize, cb = b % colSize;

    return (ra == rb && (ca = cb + 1 || cb = ca + 1)) ||
           (ca == cb && (ra = rb + 1 || rb = ra + 1));
}