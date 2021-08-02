"""
The process is basically: for any cell, if its content matches the current letter (starting with the 1st letter) of the
word, then recursively check if any of its adjacent cells contain the next letter. Continue till the end of the word
for a solution.

Because cells cannot be revisited to spell the word, the currently visited cells need to be memorized, either in-place
with a special value, or via a separate array. After exploring the potential solutions starting from one cell, it needs
to be reset to unvisisted before returning.
"""
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m, n = len(board), len(board[0])
        # Memo array to track visited cells, true means visited
        visited = [[False] * n for _ in range(m)]
        
        def backtrack(offset, i, j):
            # If end of the word is reached, return success
            if offset == len(word):
                return True
            # If coord is out of bound, or current cell was visited, or current cell doesn't contain the letter at
            # current offset, return failure
            if i < 0 or i >= m or j < 0 or j >= n or visited[i][j] or board[i][j] != word[offset]:
                return False

            # Mark current cell as visited
            visited[i][j] = True
            # Backtrack the next letter in 4 directions
            if backtrack(offset+1, i-1, j) or backtrack(offset+1, i+1, j) or backtrack(offset+1, i, j-1) or backtrack(offset+1, i, j+1):
                return True

            # Unmark current cell as visited
            visited[i][j] = False
            return False

        for i in range(m):
            for j in range(n):
                # Start from each cell to find the word, return success if any solution is found
                if backtrack(0, i, j):
                    return True
        
        return False
