#include <stdio.h>
#include <stdlib.h>

struct Obstacle {
    int x;
    int y;
    long pathTo;
};

long uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize);
int needCheckObstacle(int h, int w, int obsTop, int obsLeft, int obsBottom, int obsRight, int x, int y);
long pathBetween(int x1, int y1, int x2, int y2);

int main()
{
    printf("%d\n", pathBetween(0, 0, 2, 2));

    return 0;
}

long uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
    long path = pathBetween(0, 0, obstacleGridRowSize - 1, obstacleGridColSize - 1);
    if (path == 0 || obstacleGrid[0][0] == 1) return 0;

    struct Obstacle** obs = malloc(sizeof(struct Obstacle*) * obstacleGridRowSize * obstacleGridRowSize);
    int obsSize = 0, obsTop = -1, obsLeft = -1, obsBottom = -1, obsRight = -1;

    int i, j, k;
    long pathTo, pathFrom, pathBtw;

    for (i = 0; i < obstacleGridRowSize; i++) {
        for (j = 0; j < obstacleGridColSize; j++) {
            if (obstacleGrid[i][j] == 1 && needCheckObstacle(obstacleGridRowSize, obstacleGridColSize, obsTop, obsLeft, obsBottom, obsRight, i, j)) {
                pathTo = pathBetween(0, 0, i, j);
                pathFrom = pathBetween(i, j, obstacleGridRowSize - 1, obstacleGridColSize - 1);

                // Minus path
                printf("Minus path at %d,%d\n", i, j);
                printf("%ld - %ld * %ld = %ld\n", path, pathTo, pathFrom, path - pathTo * pathFrom);
                path -= pathTo * pathFrom;

                // Add back repeated path
                for (k = 0; k < obsSize; k++) {
                    if (pathBtw = pathBetween(obs[k]->x, obs[k]->y, i, j)) {
                        printf("%ld + %ld * %ld * %ld = %ld\n", path, obs[k]->pathTo, pathBtw, pathFrom, path + pathBtw * obs[k]->pathTo * pathFrom);
                        path += obs[k]->pathTo * pathBtw * pathFrom;
                    }
                }

                if (path == 0) return 0;

                // Save obstacle
                obs[obsSize] = malloc(sizeof(struct Obstacle));
                obs[obsSize]->x = i;
                obs[obsSize]->y = j;
                obs[obsSize]->pathTo = pathTo;
                obsSize++;

                if (obsTop == -1 || i < obsTop) obsTop = i;
                if (obsLeft == -1 || j < obsLeft) obsLeft = j;
                if (i > obsBottom) obsBottom = i;
                if (j > obsRight) obsRight = j;
            }
        }
    }

    return path;
}

int needCheckObstacle(int h, int w, int obsTop, int obsLeft, int obsBottom, int obsRight, int x, int y)
{
    if (obsTop == -1 && obsLeft == -1) return 1;
    if (x > obsBottom && y > obsRight) return 1;
    if (x <= obsBottom && obsTop > 0) return 1;
    if (y <= obsRight && obsLeft > 0) return 1;
    return 0;
}

long pathBetween(int x1, int y1, int x2, int y2)
{
    if (x2 < x1 || y2 < y1) return 0;
    if (x2 == x1 || y2 == y1) return 1;

    int m = x2 - x1 + 1;
    int n = y2 - y1 + 1;
    int t = m + n - 2;
    int s = (m > n) ? n - 1 : m - 1;

    long p = 1;
    int i;

    for (i = 0; i < s; i++, t--) {
        p *= t;
        p /= i + 1;
    }

    return p;
}