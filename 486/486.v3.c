// Problem:
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
// Think of each player's real score as "his total score - his opponent's total
// score", therefore their real scores are always x and -x, and the one with the
// positive real score wins. (Player 1 can win when his real score is 0.)
// And the strategy changes from "each player plays to maximize his score" to
// "each player plays to get more score than his opponent (and prefers to take
// from the head of the remaining scores)". So if he can win by taking from the
// head, do not check if he wins by taking from the tail any more. It saves
// running time.

#include <stdio.h>
#include <stdlib.h>

#define bool int

bool PredictTheWinner(int* nums, int numsSize);
bool canWin(int* nums, int size, int score, bool isplayer1);

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
    return canWin(nums, numsSize, 0, 1);
}

int canWin(int* nums, int size, int score, bool isplayer1)
{
    if (size == 0)
        return (isplayer1) ? score >= 0 : score > 0;
    else
        return !canWin(nums + 1, size - 1, -(score + nums[0]), !isplayer1) || !canWin(nums, size - 1, -(score + nums[size - 1]), !isplayer1);
}