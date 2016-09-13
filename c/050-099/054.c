#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize);

int main()
{

}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
    int* s = malloc(sizeof(int) * matrixRowSize * matrixColSize);
    int si = 0;

    int i = 0, j = 0;
    int it = 0, jt = matrixColSize - 1;
    int id, jd;

    while (si < matrixRowSize * matrixColSize) {
        id = (it > i) ? 1 : ((it < i) ? -1 : 0);
        jd = (jt > j) ? 1 : ((jt < j) ? -1 : 0);

        printf("i: %d to %d, %d\n", i, it, id);
        printf("j: %d to %d, %d\n", j, jt, jd);

        for (; i != it + id || j != jt + jd; i += id, j += jd) {
            printf("%d,%d\n", i, j);
            s[si++] = matrix[i][j];
        }

        j -= jd;
        i -= id;

        // Turn down or up
        if (id == 0) {
            i += jd;
            it = matrixRowSize - i;

        // Turn left or right
        } else {
            j -= id;
            jt = matrixColSize - j;
        }
    }

    return s;
}