#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minPathSum(int** grid, int gridRowSize, int gridColSize);

int main()
{
    return 0;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
    int pathSum[gridRowSize][gridColSize];
    int i, j;

    pathSum[0][0] = grid[0][0];

    for (i = 1; i < gridRowSize; i++) pathSum[i][0] = pathSum[i-1][0] + grid[i][0];
    for (j = 1; j < gridColSize; j++) pathSum[0][j] = pathSum[0][j-1] + grid[0][j];

    for (i = 1; i < gridRowSize; i++)
        for (j = 1; j < gridColSize; j++)
            pathSum[i][j] = MIN(pathSum[i-1][j], pathSum[i][j-1]) + grid[i][j];

    return pathSum[i-1][j-1];
}