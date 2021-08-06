"""
If one cell can flow to the ocean, all its adjacent cells with higher or same heights can flow to the ocean. So by
visit the cells that can flow to the ocean and recursively their adjacent oceans, we can find all cells that can flow
one ocean.

Note that even if one adjacent cell cannot flow to current cell, it doesn't mean that cell cannot have another path to
flow into the ocean, so we should only positively mark cells as flowable to the ocean, and leave the currently
unflowable cells as unvisited, and visit them again from other adjacent cells. There won't be deadlock because if one
cell is currently unflowable, the visit will stop and won't continue to its adjacent cells.

By keeping 2 matrix to mark cells that can flow to one of the oceans, and compare the matrix to collect the cells that
can flow to both, we can get the result.
"""
class Solution(object):
    def pacificAtlantic(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(heights), len(heights[0])

        # Matrix to mark each cell as flowable to either of the 2 oceans
        m1 = [[None] * n for _ in range(m)]
        m2 = [[None] * n for _ in range(m)]

        # DFE visit a cell and check if it can flow to the given ocean
        def visit(matrix, i, j, height):
            if i < 0 or i >= m or j < 0 or j >=n:
                return
            # If already visited, or this cell cannot flow to the upper level cell, stop here
            if matrix[i][j] is not None or heights[i][j] < height:
                return

            # This cell can flow to the given ocean
            matrix[i][j] = 1
            # Check if its adjacent cells can flow to this cell, i.e. can eventually flow to the same ocean
            visit(matrix, i-1, j, heights[i][j])
            visit(matrix, i+1, j, heights[i][j])
            visit(matrix, i, j-1, heights[i][j])
            visit(matrix, i, j+1, heights[i][j])

        # Visit left and right borders
        for i in range(m):
            visit(m1, i, 0, 0)
            visit(m2, i, n-1, 0)

        # Visit top and bottom borders
        for i in range(n):
            visit(m1, 0, i, 0)
            visit(m2, m-1, i, 0)

        # Collect cells that can flow to both oceans
        cells = []
        for i in range(m):
            for j in range(n):
                if m1[i][j] == 1 and m2[i][j] == 1:
                    cells.append([i, j])

        return cells
