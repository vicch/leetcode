"""
For each cell in the matrix, we can get its value range:
- Its min value is 0
- Its max value is min(rowSum[i], colSum[j]), because if it's larger, there will be at least one negative number on its
  row or column.

So for a greedy approach, we assume each cell has the max possible value that fulfills both the current row and column
sum. And by assigning this cell, the row and column sum are decremented accordingly for following cells.

As there's guaranteed to be one solution, the running row and column sums will never be negative.
"""
class Solution(object):
    def restoreMatrix(self, rowSum, colSum):
        """
        :type rowSum: List[int]
        :type colSum: List[int]
        :rtype: List[List[int]]
        """
        rows, cols = len(rowSum), len(colSum)
        matrix = [[0] * cols for _ in range(rows)]

        for i in range(rows):
            for j in range(cols):
                # Max possible value for this cell
                val = min(rowSum[i], colSum[j])
                matrix[i][j] = val
                rowSum[i] -= val
                colSum[j] -= val

        return matrix
