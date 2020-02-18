"""
Problem:
Given a matrix of M x N elements (M rows, N columns), return all elements of
the matrix in diagonal order.

Example:
Input: [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
Output: [1, 2, 4, 7, 5, 3, 6, 8, 9]

Solution:
On each run, x + y is a fixed value. Outter loop increments this value, and
inner loop increment or decrement x within the matrix boundary.
"""

class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []

        row = len(matrix)
        col = len(matrix[0])
        dir = 1
        ret = []

        for i in range(row + col - 1):
            if dir == 1:
                for x in range(min(row - 1, i), max(-1, i - col), -1):
                    ret.append(matrix[x][i - x])
            else:
                for x in range(max(0, i - col + 1), min(i + 1, row)):
                    ret.append(matrix[x][i - x])
            dir = -dir

        return ret