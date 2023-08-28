"""
The sorted 2D matrix can be treated as a sorted 1D array, where each cell in the array can map to an offset, and vice
versa. So the problem can be converted to a binary search on array.

Time: O(logmn)
Space: O(1)
"""
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        rows, cols = len(matrix), len(matrix[0])
        
        l, r = 0, rows * cols - 1
        while l <= r:
            # Binary search on 1D array
            m = (l + r) // 2
            # Convert 1D offset to 2D coordinates
            x = m // cols
            y = m % cols

            if matrix[x][y] == target:
                return True
            if matrix[x][y] > target:
                r = m - 1
            else:
                l = m + 1
        
        return False
