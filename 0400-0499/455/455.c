// Problem:
// Assume you want to give your children cookies. You should give each child at
// most one cookie. Each child i has a greed factor gi, which is the minimum
// size of a cookie that the child will be content with; and each cookie j has
// a size sj. If sj >= gi, we can assign the cookie j to the child i, and the
// child i will be content. Your goal is to maximize the number of your content
// children and output the maximum number.
// - Assume the greed factor is always positive.
// 
// Example:
// Input: [1,2,3], [1,1]
// Output: 1
// 
// Solution:
// For maximum content, give the smallest cookie acceptable to each child. So
// sort 2 arrays ascendingly and iterating. If the child is content, move
// children array pointer, otherwise only move cookie array pointer. When
// cookie or children run out, the children pointer is at the next child to
// give cookie to.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    return 0;
}

/********** Solution **********/

int cmpNum(const void* a, const void* b);

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmpNum);
    qsort(s, sSize, sizeof(int), cmpNum);

    int i, j;

    for (i = j = 0; i < gSize && j < sSize; j++) {
        if (s[j] >= g[i])
            i++;
    }

    return i;
}

int cmpNum(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}