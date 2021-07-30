"""
Basic approach is binary search.

At any time, if left > right, then the "breaking point" (i.e. the min number) must be within between left and right
bounds. And to determine which half to narrow down, compare the mid and the left element:

If left > mid, then it's like [5, 6, 0, 1, 2, 3, 4] where mid is 1, then it should narrow down to left half.
If left < mid, then it's like [2, 3, 4, 5, 6, 0, 1] where mid is 5, then it should narrow down to right half.

If left < right, then the numbers between left and right are properly sorted, and left number is the min.
"""
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums) - 1

        while l < r and nums[l] > nums[r]:
            m = (l + r) // 2
            if nums[l] > nums[m]:
                r = m
            else:
                l = m + 1

        return nums[l]
