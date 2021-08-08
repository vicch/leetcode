"""
Similar to #26 Remove Duplicates from Sorted Array, use 2 pointers to swap "wanted" values to the front. Difference is
the "unwanted" values need to be appended to the end as well. In this case, "unwanted" value is just 0, so just
populate 0 till the end of the given list.
"""

class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        l, r = 0, 0

        # Move non-zero values to front
        while r < len(nums):
            if nums[r] != 0:
                nums[l] = nums[r]
                l += 1
            r += 1

        # Overwrite remaining values with 0
        while l < len(nums):
            nums[l] = 0
            l += 1

        return nums