"""
At first it seems a typical DFS problem: starting from each gate cell and progressively mark the adjacent cells with
incrementing distance. For searches that start from other gates, stop the search when a smaller distance is met.

Actually it's simpler as BFS: pushing all gate cells to the queue first, then pop cells from the queue and mark its
adjacent cells (that are not walls and not marked yet) with distance that is +1 of current cell's distance, and
continue. If one cell is closer to another gate, it must have been visited and marked already.

Time: O(mn), each cell is visted at most once.
Space: O(mn), for the queue.
"""
class Solution(object):
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: None Do not return anything, modify rooms in-place instead.
        """
        m, n = len(rooms), len(rooms[0])

        # Another option is to use a list per BFS iteration, then swap to another list at the end.
        queue = collections.deque([])

        # Init queue with gate cells.
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    queue.append([i, j])

        while queue:
            x, y = queue.popleft()
    
            for dx, dy in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                x2, y2 = x + dx, y + dy
                # If adjacent cell is within bound and is an un-visited room, update its distance and visit it nextly.
                if 0 <= x2 < m and 0 <= y2 < n and rooms[x2][y2] == 2147483647:
                    rooms[x2][y2] = rooms[x][y] + 1
                    queue.append([x2, y2])
        
        return rooms
