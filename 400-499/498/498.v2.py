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
Annotate the matrix entries with coordinate information and sort.
"""

class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        entries = [
            (i+j, (j, i)[(i^j)&1], val)
            for i, row in enumerate(matrix)
            for j, val in enumerate(row)
        ]
        
        return [e[2] for e in sorted(entries)]