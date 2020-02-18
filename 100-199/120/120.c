#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void printArray(int* array, int num);

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes);

int main()
{

}

void printArray(int* array, int num)
{
    printf("[");
    while (num-- > 0)
        printf((num > 0) ? "%d," : "%d", *array++);
    printf("]\n");
}

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes)
{
    int t1[triangleRowSize], t2[triangleRowSize]; // 2 arrays to swap and reuse
    int *pts = t1, *cts = t2, *tmp; // Previous totals, current totals
    int i, j, min;

    pts[0] = 0;
    for (i = 0; i < triangleRowSize; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0)
                cts[j] = triangle[i][j] + pts[0];
            else if (j == i)
                cts[j] = triangle[i][j] + pts[i-1];
            else
                cts[j] = triangle[i][j] + MIN(pts[j-1], pts[j]);
        }
        // Swap 2 total arrays
        tmp = pts, pts = cts, cts = tmp;
    }

    // Find the minimum total in final totals
    for (min = pts[0], i = 0; i < triangleRowSize; i++)
        if (pts[i] < min)
            min = pts[i];

    return min;
}