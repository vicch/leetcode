#include <stdio.h>
#include <stdlib.h>

int isValidSudoku(char** board, int boardRowSize, int boardColSize);
char* getCells(char** board, int x1, int y1, int x2, int y2);
int validCells(char* cells);

int main()
{
    char* board[9];
    board[0] = "187654321";
    board[1] = "2........";
    board[2] = "3........";
    board[3] = "4........";
    board[4] = "5........";
    board[5] = "6........";
    board[6] = "7........";
    board[7] = "8........";
    board[8] = "9........";

    printf("%d\n", isValidSudoku(board, 9, 9));

    return 0;
}

int isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
    int i, j;

    // Check rows
    for (i = 0; i < 9; i++) {
        if (!validCells(getCells(board, i, 0, i, 8))) {
            return 0;
        }
    }

    // Check columns
    for (i = 0; i < 9; i++) {
        if (!validCells(getCells(board, 0, i, 8, i)))
            return 0;
    }

    // Check squares
    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            if (!validCells(getCells(board, i, j, i+2, j+2)))
                return 0;
        }
    }

    return 1;
}

char* getCells(char** board, int x1, int y1, int x2, int y2)
{
    char* cells = malloc(10);
    int i, j, k;

    k = 0;
    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            cells[k++] = board[i][j];
        }
    }
    cells[9] = '\0';

    return cells;
}

int validCells(char* cells)
{
    int nums[9];
    int i;

    for (i = 0; i < 9; i++) {
        nums[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        if (cells[i] < '0' || cells[i] > '9') {
            continue;
        }
        if (nums[cells[i] - '0' - 1] == 0) {
            nums[cells[i] - '0' - 1] = 1;
        } else {
            return 0;
        }
    }

    return 1;
}