#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBoard(char** board, int r);
void printArray(int* array, int num);

void solve(char** board, int boardRowSize, int boardColSize);
int* markBorderCircles(int rSize, int cSize, int cirs[], int cirSize, int* bCirSize);
int onBorder(int rSize, int cSize, int n);
int* markAdjacentCircles(int cSize, int cirs[], int cirSize, int nsCirs[], int nsCirSize, int* newNsCirSize);
int isAdjacent(int cSize, int a, int b);

int main()
{
    char* b1[3];
    b1[0] = "XXX";
    b1[1] = "XOX";
    b1[2] = "XXX";
    printBoard(b1, 3);
    solve(b1, 3, 3);
    printBoard(b1, 3);

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
    if (!boardRowSize || !boardColSize) return;

    int i, j;

    // Circle positions list
    int cirs[boardRowSize * boardColSize];
    int cirSize = 0;

    // Get circle positions
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[i][j] == 'O')
                cirs[cirSize++] = i * boardColSize + j;
        }
    }

    if (!cirSize) return;

    printf("Init circles: ");
    printArray(cirs, cirSize);

    // Not surrounded circle positions list
    int* nsCirs = NULL;
    int nsCirSize = 0;

    // Mark circles on borders as first batch of un-surrounded circles
    nsCirs = markBorderCircles(boardRowSize, boardColSize, cirs, cirSize, &nsCirSize);

    printf("Border circles = %d\n", nsCirSize);

    // If there are un-surrounded circles, recursively find their adjacent circles
    // and label as un-surrounded too
    while (nsCirSize) {
        printf("Un-surrounded circles: ");
        printArray(nsCirs, nsCirSize);
        nsCirs = markAdjacentCircles(boardColSize, cirs, cirSize, nsCirs, nsCirSize, &nsCirSize);
    }

    if (nsCirs) free(nsCirs);

    printf("Surrounded circles: ");
    printArray(cirs, cirSize);

    // Change circles still in the list to crosses
    for (i = 0; i < cirSize; i++) {
        if (cirs[i] != -1) {
            printf("Change circle (%d,%d)\n", cirs[i] / boardColSize, cirs[i] % boardColSize);
            board[cirs[i] / boardColSize][cirs[i] % boardColSize] = 'X';
        }
    }

    return;
}

int* markBorderCircles(int rSize, int cSize, int cirs[], int cirSize, int* bCirSize)
{
    *bCirSize = 0;
    int* bCirs = malloc(sizeof(int) * (rSize*2 + cSize*2 - 4));
    int i;

    for (i = 0; i < cirSize; i++) {
        if (onBorder(rSize, cSize, cirs[i])) {
            bCirs[(*bCirSize)++] = cirs[i];
            cirs[i] = -1; // Remove un-surrounded circle positions from list
        }
    }

    return bCirs;
}

/**
 * If position N is on border
 */
int onBorder(int rSize, int cSize, int n)
{
    return (n < cSize) ||
           (n >= cSize * (rSize-1)) ||
           (n % cSize == 0) ||
           ((n+1) % cSize == 0);
}

int* markAdjacentCircles(int cSize, int cirs[], int cirSize, int nsCirs[], int nsCirSize, int* newNsCirSize)
{
    // Each un-surrounded circles can lead to 3 adjacent circles at most
    int* newNsCirs = malloc(sizeof(int) * nsCirSize * 3);
    int newNsCirSizeTmp = 0;
    int i, j;

    for (i = 0; i < nsCirSize; i++) {
        for (j = 0; j < cirSize; j++) {
            if (cirs[j] != -1 && isAdjacent(cSize, nsCirs[i], cirs[j])) {
                newNsCirs[newNsCirSizeTmp++] = cirs[j];
                cirs[j] = -1; // Remove un-surrounded circle from list
            }
        }
    }

    // Free last batch of un-surrounded circle positions
    free(nsCirs);
    *newNsCirSize = newNsCirSizeTmp;

    return newNsCirs;
}

/**
 * If position A and position B are adjacent
 */
int isAdjacent(int cSize, int a, int b)
{
    return (a == b+1 && a % cSize != 0) ||
           (b == a+1 && b % cSize != 0) ||
           (a == b+cSize) ||
           (b == a+cSize);
}