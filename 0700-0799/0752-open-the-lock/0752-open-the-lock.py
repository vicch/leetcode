"""
This can be considered as a "shortest path" problem in a n-dimensional matrix. Each move of the lock's combination is
one step forward/back on one dimension. And the deadends are basically obstacle cells.

As the wheels can rotate, there is guaranteed to be a solution unless the detination or the starting cell is surrounded
by deadends.

Naturally it can be solved with BFS starting from the destination, by visiting unvisited adjacent cells in each cycle,
while incrementing the steps count indicating the steps needed to reach the destination from the current queue of cells.

When the starting cell is reached, the current steps count is the shortest path.

One optimization is that we don't need to memorize the shortest step (to the destination) per cell in a matrix, instead
we just need to mark them as visited in a set.

The coordinate strings can be converted to integer tuples for numerical operations such as incr/decr and rotate when
passing boundaries.
"""
class Solution(object):
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        # Convert "1234" to (1, 2, 3, 4)
        def digits(str):
            return tuple([ord(s) - ord('0') for s in str])

        def incr(n):
            if n == 9:
                return 0
            return n + 1

        def decr(n):
            if n == 0:
                return 9
            return n - 1

        # Increment only the n-th dimension of given cell by 1
        def incrDim(dims, n):
            new = dims[:n] + (incr(dims[n]), ) + dims[n+1:]
            return new

        # Decrement only the n-th dimension of given cell by 1
        def decrDim(dims, n):
            new = dims[:n] + (decr(dims[n]), ) + dims[n+1:]
            return new

        # Enumerate adjacent cells of given cell
        def adjacents(dims):
            return [
                incrDim(dims, 0), incrDim(dims, 1), incrDim(dims, 2), incrDim(dims, 3),
                decrDim(dims, 0), decrDim(dims, 1), decrDim(dims, 2), decrDim(dims, 3)
            ]

        # Deadends are marked as visited
        visited = set([digits(d) for d in deadends])

        queue = deque([digits(target)])
        step = 0

        while queue:
            # Iterate current layer of cells
            for _ in range(len(queue)):
                cell = queue.popleft()
                # Reached starting point
                if cell == (0, 0, 0, 0):
                    return step
                for adjacent in adjacents(cell):
                    if adjacent in visited:
                        continue
                    visited.add(adjacent)
                    queue.append(adjacent)
            step += 1

        return -1
