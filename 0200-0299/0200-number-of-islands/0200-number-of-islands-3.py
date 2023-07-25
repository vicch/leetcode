"""
BFS instead of DFS. Note that the cell must be marked as visited when pushed to the queue, instead of when popped from
the queue, otherwise it can lead to duplication: same cell being pushed multiple times when BFS from its adjacent cells.
"""
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def bfs(i, j):
            cells = deque([(i, j)])
            visited[i][j] = True

            while cells:
                i, j = cells.popleft()
                for x, y in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    newi, newj = i + x, j + y
                    if 0 <= newi < m and 0 <= newj < n and not visited[newi][newj] and grid[newi][newj] == "1":
                        cells.append((newi, newj))
                        visited[newi][newj] = True

        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        islands = 0

        for i in range(m):
            for j in range(n):
                if not visited[i][j] and grid[i][j] == "1":
                    islands += 1
                    bfs(i, j)

        return islands
