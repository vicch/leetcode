"""
Typical matrix search problem. The difference is the way of movement: instead of moving to adjacent cell, it rolls in
one direction until hitting a wall or boundary. So the transition is to find the stop when rolling in one direction.
Then with a standard vistied cache and BFS, move till there is no more new cells to visit or the destination is reached.
"""
class Solution(object):
    def hasPath(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: bool
        """
        def roll(x, y, dx, dy, m, n):
            # Roll in given direction till hitting the boundry or a wall.
            while 0 <= x + dx < m and 0 <= y + dy < n and maze[x + dx][y + dy] == 0:
                x += dx
                y += dy
            return x, y

        m, n = len(maze), len(maze[0])
        visited = [[0] * n for _ in range(m)]

        queue = [start]
        visited[start[0]][start[1]] = 1

        while len(queue) > 0:
            x1, y1 = queue.pop()
            for dx, dy in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                x2, y2 = roll(x1, y1, dx, dy, m, n)
                # Reaching a visited cell, no need to explore again.
                if visited[x2][y2]:
                    continue
                if [x2, y2] == destination:
                    return True
                queue.append([x2, y2])
                visited[x2][y2] = 1

        return False
