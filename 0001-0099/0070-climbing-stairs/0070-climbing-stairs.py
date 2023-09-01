"""
For each step n, the method to climb to it f(n) = f(n-2) + f(n-1). So it's basically calculating the nth number in
Fibonacci sequence. For a bottom-up approach, keep 2 vars for f(n-2) and f(n-1) and calculate f(n), then swap and
continue.

Time: O(n)
Space: O(1)
"""
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        a, b = 1, 1
        for _ in range(n - 1):
            a, b = b, a + b
        return b
