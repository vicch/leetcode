"""
The water volume between 2 indexes i and j is: min(height[i], height[j]) * (j - i)

When traversing the array, the value changes of the heights are uncertain, but value changes of the distances between
the indexes are clear: the 2 indexes at both ends of the array has the largest distance, and it decreases as they move
towards the center.

So the indexes at both ends can be considered as local optimal solution to begin with, then move them towards the
center to look for better solutions. Each time the index with smaller height (between the 2 indexes before the move)
should move, because moving the one with larger height would never result in a better solution, as
min(height[i], height[j]) only increases when the smaller value increases.
"""
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height) - 1
        area = 0
        while l < r:
            area = max(area, min(height[l], height[r]) * (r - l))
            # Move the pointer with smaller height
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return area

s = Solution()
print(s.maxArea([1,8,6,2,5,4,8,3,7]))
