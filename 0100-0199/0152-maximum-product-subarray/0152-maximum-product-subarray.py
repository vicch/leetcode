"""
Similar to #53 Maximum Subarray, but with negative numbers in the array, a temporary min product can become a max
product if another negative number shows up.

So instead of keeping only 1 local max value, we need to keep both local max and min.
"""
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        global_max, local_max, local_min = nums[0], nums[0], nums[0]
        for n in nums[1:]:
            """
            Must use joint assignments so that values of local_max and local_min at start of the loop are used, if
            doing it like this:
            
            local_max = max(local_max * n, local_min * n, n)
            local_min = min(local_max * n, local_min * n, n)
            
            Value of local_max in 2nd expression will be wrong.
            """
            local_max, local_min = max(local_max * n, local_min * n, n), min(local_max * n, local_min * n, n)
            global_max = max(global_max, local_max)
        return global_max
