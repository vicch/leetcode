"""
A variation of the stair climbing problem. Define f(i) as the min cost of starting to climb from the ith stair, then
f(i) = min(f(i-1), f(i-2)) + cost[i]

By maintaining 2 vars to represent f(i-1) and f(i-2), for each stair, compute f(i) and then assign the vars to be f(i)
and f(i-1), and continue to compute f(i+1).

Time: O(n)
Space: O(1)
"""
class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        # Init the values, consider them as f(-1) and f(-2), which take no cost to start from.
        a, b = 0, 0
        for c in cost:
            a, b = b, min(a, b) + c
        return min(a, b)
