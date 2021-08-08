"""
Land cells that are adjacent can only count as one island. So every time a new land cell is met, all adjacent land
cells of it should be visited recursively (DFS), and memorized, so they won't count as another island later.

In outer loop, visited all cells and look for unvisited land cells, count them as islands, then visit adjacent cells
as mentioned above.
"""
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        # Matrix to memorize cells as visited
        visited = [[False] * n for _ in range(m)]
        islands = 0

        def visit(i, j):
            if i < 0 or i >= m or j < 0 or j >=n or visited[i][j]:
                return

            visited[i][j] = True

            # Continue visiting if the island extends to this cell
            if grid[i][j] == "1":
                visit(i+1, j)
                visit(i-1, j)
                visit(i, j+1)
                visit(i, j-1)

        for i in range(m):
            for j in range(n):
                # If this cell isn't visited yet, and it's land, it's a new island
                if not visited[i][j] and grid[i][j] == "1":
                    islands += 1
                    # Visit all adjacent land cells
                    visit(i, j)

        return islands
