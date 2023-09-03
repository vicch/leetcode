"""
The way to get each cell f(i, j) = f(i-1, j) + f(i, j-1), which is the DP transition function. At the start we know
f(0, n) and f(n, 0) are all 1s. Then the remaining cells can be popualated from top/left to bottom/right.

Time: O(mn)
Space: O(mn)
"""
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0] * n for _ in range(m)]

        for i in range(m):
            dp[i][0] = 1
        for i in range(n):
            dp[0][i] = 1
        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
                    
        return dp[m-1][n-1]
