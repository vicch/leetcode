"""
Define f(n) as the number of odd numbers between 0 and n (inclusive), then the problem is equivalent to
f(high) - f(low - 1).

For f(n), just consider the cases when n is odd and even, basically f(n) = floor((n + 1) / 2).
"""
class Solution(object):
    def countOdds(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        return int((high + 1) / 2) - int(low / 2)
