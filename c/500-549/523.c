// Problem:
// Given a list of non-negative numbers and a target integer k, write a
// function to check if the array has a continuous subarray of size at least 2
// that sums up to the multiple of k, that is, sums up to n*k where n is also
// an integer.
// 
// Example:
// Input: [23, 2, 4, 6, 7],  k=6
// Output: True, [2, 4] is a continuous subarray of size 2 and sums up to 6
// 
// Solution:
// Make a new array as new[i] = old[0] + ... + old[i]. If any 2 elements in new
// array new[m] % k == new[n] % k, then subarray old[m+1] to old[n] is the
// result.
// 
// Note:
// This cannot be solved in C without a hash table implementation, because k
// may be very large and it's impossible to simply use an array for the
// remainders.
// 
// Lesson:
// - Use sum[i] = arr[0] + ... arr[i] array for subarray sum problems.

#include <stdio.h>
#include <string.h>

typedef int bool;

bool checkSubarraySum(int* nums, int numsSize, int k);

int main()
{
    return 0;
}

/********** Solution **********/

bool checkSubarraySum(int* nums, int numsSize, int k)
{
    if (numsSize < 2)
        return 0;

    int i;

    for (i = 0; i < numsSize - 1; i++)
        if (nums[i] == 0 && nums[i + 1] == 0)
            return 1;

    if (k == 0)
        return 0;

    if (k < 0)
        k = -k;

    int remainder[k], sum;

    memset(remainder, 0, sizeof(remainder));
    remainder[0] = 1; // For the empty subarray at the beginning

    for (sum = i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (remainder[sum % k] == 1)
            return 1;
        else
            remainder[sum % k] = 1;
    }

    return 0;
}