// Question:
// Given an array of scores that are non-negative integers. Player 1 picks one
// of the numbers from either end of the array followed by the player 2 and
// then player 1 and so on. This continues until all the scores have been
// chosen. The player with the maximum score wins. Given an array of scores,
// predict whether player 1 is the winner. Assume each player plays to maximize
// his score.
// 
// Example:
// Input: [1, 5, 2]
// Output: False
// Initially, player 1 can choose between 1 and 2. If he chooses 2 (or 1), then
// player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1
// will be left with 1 (or 2). So, final score of player 1 is 1 + 2 = 3, and
// player 2 is 5. Hence, player 1 will never be the winner.
// 
// Solution:
// For player 1 to win, he has to get more than what player 2 gets. Think from
// the prospective of one player, what he gains each time is a plus for him, and
// what the other player gains each time is a minus for him. Eventually if
// player 1 can have a >= 0 total, he wins.

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool PredictTheWinner(int* nums, int numsSize);
int getResult(int* nums, int size);

int main()
{
    int s1[] = {1, 5, 2};
    printf("%d\n", PredictTheWinner(s1, 3));

    int s2[] = {1, 5, 233, 7};
    printf("%d\n", PredictTheWinner(s2, 4));

    int s3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    printf("%d\n", PredictTheWinner(s3, 9));

    int s4[] = {1, 7, 9, 2, 10, 4, 2, 1, 5, 4, 5};
    printf("%d\n", PredictTheWinner(s4, 11));

    return 0;
}

bool PredictTheWinner(int* nums, int numsSize)
{
    return getResult(nums, numsSize) >= 0;
}

int getResult(int* nums, int size)
{
    if (size == 1)
        return nums[0];
    else {
        int head = nums[0] - getResult(nums+1, size-1);
        int tail = nums[size-1] - getResult(nums, size-1);
        return MAX(head, tail);
    }
}