#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBoard(char** board, int r);
void printArray(int* array, int num);

void solve(char** board, int boardRowSize, int boardColSize);
void markRecursive(int** all, int rSize, int cSize, int x, int y, int dir);

int main()
{
    char** b1 = malloc(sizeof(char*) * 4);
    b1[0] = malloc(sizeof(char) * 6), strcpy(b1[0], "XOXOXO");
    b1[1] = malloc(sizeof(char) * 6), strcpy(b1[1], "OXOXOX");
    b1[2] = malloc(sizeof(char) * 6), strcpy(b1[2], "XOXOXO");
    b1[3] = malloc(sizeof(char) * 6), strcpy(b1[3], "OXOXOX");
    printBoard(b1, 4);
    solve(b1, 4, 6);
    printBoard(b1, 4);

    return 0;
}

void printBoard(char** board, int r)
{
    int i;
    for (i = 0; i < r; i++)
        printf("%s\n", board[i]);
    return;
}

void printArray(int* array, int num)
{
    printf("[");
    while (num-- > 0)
        printf((num > 0) ? "%d," : "%d", *array++);
    printf("]\n");
}

void solve(char** board, int boardRowSize, int boardColSize)
{
    if (boardRowSize < 3 || boardColSize < 3) return;

    int i, j;

    // Mark all positions: 0 == 'X', 1 == 'O'
    int** all = malloc(sizeof(int*) * boardRowSize);
    for (i = 0; i < boardRowSize; i++) 
        all[i] = malloc(sizeof(int) * boardColSize);

    // Border circle postions
    int bCirs[boardRowSize*2 + boardColSize*2 - 4];
    int bCirSize = 0;

    // Mark positions
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[i][j] == 'O') {
                // If on borders
                if (i == 0 || i == boardRowSize-1 || j == 0 || j == boardColSize-1)
                    bCirs[bCirSize++] = i * boardColSize + j;
                all[i][j] = 1;
            } else
                all[i][j] = 0;
        }
    }

    // printf("Border circles: ");
    // printArray(bCirs, bCirSize);

    // Recursively mark connected circles as not surrounded
    for (i = 0; i < bCirSize; i++) {
        markRecursive(all, boardRowSize, boardColSize, bCirs[i] / boardColSize, bCirs[i] % boardColSize, 0);
    }

    // printf("Surrounded circles:\n");
    // for (i = 0; i < boardRowSize; i++)
    //     printArray(all[i], boardColSize);

    // Change un-marked 'O' to 'X'
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (all[i][j]) {
                // printf("Surrounded circle (%d,%d)\n", i, j);
                board[i][j] = 'X';
            }
        }
        free(all[i]);
    }

    free(all);

    // printf("Board:\n");
    // for (i = 0; i < boardRowSize; i++)
    //     printf("%s\n", board[i]);

    return;
}

void markRecursive(int** all, int rSize, int cSize, int x, int y, int dir)
{
    // printf("Mark (%d,%d)\n", x, y);
    if (all[x][y]) {
        all[x][y] = 0;
        // Do not mark borders or go back to coming direction
        if (dir != 3 && x > 1) markRecursive(all, rSize, cSize, x-1, y, 1);       // Up
        if (dir != 4 && y > 1) markRecursive(all, rSize, cSize, x, y-1, 2);       // Left
        if (dir != 1 && x < rSize-2) markRecursive(all, rSize, cSize, x+1, y, 3); // Down
        if (dir != 2 && y < cSize-2) markRecursive(all, rSize, cSize, x, y+1, 4); // Right
    }
    return;
}