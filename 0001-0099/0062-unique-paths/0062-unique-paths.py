"""
Consider 2-dimensional DP, and DP[i][j] stores the different ways to reach the cell. Then for each cell:

- If it can move to the cell below it, then the ways to move that cell (i.e. DP[i+1][j]) is incremented by DP[i][j].
- Same goes for the cell to the right side of it.

Build the DP array from bottom up, starting with top left cell and iterate till bottom right. The last value in DP array
is the ways to get to the last cell.
"""
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1

        for i in range(m):
            for j in range(n):
                # If can still move down
                if i < m-1:
                    dp[i+1][j] += dp[i][j]
                # If can still move right
                if j < n-1:
                    dp[i][j+1] += dp[i][j]

        return dp[-1][-1]
