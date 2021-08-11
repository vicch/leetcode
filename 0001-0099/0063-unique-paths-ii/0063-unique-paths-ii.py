"""
Similar to #62 Unique Paths, just check for obstacle cells and skip counting paths that pass through them.
"""

class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        # If start and end cells are obstacles, there is 0 path
        if obstacleGrid[0][0] or obstacleGrid[-1][-1]:
            return 0

        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1

        for i in range(m):
            for j in range(n):
                # If current cell is obstable, skip
                if obstacleGrid[i][j]:
                    continue
                # Update method to reach cell below (no need to check obstacle, which is skipped when reaching tha
                # cell anyway)
                if i < m-1:
                    dp[i+1][j] += dp[i][j]
                # Update method to reach cell on the right
                if j < n-1:
                    dp[i][j+1] += dp[i][j]

        return dp[-1][-1]
