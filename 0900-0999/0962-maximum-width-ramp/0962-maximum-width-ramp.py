"""
[NEED_REVIEW]

The problem is essentially finding the max(j - i) where nums[i] <= nums[j].

This can be thought as a DP problem. Assuming we have found the local optimal for j1 == len(nums)-1, which is (i1, j1), if there is a better
solution (i2, j2), then there must be:

- j2 < j1, because j1 is at the end already
- i2 < i1, because otherwise j - i will be smaller
- nums[i2] > nums[i1], because otherwise the optimal for j1 would be (i2, j1)
- nums[j2] > nums[i1], because nums[j2] >= nums[i2] > nums[i1]

So we can use a monotonic stack to store all potential i index from the left, then by moving j pointer from right to left, look for the local
optimal for each j by popping the i index from the stack.

Time complexity:
- O(N), for iterating the array to build stack, and iterating the array from right to left, the stack will be iterated once in the second step.

Space complexity:
- O(N), for the stack.
"""
class Solution(object):
    def maxWidthRamp(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stack = [0]
        for i in range(1, len(nums)):
            if nums[i] < nums[stack[-1]]:
                stack.append(i)

        maxWidth = 0
        for j in range(len(nums)-1, -1, -1):
            while stack and nums[stack[-1]] <= nums[j]:
                i = stack.pop()
                maxWidth = max(maxWidth, j - i)

        return maxWidth
