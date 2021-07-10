"""
Problem:
Given an 2D board, count how many battleships are in it. The battleships are
represented with "X", empty slots are represented with ".". Rules:
- Input is a valid board, made of only battleships or empty slots.
- Battleships can only be placed horizontally or vertically.
- Battleships can be of any size
- At least one horizontal or vertical cell separates between two battleships.
Do it in one-pass, using only O(1) extra memory and without modifying the
value of the board.

Example:
X..X
...X
...X

Solution:
Count number of separate "X" groups in each row, ignoring slots where the
slot above it is also an "X".
"""

class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        state, count = 0, 0

        if not board:
            return count

        row = len(board)
        col = len(board[0])

        for i in range(row):
            for j in range(col):
                if board[i][j] == 'X':
                    if state == 0 and (i == 0 or board[i-1][j] == '.'):
                        count += 1
                    state = 1
                else:
                    state = 0
            state = 0

        return count
