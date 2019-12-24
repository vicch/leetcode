#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** combine(int n, int k, int** columnSizes, int* returnSize);
int calcCombination(int a, int b);

int main()
{
    return 0;
}

int** combine(int n, int k, int** columnSizes, int* returnSize)
{
    *returnSize = calcCombination(n, k);
    *columnSizes = malloc(sizeof(int) * *returnSize);
    int** ret = malloc(sizeof(int*) * *returnSize);

    int i = 0, j = 0;
    int p[k];
    memset(p, 0, sizeof(p));

    while (i >= 0) {
        p[i]++;
        if (p[i] > n) --i;
        else if (i == k - 1) {
            (*columnSizes)[j] = k;
            ret[j] = malloc(sizeof(int) * k);
            memcpy(ret[j], p, sizeof(p));
            j++;
        } else {
            ++i;
            p[i] = p[i - 1];
        }
    }

    return ret;
}

int calcCombination(int a, int b)
{
    int r = 1, i;
    for (i = 1; i <= b; i++) {
        r *= a + 1 - i;
        r /= i;
    }
    return r;
}