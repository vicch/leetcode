"""
Just keep a running value of current global max height while iterating the heights from right to left, and select any
index that has a higher height.

Time: O(n)
Space: O(1), not counting the return value
"""
class Solution(object):
    def findBuildings(self, heights):
        """
        :type heights: List[int]
        :rtype: List[int]
        """
        highest = float('-inf')
        selected = []

        for i in range(len(heights) - 1, -1, -1):
            if heights[i] > highest:
                highest = heights[i]
                selected.append(i)

        return reversed(selected)
