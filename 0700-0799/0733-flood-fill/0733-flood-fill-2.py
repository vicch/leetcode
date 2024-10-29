"""
The DFS approach, is slightly simpler.
"""
class Solution(object):
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        rows, cols = len(image), len(image[0])
        origColor = image[sr][sc]

        # Return early
        if origColor == color:
            return image

        def dfs(r, c):
            if image[r][c] != origColor:
                return
            image[r][c] = color

            if r > 0:
                dfs(r - 1, c)
            if r < rows - 1:
                dfs(r + 1, c)
            if c > 0:
                dfs(r, c - 1)
            if c < cols - 1:
                dfs(r, c + 1)

        dfs(sr, sc)

        return image
