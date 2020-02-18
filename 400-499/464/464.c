// Problem:
// With a pool of integers from 1 to N, 2 players take turns to draw from it.
// The first player whose total is >= M wins. Each integer can only be drew
// once. Given N and M, determin if player 1 can find a strategy that guarantees
// to win.
// 
// Example:
// N = 10, M = 11. No matter which number player 1 draws, player 2 will win.
// 
// Solution:
// Consider all possibles situations as a decision tree.
// - For a node representing player 1's turn (the initial node), it's a "win"
//   for player 1 when player 1 wins (target reached) at this node, or all its
//   sub-nodes (player 2's turn) are "win" for player 1.
// - For a node representing player 2's turn, it's a "win" for player 1 when
//   player 2 does not win (target not reached) at this node, and any of the
//   sub-nodes (player 1's turn) is "win" for player 1.

#include <stdio.h>
#include <string.h>

typedef int bool;

bool canIWin(int maxChoosableInteger, int desiredTotal);

int main()
{
    printf("%d\n", canIWin(10, 11));

    return 0;
}

bool canIWinSub(int max, int target, unsigned int pool, int score, bool player1Turn);

int cache[1048577]; // 2^20 + 1

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
        return 0;

    // Init pool as bit map with "1s on the right marking the numbers not taken
    unsigned int pool = (1 << maxChoosableInteger) - 1;

    // Init cache as -1 (all "1" bits)
    memset(cache, -1, sizeof(cache));

    return canIWinSub(maxChoosableInteger, desiredTotal, pool, 0, 1);
}

bool canIWinSub(int max, int target, unsigned int pool, int score, bool player1Turn)
{
    if (cache[pool] != -1)
        return cache[pool];

    int i;

    for (i = max; i >= 1; i--)
        // If number not taken yet
        if (pool & (1 << (i - 1)))
            if (score + i >= target || canIWinSub(max, target, pool ^ (1 << (i - 1)), score + i, !player1Turn) == player1Turn) {
                return cache[pool] = player1Turn;
            }
            
    return cache[pool] = !player1Turn;

    /* The above code is a simplied yet confusing version of code below */

    // // Player 1's turn
    // if (player1Turn) {
    //     for (i = max; i >= 1; i--) {
    //         // If number not taken yet
    //         if (1 << (i - 1) & pool) {
    //             // If any sub-node wins, it's a "win"
    //             if (score + i >= target || canIWinSub(max, target, pool ^ (1 << (i - 1)), score + i, 0))
    //                 return 1;
    //         }
    //     }
    //     return 0;
    // // Player 2's turn
    // } else {
    //     for (i = max; i >= 1; i--) {
    //         // If number not taken yet
    //         if (1 << (i - 1) & pool) {
    //             // If any sub-node wins, it's not a "win"
    //             if (score + i >= target || !canIWinSub(max, target, pool ^ (1 << (i - 1)), score + i, 1))
    //                 return 0;
    //         }
    //     }
    //     return 1;
    // }
}