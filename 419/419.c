// Problem:
// Given an 2D board, count how many battleships are in it. The battleships are
// represented with "X", empty slots are represented with ".". Rules:
// - Input is a valid board, made of only battleships or empty slots.
// - Battleships can only be placed horizontally or vertically.
// - Battleships can be of any size
// - At least one horizontal or vertical cell separates between two battleships.
// Do it in one-pass, using only O(1) extra memory and without modifying the
// value of the board.
// 
// Example:
// X..X
// ...X
// ...X
// 
// Solution:
// Count number of separate "X" groups in each row, ignoring slots where the
// slot above it is also an "X".

#include <stdio.h>

int countBattleships(char** board, int boardRowSize, int boardColSize);

int main()
{
    return 0;
}

int countBattleships(char** board, int boardRowSize, int boardColSize)
{
    int i, j, state, count;

    state = count = 0;
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[i][j] == 'X') {
                if (state == 0 && (i == 0 || board[i-1][j] == '.'))
                    count++;
                state = 1;
            } else
                state = 0;
        }
        state = 0;
    }

    return count;
}