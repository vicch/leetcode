"""
A more straightforward comparison: for any cell (x, y) that is not on the first row or column, check if its value is
equal to (x-1, y-1).

Time: O(mn)
Space: O(1)
"""
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][j] != matrix[i-1][j-1]:
                    return False
        return True
