"""
Each row consists of 2 parts:

- The middle numbers are calculated by adding up adjacent numbers of the last row.
- The leading and trailing 1s.
"""

class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        # Init first row
        rows = [[1]]

        for _ in range(numRows - 1):
            row = []

            # Populate the middle numbers based on last row
            for i in range(len(rows[-1])-1):
                row.append(rows[-1][i] + rows[-1][i+1])

            # Attach leading and trailing 1s
            rows.append([1] + row + [1])

        return rows
