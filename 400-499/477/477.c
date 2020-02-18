// Problem:
// The Hamming distance between two integers is the number of positions at
// which the corresponding bits are different. Write a function to find the
// total Hamming distance between all pairs of the given numbers.
// 
// Example:
// Input: 4, 14, 2
// Output: 6
// 
// Solution:
// Consider the same bit across all numbers as a collection, if there are n 1's
// and m 0's, then the total Hamming distance contributed by this bit is m x n.
// 
// Example:
// 0100
// 1110
// 0010
// - 1st bits are [0, 0, 0], 3 x 0 = 0
// - 2nd bits are [0, 1, 1], 1 x 2 = 2
// - 3rd bits are [1, 1, 0], 1 x 2 = 2
// - 4th bits are [0, 1, 0], 2 x 1 = 2

#include <stdio.h>

int totalHammingDistance(int* nums, int numsSize);

int main()
{
    return 0;
}

/********** Solution **********/

int totalHammingDistance(int* nums, int numsSize)
{
    int mask, one, total, i, j;

    for (i = total = 0, mask = 1; i < 31; i++, mask <<= 1) {
        for (j = one = 0; j < numsSize; j++) {
            if (nums[j] & mask) {
                one++;
            }
        }
        total += one * (numsSize - one);
    }

    return total;
}