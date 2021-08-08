"""
The max profit that is achievable equals to the sum of all increments between the adjacent prices. And since there is no
limit of transactions, the strategy to get max profit is just buy and sell every time the price goes up.
"""

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0

        for i in range(len(prices) - 1):
            # Buy and sell for every increasing pair
            if prices[i] < prices[i+1]:
                profit += prices[i+1] - prices[i]

        return profit
