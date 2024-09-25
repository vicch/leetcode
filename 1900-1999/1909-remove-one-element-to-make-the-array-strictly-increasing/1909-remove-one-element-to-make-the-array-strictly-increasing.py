"""
The solution is to fix and memorize the first exception of increasing values when iterating the array.

If the exception cannot be fixed, or another exception is met, return false.

The trick is to identify the options: either the current number, or the precedent number should be removed.
"""
class Solution(object):
    def canBeIncreasing(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        removed = False
        n = len(nums)
        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                if removed:
                    return False
                removed = True

                # Check if removing nums[i - 1] can fix it
                if i < 2 or nums[i - 2] < nums[i]:
                    continue
                # Check if removing nums[i] can fix it
                elif i > n - 2 or nums[i - 1] < nums[i + 1]:
                    continue
                # There is no fix
                else:
                    return False
        return True
