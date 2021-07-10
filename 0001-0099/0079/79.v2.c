#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;

bool exist(char** board, int boardRowSize, int boardColSize, char* word);
bool existSub(char** board, int row, int col, int x, int y, char* word);

int main()
{
    return 0;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word)
{
    int x, y;
    for (x = 0; x < boardRowSize; x++)
        for (y = 0; y < boardColSize; y++)
            if (existSub(board, boardRowSize, boardColSize, x, y, word))
                return true;
    return false;
}

bool existSub(char** board, int row, int col, int x, int y, char* word)
{
    if (*word == '\0') return true;
    if (x < 0 || y < 0 || x == row || y == col || board[x][y] != *word) return false;

    // Set visited character to an impossible value, to avoid re-visit
    char tmp = board[x][y];
    board[x][y] = '\0';
    bool exist = existSub(board, row, col, x-1, y, word+1) ||
                 existSub(board, row, col, x, y-1, word+1) ||
                 existSub(board, row, col, x, y+1, word+1) ||
                 existSub(board, row, col, x+1, y, word+1);
    board[x][y] = tmp;
    return exist;
}