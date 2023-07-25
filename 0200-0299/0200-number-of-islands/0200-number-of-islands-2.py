"""
Adjusted DFS approach, using tuples for DFS direction etc.
"""
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or visited[i][j] or grid[i][j] == "0":
                return

            visited[i][j] = True
            
            for x, y in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                dfs(i + x, j + y)

        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        islands = 0

        for i in range(m):
            for j in range(n):
                if not visited[i][j] and grid[i][j] == "1":
                    islands += 1
                    dfs(i, j)

        return islands
