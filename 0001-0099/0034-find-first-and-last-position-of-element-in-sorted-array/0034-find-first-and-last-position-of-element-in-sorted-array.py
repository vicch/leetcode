"""
Still binary search, but instead of finding the target value, it needs to be tweaked to find:

- The first number that is smaller than or equal to target
- The first number that is larger than target, which when minus 1, is the last number that is smaller than or equal to
target

If numbers at these index are equal to the target, return them, otherwise return [-1, -1] which means the target value
doesn't exist in array.
"""

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []

        l, r = 0, len(nums)-1
        while l <= r:
            m = (l + r) // 2
            # Moves left when current middle is larger than or equal to target, so it will find the first number that is
            # smaller than or equal to target
            if nums[m] >= target:
                r = m - 1
            else:
                l = m + 1

        # If it's equal to target, then it's valid, otherwise target doesn't exist in array
        result.append(l if l < len(nums) and nums[l] == target else -1)

        # The rest can be skipped if starting index is -1, because the number doesn't exist in array

        l, r = 0, len(nums)-1
        while l <= r:
            m = (l + r) // 2
            # Moves right when current middle is smaller than or equal to target, so it will find the first number that
            # is larger than target
            if nums[m] <= target:
                l = m + 1
            else:
                r = m - 1

        # Step back one number is the last number that is smaller than or equal to target
        # If it's equal to target, then it's valid, otherwise target doesn't exist in array
        result.append(l - 1 if l > 0 and nums[l - 1] == target else -1)

        return result
