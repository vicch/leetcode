#include <stdio.h>

int numTrees(int n);
int numTreesSub(int seq[], int n);

int main()
{
    printf("%d\n", numTrees(0));
    printf("%d\n", numTrees(1));
    printf("%d\n", numTrees(2));
    printf("%d\n", numTrees(3));
    printf("%d\n", numTrees(4));
    printf("%d\n", numTrees(5));

    return 0;
}

int numTrees(int n)
{
    if (n < 1) return 0;

    // seq[] stores tree numbers of different numbers of nodes
    // Use these numbers to calculate larger ones, to avoid recursion
    int i, seq[n+1];
    for (i = 0; i <= n; i++)
        seq[i] = numTreesSub(seq, i);
    return seq[n];
}

/**
 * With tree numbers of 0 to n-1 nodes, return tree number of n nodes
 */
int numTreesSub(int seq[], int n)
{
    if (n < 2) return 1;

    int i, num = 0;
    for (i = 0; i < n / 2; i++)
        num += seq[i] * seq[n-i-1] * 2;
    if (i * 2 < n)
        num += seq[i] * seq[i];
    return num;
}