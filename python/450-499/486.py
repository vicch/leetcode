"""
Question:
Given an array of scores that are non-negative integers. Player 1 picks one
of the numbers from either end of the array followed by the player 2 and
then player 1 and so on. This continues until all the scores have been
chosen. The player with the maximum score wins. Given an array of scores,
predict whether player 1 is the winner. Assume each player plays to maximize
his score.

Example:
Input: [1, 5, 2]
Output: False
Initially, player 1 can choose between 1 and 2. If he chooses 2 (or 1), then
player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1
will be left with 1 (or 2). So, final score of player 1 is 1 + 2 = 3, and
player 2 is 5. Hence, player 1 will never be the winner.

Solution:
Think of each player's real score as "his total score - his opponent's total
score", therefore their real scores are always x and -x, and the one with the
positive real score wins. (Player 1 can win when his real score is 0.)
And the strategy changes from "each player plays to maximize his score" to
"each player plays to get more score than his opponent (and prefers to take
from the head of the remaining scores)". So if he can win by taking from the
head, do not check if he wins by taking from the tail any more. It saves
running time.
"""

class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return self.canWin(nums, 0, True)

    def canWin(self, nums, score, isplayer1):
        if len(nums) == 0:
            return (score >= 0) if isplayer1 else (score > 0)
        else:
            return (not self.canWin(nums[1:], -(score + nums[0]), not isplayer1)) or (not self.canWin(nums[:-1], -(score + nums[-1]), not isplayer1))