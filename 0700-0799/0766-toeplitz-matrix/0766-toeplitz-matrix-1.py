"""
Simply check the diagnols one by one, with the top-left cell's value as target.

Time: O(mn)
Space: O(1)
"""
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        height, width = len(matrix), len(matrix[0])

        # Check diagnols starting on first column.
        for i in range(height):
            val = matrix[i][0]
            for di in range(1, min(height - i, width)):
                if matrix[i+di][di] != val:
                    return False

        # Check diagnols starting on first row.
        for i in range(1, width):
            val = matrix[0][i]
            for di in range(1, min(height, width - i)):
                if matrix[di][i+di] != val:
                    return False

        return True
