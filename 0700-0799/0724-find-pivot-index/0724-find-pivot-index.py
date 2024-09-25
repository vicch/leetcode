"""
As the numbers are random and can contain negative values, every number is potentially the pivot and has to be checked
in linear traversal.

The optimization is avoid calculating the sum before and after each candidate, but consider it as prefix sum: when
iterating to the next number, its prefix sum increment by the previous number, and its suffix sum decrement by current
number.
"""
class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prefix, suffix = 0, sum(nums)
        for i in range(len(nums)):
            suffix -= nums[i]
            if prefix == suffix:
                return i
            prefix += nums[i]
        return -1
