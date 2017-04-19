// Problem:
// Given scores of N athletes, find their relative ranks and the people with
// the top three highest scores, who will be awarded medals: "Gold Medal",
// "Silver Medal" and "Bronze Medal".
// - N is a positive integer and won't exceed 10,000.
// - All the scores of athletes are guaranteed to be unique.
// 
// Example:
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// 
// Solution:
// Create an array whose keys are scores, values are indices of each score in
// the input array. Iterating the scores backwards, for each score with an
// index set, add its award string (indicated by a "rank" variable that
// increments).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** findRelativeRanks(int* nums, int numsSize, int* returnSize);

int main()
{
    return 0;
}

/********** Solution **********/

char* rankToString(int rank);

char** findRelativeRanks(int* nums, int numsSize, int* returnSize)
{
    int i, largest, rank;
    char** ranks;

    *returnSize = numsSize;
    ranks = malloc(sizeof(char*) * numsSize);

    // Get largest score
    for (i = largest = 0; i < numsSize; i++)
        if (nums[i] > largest)
            largest = nums[i];

    int scores[largest + 1];
    memset(scores, -1, sizeof(scores));

    for (i = 0; i < numsSize; i++)
        scores[nums[i]] = i;

    for (i = largest, rank = 1; i >= 0; i--)
        if (scores[i] != -1)
            ranks[scores[i]] = rankToString(rank++);

    return ranks;
}

char* rankToString(int rank)
{
    char* str;

    if (rank > 3) {
        int i;
        str = malloc(sizeof(char) * 6); // Longest is 10000
        str[5] = '\0';
        for (i = 4; rank > 0; i--, rank /= 10)
            str[i] = (rank % 10) + '0';
        str += i + 1;

    } else {
        str = malloc(sizeof(char) * 13);
        if (rank == 1)
            strcpy(str, "Gold Medal");
        else if (rank == 2)
            strcpy(str, "Silver Medal");
        else if (rank == 3)
            strcpy(str, "Bronze Medal");
    }

    return str;
}