"""
[NEED_REVIEW]

A typical DP problem, and for any amount, the number of ways f(n) = f(n - coins[0]) + f(n - coins[1]) + ...

So a bottom-up solution with DP memo can build up f(n) from 0 to the total amount.

The arrangement of loops is very important: as we want the number of combinations instead of permutations, i.e. same combination of coins in
different orders are considered the same solution, we have to iterate the coins in an outer loop to avoid duplication.

Also note that the order of coins in the input doesn't matter, because eventually f(n) will get the correct value regardless of the order of
accumulating the f(n - coins[m]) values.

Time complexity:
- O(NM), where N = amount, M = number of coins, because of the nested loops.

Space complexity:
- O(N), for the DP memo.
"""
class Solution(object):
    def change(self, amount, coins):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """
        dp = [0] * (amount + 1)

        # Bottom case, there is one way to get 0: no coin.
        dp[0] = 1
        
        for coin in coins:
            for target in range(coin, amount + 1):
                dp[target] += dp[target - coin]
        
        return dp[amount]
