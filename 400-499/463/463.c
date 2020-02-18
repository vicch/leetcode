// Problem:
// Given a map in form of a two-dimensional integer grid where 1 represents
// land and 0 represents water. Grid cells are connected horizontally or
// vertically (not diagonally). The grid is completely surrounded by water, and
// there is exactly one island (i.e., one or more connected land cells). The
// island doesn't have "lakes" (water inside that isn't connected to the water
// around the island). One cell is a square with side length 1. The grid is
// rectangular, width and height don't exceed 100. Determine the perimeter of
// the island.
// 
// Example:
// Input: [[0, 1, 0, 0],
//         [1, 1, 1, 0],
//         [0, 1, 0, 0],
//         [1, 1, 0, 0]]
// Output: 16
// 
// Solution:
// perimeter = land cell count * 4 - adjacent land cell count * 2
// Iterating the array, count land cells and check if its adjacent cells on top
// and left are land cells too.

#include <stdio.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize);

int main()
{
    return 0;
}

/********** Solution **********/

int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
    int land, adj, i, j;

    for (i = land = adj = 0; i < gridRowSize; i++)
        for (j = 0; j < gridColSize; j++)
            if (grid[i][j] == 1) {
                land++;
                if (i > 0 && grid[i - 1][j] == 1)
                    adj++;
                if (j > 0 && grid[i][j - 1] == 1)
                    adj++;
            }

    return land * 4 - adj* 2;
}