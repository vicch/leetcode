"""
Straightforward solution:

1. Firstly assuming the array is monotonic, verify if it's increasing or decreasing by finding the first unequal pair.
2. Check if the rest of the array fulfills the monotonic requirement.
"""
class Solution(object):
    def isMonotonic(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        i = 0

        # Iterate to either the end, or the first pair that isn't equal.
        while i < len(nums)-1 and nums[i] == nums[i+1]:
            i += 1
        # If the end is reached, then their relation doesn't matter.
        if i == len(nums)-1:
            return True

        # Check if it's increasing or decreasing if it's monotonic.
        increasing = nums[i] < nums[i+1]

        # Iterate to either the end, or the first pair that breaks the monotonic pattern.
        while i < len(nums)-1 and (nums[i] <= nums[i+1] if increasing else nums[i] >= nums[i+1]):
            i += 1

        # If the end is reached, all pairs were following the monotonic pattern.
        return i == len(nums)-1
