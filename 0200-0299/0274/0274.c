// Problem:
// Given an array of citations (each citation is a non-negative integer) of a
// researcher, write a function to compute the researcher's h-index. The
// definition of h-index: A scientist has index h if h of his N papers have at
// least h citations each, and the other N − h papers have no more than h
// citations each.
// - If there are several possible values for h, the maximum one is taken as
// the h-index.
// 
// Example:
// Input: [3, 0, 6, 1, 5]
// Output: 3
// 
// Solution:
// Use an array to count the occurence of each citaion number. Iterating from
// the largest number backwards and keep the sum of citation numbers. When the
// sum is greater than the citation number, return the citation number.

#include <stdio.h>
#include <string.h>

int hIndex(int* citations, int citationsSize);

int main()
{
    return 0;
}

/********** Solution **********/

int hIndex(int* citations, int citationsSize)
{
    // Assume the largest citation is 999
    int nums[1000], max, sum, i;

    memset(nums, 0, sizeof(nums));

    for (i = max = 0; i < citationsSize; i++) {
        nums[citations[i]]++;
        if (max < citations[i])
            max = citations[i];
    }

    for (sum = 0, i = max; i >= 0; i--) {
        sum += nums[i];
        if (sum >= i)
            break;
    }

    return i;
}