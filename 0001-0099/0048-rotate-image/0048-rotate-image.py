"""
Each layer of the matrix can be split into 4 parts:

X X X X O
O       O
O       O
O       O
O X X X X

And the rotation is rotate the cells of each part into the corresponding cells of the next part.

With an outer loop for each layer, and inner loop for each cell (1 out of 4 cells in each part) in that layer, the
coordinates of the corresponding cells can be obtained.
"""
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        
        for i in range(n // 2 + 1):
            for j in range(i, n-i-1):
                matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1], matrix[n-j-1][i] = matrix[n-j-1][i], matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1]
