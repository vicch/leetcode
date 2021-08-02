"""
For each cell that is 0, its row and column need to be set to 0. The rows and columns can be recorded on 1st traversal,
then iterate the rows and columns and set their cells to 0.
"""
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        # The rows and cols that need to be set to 0
        rows, cols = [], []

        for i in range(m):
            for j in range(n):
                # If any cell is 0, its row and col need to be set to 0
                if matrix[i][j] == 0:
                    rows.append(i)
                    cols.append(j)

        # Dedup
        rows, cols = set(rows), set(cols)

        for r in rows:
            for j in range(n):
                matrix[r][j] = 0

        for c in cols:
            for i in range(m):
                matrix[i][c] = 0

        return matrix
