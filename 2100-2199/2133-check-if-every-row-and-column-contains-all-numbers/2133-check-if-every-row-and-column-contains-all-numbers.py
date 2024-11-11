"""
This is essentially iterating the rows and columns of the matrix, and check if the collection of numbers is equal to a predefined set.

Time complexity:
- O(N^2), for visiting all numbers in the matrix.

Space complexity:
- O(N), for the number sets.
"""
class Solution(object):
    def checkValid(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        n = len(matrix)
        values = set(range(1, n + 1))
        
        for row in matrix:
            if set(row) != values:
                return False
        
        for i in range(n):
            if set([row[i] for row in matrix]) != values:
                return False
        
        return True
