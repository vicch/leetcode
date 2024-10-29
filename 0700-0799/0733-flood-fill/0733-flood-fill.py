"""
Typical matrix traversal problem. Can be either DFS or BFS. For each cell being visited, if it matches original color,
the traversal can continue to its adjacent cells.

Time complexity:
- O(N), for visiting each cell once.

Space complexity:
- O(N), for the visited and BFS data.
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

        visited = set()
        bfs = [(sr, sc)]

        while bfs:
            nextBfs = []
            for x, y in bfs:
                # Check boundary
                if x < 0 or y < 0 or x >= rows or y >= cols:
                    continue

                if (x, y) in visited:
                    continue
                visited.add((x, y))

                # Fill color
                if image[x][y] != origColor:
                    continue
                image[x][y] = color

                nextBfs.extend([(x-1, y), (x, y-1), (x+1, y), (x, y+1)])

            bfs = nextBfs

        return image
