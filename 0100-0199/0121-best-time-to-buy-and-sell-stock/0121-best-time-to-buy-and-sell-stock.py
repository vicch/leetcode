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
