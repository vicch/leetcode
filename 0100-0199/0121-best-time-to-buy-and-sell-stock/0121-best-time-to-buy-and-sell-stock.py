"""
Not a typical DP problem, but basically the best profit if selling at a particular point is price[n] - min(price[0:n]).
With this local optimal, maintain a global optimal, which is the answer in the end.
"""
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min_price, max_profit = float("inf"), 0
        for p in prices:
        	# Update the min price in history
            min_price = min(min_price, p)
            # Check if selling now (and assuming bought at the min price in history) beats the max profit in history
            max_profit = max(max_profit, p - min_price)
        return max_profit
