"""
Dynamic programming by using each intermediate amount as key, and the currently minimum number of coins needed for that
amount as value.

For each amount from bottom up (outer loop), iterate the available coins (inner loop), as check if using the current
coin as the last coin to reach this amount is a better solution.

After each outer loop of amount n, cache[n] should have the optimal solution for this amount.
"""
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        # Init to a value larger than the largest possible number of coins (using only coins of 1 to get the amount).
        # Array is 0-indexed with 0 representing amount 0, so needs n+1 elements for amount n.
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if i >= coin:
                    # Improve solution if using current coin as last coin to reach this amount is better
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        # If cache[n] is the initial value, it means there is no solution
        return dp[amount] if dp[amount] < amount + 1 else -1
