"""
Typical matrix traversal and shortest path problem. By BFS starting from the initially rotten oranges, each cycle can
represent one minute of rotting spread. When there is no more reachable fresh orange to visit, check if there is any
remaining fresh orange, via a counter that is initialized as total oranges and decremented per cell visit.

Time complexity:
- O(N), for visiting all cells once.

Space complexity:
- O(N), for BFS and visited set.
"""
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows, cols = len(grid), len(grid[0])

        total = 0
        bfs = []

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    total += 1
                    bfs.append((i, j))
                elif grid[i][j] == 1:
                    total += 1

        if total == 0:
            return 0

        # Offset the initial increment of minutes on first cycle
        minutes = -1
        visited = set()

        while bfs:
            minutes += 1
            nextBfs = []

            for i, j in bfs:
                # Out of boundary
                if i < 0 or j < 0 or i >= rows or j >= cols:
                    continue

                # Already visited (rotten) or empty
                if (i, j) in visited or grid[i][j] == 0:
                    continue

                # Visit and add adjacent cells to visit
                visited.add((i, j))
                nextBfs.extend([(i-1, j), (i+1, j), (i, j-1), (i, j+1)])

            bfs = nextBfs

        # The last cycle is empty or invalid, so offset minutes by 1 again.
        return minutes-1 if total == len(visited) else -1
