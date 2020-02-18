#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;

void printArrays(int** arrays, int* cols, int size);
void printArray(int* seq, int count);

bool exist(char** board, int boardRowSize, int boardColSize, char* word);
bool adjacent(int a, int b, int colSize);
bool inArray(int* a, int s, int t);

int main()
{
    // char** board = malloc(sizeof(char*) * 3);
    // board[0] = malloc(sizeof(char) * 4);
    // board[0][0] = 'A';
    // board[0][1] = 'B';
    // board[0][2] = 'C';
    // board[0][3] = 'E';
    // board[1] = malloc(sizeof(char) * 4);
    // board[1][0] = 'S';
    // board[1][1] = 'F';
    // board[1][2] = 'C';
    // board[1][3] = 'S';
    // board[2] = malloc(sizeof(char) * 4);
    // board[2][0] = 'A';
    // board[2][1] = 'D';
    // board[2][2] = 'E';
    // board[2][3] = 'E';
    // char* word = "ABCEC";

    char** board = malloc(sizeof(char*) * 1);
    board[0] = malloc(sizeof(char) * 1);
    board[0][0] = 'a';
    char* word = "a";

    printf("Result: %d\n", exist(board, 1, 1, word));

    return 0;
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
    int l = strlen(word);
    if (l == 0 || l > boardRowSize * boardColSize) return 0;

    int* map[256];
    int size[256];
    int path[l];
    int i, j, k;

    for (i = 0; i < 256; i++)
        map[i] = NULL, size[i] = 0;

    // Make letter map
    for (i = 0; i < boardRowSize; i++)
        for (j = 0; j < boardColSize; j++) {
            k = board[i][j];
            map[k] = realloc(map[k], sizeof(int) * (++size[k]));
            map[k][size[k] - 1] = i * boardColSize + j;
        }

    // printArrays(map, size, 26);

    i = 0;
    memset(path, -1, sizeof(path));

    while (i >= 0 && i < l) {
        k = word[i];

        // Letter not exist
        if (size[k] == 0) return 0;

        // Find loop start
        for (j = 0; j < size[k] && path[i] >= map[k][j]; j++);

        for (; j < size[k]; j++) {
            // First letter, do not check for adjacent
            if ((i == 0 || adjacent(path[i - 1], map[k][j], boardColSize)) && !inArray(path, i, map[k][j])) {
                path[i++] = map[k][j];
                break;
            }
        }

        // Revert to previous letter
        if (j == size[k]) path[i--] = -1;
    }

    // printArray(path, i);

    return i >= 0;
}

bool adjacent(int a, int b, int colSize)
{
    int ra = a / colSize, rb = b / colSize;
    int ca = a % colSize, cb = b % colSize;

    return (ra == rb && (ca == cb + 1 || cb == ca + 1)) ||
           (ca == cb && (ra == rb + 1 || rb == ra + 1));
}

bool inArray(int* a, int s, int t)
{
    int i;
    for (i = 0; i < s; i++)
        if (a[i] == t)
            return 1;
    return 0;
}