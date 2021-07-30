"""
Similar to #153, use left/mid/right values and the target value to determine which half to narrow down to.
"""
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l, r = 0, len(nums) - 1

        while l <= r:
            m = (l + r) // 2

            if nums[m] == target:
                return m
            elif (nums[m] >= nums[l] and nums[l] <= target < nums[m]) or \
                 (nums[m] < nums[l] and not (nums[m] < target <= nums[r])):
                r = m - 1
            else:
                l = m + 1

        return -1
