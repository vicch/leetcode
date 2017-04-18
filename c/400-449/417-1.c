// Problem:
// Given an m x n matrix of non-negative integers representing the height of
// each unit cell in a continent, the "Pacific ocean" touches the left and top
// edges of the matrix and the "Atlantic ocean" touches the right and bottom
// edges. Water can only flow in four directions (up, down, left, or right)
// from a cell to another one with height equal or lower. Find the list of grid
// coordinates where water can flow to both the Pacific and Atlantic ocean.
// 
// Example:
// Pacific ~   ~   ~   ~   ~ 
//      ~  1   2   2   3  (5) *
//      ~  3   2   3  (4) (4) *
//      ~  2   4  (5)  3   1  *
//      ~ (6) (7)  1   4   5  *
//      ~ (5)  1   1   2   4  *
//         *   *   *   *   * Atlantic
//
// Solution:
// DFS checking if each cell can flow to either of the oceans. Use 2 arrays as
// cache. Use array to avoid loop.
// 
// Lesson:
// - DFS need to avoid loop.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** pacificAtlantic(int** matrix, int matrixRowSize, int matrixColSize, int** columnSizes, int* returnSize);

int main()
{
    int m1[5][5] = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    int* c1;
    int s1;
    int** r1 = pacificAtlantic((int**)m1, 5, 5, &c1, &s1);

    return 0;
}

/********** Solution **********/

int** m;
int r;
int c;

int* cache[2];    // Result cache, each cell's ability to flow to 2 oceans
int path[100][2]; // Path cache, assume max path as 100
int pi;           // Path cache index

int pacificAtlanticSub(int ocean, int x, int y);
void addPath(int x, int y);
int inPath(int x, int y);

int** pacificAtlantic(int** matrix, int matrixRowSize, int matrixColSize, int** columnSizes, int* returnSize)
{
    *returnSize = 0;

    if (!matrix || !matrixRowSize || !matrixColSize)
        return NULL;

    int** result = malloc(sizeof(int*) * matrixRowSize * matrixColSize);
    *columnSizes = malloc(sizeof(int) * matrixRowSize * matrixColSize);

    m = matrix;
    r = matrixRowSize;
    c = matrixColSize;

    cache[0] = malloc(sizeof(int) * matrixRowSize * matrixColSize);
    cache[1] = malloc(sizeof(int) * matrixRowSize * matrixColSize);

    // Init result cache as -1, meaning "not checked"
    memset(cache[0], -1, sizeof(int) * matrixRowSize * matrixColSize);
    memset(cache[1], -1, sizeof(int) * matrixRowSize * matrixColSize);

    int i, j, a, b;

    // Init cache for cells on edges
    for (i = 0; i < r; i++) {
        cache[0][i * c] = 1;
        cache[1][i * c + c - 1] = 1;
    }
    for (i = 0; i < c; i++) {
        cache[0][i] = 1;
        cache[1][r * c - c + i] = 1;
    }

    for (i = pi = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            // Path resets after each run
            a = pacificAtlanticSub(0, i, j), pi = 0;
            b = pacificAtlanticSub(1, i, j), pi = 0;
            if (a == 1 && b == 1) {
                result[*returnSize] = malloc(sizeof(int) * 2);
                result[*returnSize][0] = i;
                result[*returnSize][1] = j;
                (*columnSizes)[(*returnSize)++] = 2;
            }
        }

    free(cache[0]);
    free(cache[1]);

    return result;
}

int pacificAtlanticSub(int ocean, int x, int y)
{
    // Cache hit
    if (cache[ocean][x * c + y] > -1)
        return cache[ocean][x * c + y];
    
    // Do not check cell if it's already in path
    if (inPath(x, y))
        return 2;

    addPath(x, y);

    int up = 0, right = 0, down = 0, left = 0;

    if (
        (x > 0 && m[x][y] >= m[x-1][y] && (up = pacificAtlanticSub(ocean, x - 1, y)) == 1) ||
        (y < c - 1 && m[x][y] >= m[x][y+1] && (right = pacificAtlanticSub(ocean, x, y + 1)) == 1) ||
        (x < r - 1 && m[x][y] >= m[x+1][y] && (down = pacificAtlanticSub(ocean, x + 1, y)) == 1) ||
        (y > 0 && m[x][y] >= m[x][y-1] && (left = pacificAtlanticSub(ocean, x, y - 1)) == 1)
    )
        return cache[ocean][x * c + y] = 1;

    // If no adjacent cell can flow to the ocean, and any of them is in path,
    // consider this cell as in path too
    if (up == 2 || right == 2 || down == 2 || left == 2)
        return 2;

    // Not able to flow to the ocean
    return cache[ocean][x * c + y] = 0;
}

void addPath(int x, int y)
{
    path[pi][0] = x;
    path[pi][1] = y;
    pi++;
    return;
}

int inPath(int x, int y)
{
    int i;
    for (i = 0; i < pi; i++)
        if (path[i][0] == x && path[i][1] == y)
            return 1;
    return 0;
}