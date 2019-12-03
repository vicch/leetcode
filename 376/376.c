// Problem:
// A sequence of numbers is called a wiggle sequence if the differences between
// successive numbers strictly alternate between positive and negative. The
// first difference (if one exists) may be either positive or negative. A
// sequence with fewer than two elements is trivially a wiggle sequence.
// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
// (6,-3,5,-7,3) are alternately positive and negative. In contrast,
// [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its
// first two differences are positive and the second because its last
// difference is zero.
// Given a sequence of integers, return the length of the longest subsequence
// that is a wiggle sequence. A subsequence is obtained by deleting some number
// of elements (eventually, also zero) from the original sequence, leaving the
// remaining elements in their original order.
// 
// Example:
// Input: [1,17,5,10,13,15,10,5,16,8]
// Output: 7 (There are several subsequences that achieve this length. One is
// [1,17,10,13,10,16,8].)
// 
// Solution:
// Iterating the array, use a state variable to store last valid (that follows
// the wiggling pattern) difference's state (1 for positive, -1 for negative),
// and if current difference does not wiggle, continue to next.

#include <stdio.h>

int wiggleMaxLength(int* nums, int numsSize);

int main()
{
    return 0;
}

/********** Solution **********/

int wiggleMaxLength(int* nums, int numsSize)
{
    if (numsSize < 2)
        return numsSize;

    int i, len, last;

    for (i = len = 1, last = 0; i < numsSize; i++) {
        if (nums[i] > nums[i - 1])
            if (last == 1)
                ;
            else
                len++, last = 1;
        else if (nums[i] < nums[i - 1])
            if (last == -1)
                ;
            else
                len++, last = -1;
        else
            ;
    }

    return len;
}