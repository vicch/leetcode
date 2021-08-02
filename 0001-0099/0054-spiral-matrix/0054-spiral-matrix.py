"""
Consider the spiral path as "peeling" the matrix by layers:

X X X X X X
O . . . . O
O . . . . O
X X X X X X

X and O are borders of the 1st layer, then it continues to the next layer.

Use 4 variables to maintain the 4 borders for clarity. It should always be: top < bottom, left < right. If the borders
overlap, the last layer is reached.
"""
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        nums = []
        m, n = len(matrix), len(matrix[0])
        # Borders: top, bottom, left, right
        t, b, l, r = 0, m-1, 0, n-1

        while t <= b and l <= r:
            for j in range(l, r+1):
                nums.append(matrix[t][j])
            for i in range(t+1, b):
                nums.append(matrix[i][r])
            if t < b:
                for j in range(r, l-1, -1):
                    nums.append(matrix[b][j])
            if l < r:
                for i in range(b-1, t, -1):
                    nums.append(matrix[i][l])
            # Update borders to next layer
            t, b, l, r = t+1, b-1, l+1, r-1

        return nums
