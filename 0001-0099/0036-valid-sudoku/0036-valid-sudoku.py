"""
Iterate and validate each row, column and square.

Trick of checking duplicate in list: compare the list's length, and length of the set created from the list.
"""
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        def isValidSet(nums):
            vals = [n for n in nums if n != '.']
            return len(vals) == len(set(vals))

        for i in range(9):
            if not isValidSet(board[i]):
                return False
            if not isValidSet([col[i] for col in board]):
                return False

        for i in (0, 3, 6):
            for j in (0, 3, 6):
                nums = [board[x][y] for x in range(i, i + 3) for y in range(j, j + 3)]
                if not isValidSet(nums):
                    return False

        return True
