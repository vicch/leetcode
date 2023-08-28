"""
It's a 2-phase binary search:
- Find the row by binary search of the lower bound on the first column.
- Find the column by binary search of exact match on the row.

The tricky part is the boundary conditions, esp. for the 1st phase of finding lower bound.

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
        l, r = 0, len(matrix) - 1
        # Stop searching when left and right touches.
        while l < r:
            m = (l + r) // 2
            if matrix[m][0] == target:
                return True
            if matrix[m][0] > target:
                r = m - 1
            else:
                l = m + 1
        
        # There are only several cases when it reaches here:
        # - The last step was a "r = m - 1" or "l = m + 1"
        # - The current condition is either "l == r" or "l > r"
        # Hand check each of these cases, and figure out the lower bound, but basically it depends on left pointer.
        x = (l - 1) if (matrix[l][0] > target) else l

        l, r = 0, len(matrix[0]) - 1
        while l <= r:
            m = (l + r) // 2
            if matrix[x][m] == target:
                return True
            if matrix[x][m] > target:
                r = m - 1
            else:
                l = m + 1
        
        return False
