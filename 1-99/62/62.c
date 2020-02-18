#include <stdio.h>

int uniquePaths(int m, int n);

int main()
{
    printf("%d\n", uniquePaths(3, 7));

    return 0;
}

int uniquePaths(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;

    int t = m + n - 2;
    int s = (m > n) ? n - 1 : m - 1;

    unsigned long p = 1;
    int i;

    for (i = 0; i < s; i++, t--) {
        p *= t;
        p /= i + 1;
    }

    return p;
}