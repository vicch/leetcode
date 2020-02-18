// Problem:
// Given a 2d grid map of '1's (land) and '0's (water), count the number of
// islands. An island is surrounded by water and is formed by connecting
// adjacent lands horizontally or vertically. You may assume all four edges of
// the grid are all surrounded by water.
// 
// Example:
// Input: 11000
//        11000
//        00100
//        00011
// Output: 3
// 
// Solution:
// Use another m x n array to store the "mapped" status of each cell. When one
// cell is being mapped, recursively mark all adjacent unmapped cells of the
// same state (land or water) as "mapped" too. Iterating the original array,
// when a cell is unmapped and is land, the number of island increment by 1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numIslands(char** grid, int gridRowSize, int gridColSize);

int main()
{
    return 0;
}

/********** Solution **********/

int* map;
int row, col;

void markMap(char** grid, int x, int y, char state);

int numIslands(char** grid, int gridRowSize, int gridColSize)
{
    if (gridRowSize == 0 || gridColSize == 0)
        return 0;

    row = gridRowSize, col = gridColSize;
    map = malloc(sizeof(int) * row * col);
    memset(map, 0, sizeof(int) * row * col);

    int i, j, island;

    for (i = island = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (map[i * col + j] == 0) {
                if (grid[i][j] == '1')
                    island++;
                markMap(grid, i, j, grid[i][j]);
            }

    return island;
}

void markMap(char** grid, int x, int y, char state)
{
    map[x * col + y] = 1;

    if (y < col - 1 && map[x * col + y + 1] == 0 && grid[x][y + 1] == state) markMap(grid, x, y + 1, state);
    if (x < row - 1 && map[(x + 1) * col + y] == 0 && grid[x + 1][y] == state) markMap(grid, x + 1, y, state);
    if (x > 0 && map[(x - 1) * col + y] == 0 && grid[x - 1][y] == state) markMap(grid, x - 1, y, state);
    if (y > 0 && map[x * col + y - 1] == 0 && grid[x][y - 1] == state) markMap(grid, x, y - 1, state);

    return;
}