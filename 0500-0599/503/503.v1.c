// Problem:
// Given a circular array, print the Next Greater Number for every element. The
// Next Greater Number of a number is the first greater number to its
// traversing-order next in the array. If it doesn't exist, output -1.
//
// Example:
// Input: [4, 1, 2, 5]
// Output: [5, 2, 5, -1]
//
// Solution:
// Just look for next greater number for each number, return to 0 when reaches
// the end.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* seq, int count);
int* nextGreaterElements(int* nums, int numsSize, int* returnSize);

int main()
{
    int s1[] = {4, 1, 2, 5};
    int rs1;
    printArray(nextGreaterElements(s1, 4, &rs1), 4);

    int s2[] = {5, 4, 3, 2, 1};
    int rs2;
    printArray(nextGreaterElements(s2, 5, &rs2), 5);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d", *seq++);
    printf("\n");
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
    int i, j;

    *returnSize = numsSize;
    int* elements = malloc(sizeof(int) * numsSize);

    // Init all as -1
    memset(elements, -1, sizeof(int) * numsSize);

    for (j = 0; j < numsSize; j++)
        // Start from next number, return to 0 when end is reached
        for (i = (j + 1) % numsSize; i != j; i += (i < numsSize - 1) ? 1 : -i)
            if (nums[i] > nums[j]) {
                elements[j] = nums[i];
                break;
            }

    return elements;
}