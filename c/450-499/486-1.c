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
// Solution 1:
// Use a binary tree to represent all possible paths of choices, the goal of
// each player is to follow the path which maximizes his score in the end.
// And each player's choice may cause the other player to re-calculate how he
// could win, given previous choices.
// Each node contains:
// - score:  score being chosen
// - player: player who chooses this score
// - next:   next player's choice (left or right) to maximize his score
// 
// Solution 2:
// Don't store each step's data with tree, instead, use a recursive function
// to get the max scores current player can get when he chooses to take head or
// tail of the remaining scores. The bigger one will be his choice.

#include <stdio.h>
#include <stdlib.h>

#define bool int

bool PredictTheWinner(int* nums, int numsSize);
void getResult(int score, int player, int* nums, int size, int score1, int score2, int* max1, int* max2);

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
    int max1, max2;
    // Pretend player 2 chooses a first score of 0
    getResult(0, 2, nums, numsSize, 0, 0, &max1, &max2);
    return max1 >= max2;
}

void getResult(int score, int player, int* nums, int size, int score1, int score2, int* max1, int* max2)
{
    if (player == 1)
        score1 += score;
    else
        score2 += score;

    // Last one
    if (size == 0) {
        *max1 = score1;
        *max2 = score2;

    } else {
        int max1head, max2head, max1tail, max2tail;

        // Current choice is player 1's
        if (player == 1) {
            // If player 2 chooses head nextly
            getResult(nums[0], 2, nums+1, size-1, score1, score2, &max1head, &max2head);
            // If player 2 chooses tail nextly
            getResult(nums[size-1], 2, nums, size-1, score1, score2, &max1tail, &max2tail);
            // Max scores when player 2 chooses head or tail
            *max1 = (max2head > max2tail) ? max1head : max1tail;
            *max2 = (max2head > max2tail) ? max2head : max2tail;

        // Current choice is player 2's
        } else {
            // If player 1 chooses head nextly
            getResult(nums[0], 1, nums+1, size-1, score1, score2, &max1head, &max2head);
            // If player 1 chooses tail nextly
            getResult(nums[size-1], 1, nums, size-1, score1, score2, &max1tail, &max2tail);
            // Max scores when player 2 chooses head or tail
            *max1 = (max1head > max1tail) ? max1head : max1tail;
            *max2 = (max1head > max1tail) ? max2head : max2tail;
        }
    }

    return;
}