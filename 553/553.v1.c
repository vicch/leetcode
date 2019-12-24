// Problem:
// Given a list of positive integers, the adjacent integers will perform the
// float division. For example, [2,3,4] -> 2/3/4. You can add any number of
// parenthesis at any position to change the priority of operations. Find out
// how to add parenthesis to get the maximum result, and return the
// corresponding expression in string format. Your expression should NOT
// contain redundant parenthesis.
// - The length of the input array is [1, 10].
// - Elements in the given array will be in range [2, 1000].
// - There is only one optimal division for each test case.
// 
// Example:
// Input: [1000,100,10,2]
// Output: "1000/(100/10/2)"
// 
// Solution:
// Consider each expression as n/m, to maximize n/m, n should be maximized and
// m should be minimized. And recursively m is p/q, where q should be minimized
// and q be maximized. Compute the max amd min value for each subsequence, use
// DP arrays to caches the results. And return max(begin, end) in the end.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* optimalDivision(int* nums, int numsSize);

int main()
{
    int nums1[] = {1000, 100, 10, 2};
    printf("%s\n", optimalDivision(nums1, 4));

    return 0;
}

/********** Solution **********/

void optimalSub(int* nums, float** vmin, float** vmax, char*** smin, char*** smax, int f, int t);
char* itoa(int n);

char* optimalDivision(int* nums, int numsSize)
{
    if (numsSize == 0)
        return "";

    int i, j;
    char* res = malloc(sizeof(char) * 100);

    float* vmin[numsSize];
    float* vmax[numsSize];
    char** smin[numsSize];
    char** smax[numsSize];

    for (i = 0; i < numsSize; i++) {
        vmin[i] = malloc(sizeof(float) * numsSize);
        vmax[i] = malloc(sizeof(float) * numsSize);
        smin[i] = malloc(sizeof(char*) * numsSize);
        smax[i] = malloc(sizeof(char*) * numsSize);

        memset(vmin[i], 0, sizeof(float) * numsSize);
        memset(vmax[i], 0, sizeof(float) * numsSize);
        memset(smin[i], 0, sizeof(char*) * numsSize);
        memset(smax[i], 0, sizeof(char*) * numsSize);
    }

    optimalSub(nums, vmin, vmax, smin, smax, 0, numsSize - 1);

    strcpy(res, smax[0][numsSize - 1]);

    // for (i = 0; i < numsSize; i++) {
    //     free(vmin[i]), free(vmax[i]);
    //     for (j = i; j < numsSize; j++)
    //         free(smin[i][j]), free(smax[i][j]);
    //     free(smin[i]), free(smax[i]);
    // }

    return res;
}

void optimalSub(int* nums, float** vmin, float** vmax, char*** smin, char*** smax, int f, int t)
{
    // Already computed
    if (vmin[f][t])
        return;

    // One number
    if (f == t) {
        vmin[f][t] = vmax[f][t] = nums[t] * 1.0;
        smin[f][t] = smax[f][t] = itoa(nums[t]);
        return;
    }

    int i, imin, imax;
    float vtmin, vtmax;
    char* stmin = malloc(sizeof(char) * 100);
    char* stmax = malloc(sizeof(char) * 100);

    for (i = imin = imax = f, vtmin = vtmax = 0; i < t; i++) {
        optimalSub(nums, vmin, vmax, smin, smax, f, i);
        optimalSub(nums, vmin, vmax, smin, smax, i + 1, t);

        if (vtmin == 0 || vtmin > vmin[f][i] / vmax[i + 1][t]) {
            vtmin = vmin[f][i] / vmax[i + 1][t];
            imin = i;
        }

        if (vtmax < vmax[f][i] / vmin[i + 1][t]) {
            vtmax = vmax[f][i] / vmin[i + 1][t];
            imax = i;
        }
    }

    vmin[f][t] = vtmin;

    strcat(stmin, smin[f][imin]);
    strcat(stmin, "/");
    // Add parenthesis if right part has more than one number
    if (imin < t - 1) strcat(stmin, "(");
    strcat(stmin, smax[imin + 1][t]);
    if (imin < t - 1) strcat(stmin, ")");
    smin[f][t] = stmin;

    vmax[f][t] = vtmax;

    strcat(stmax, smax[f][imax]);
    strcat(stmax, "/");
    // Add parenthesis if right part has more than one number
    if (imax < t - 1) strcat(stmax, "(");
    strcat(stmax, smin[imax + 1][t]);
    if (imax < t - 1) strcat(stmax, ")");
    smax[f][t] = stmax;

    return;
}

char* itoa(int n)
{
    // 4 digits plus null char
    char* s = malloc(sizeof(char) * 5);
    sprintf(s, "%d", n);
    return s;
}